#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main()
{
 int sockfd;
 char buffer[1024];
 char const *request = "Request from client";
 struct sockaddr_in server_addr;
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
{
 perror("socket creation failed");
 exit(EXIT_FAILURE);
 }
 memset(&server_addr, 0, sizeof(server_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(PORT);
 server_addr.sin_addr.s_addr = INADDR_ANY;
 int n, len, max_len = 1024;
 int ch=1;
 while (ch == 1)
 {
 sendto(sockfd, (const char *)request, strlen(request),
 MSG_CONFIRM, (const struct sockaddr *)&server_addr,sizeof(server_addr));
 printf("Request sent.\n");
 n = recvfrom(sockfd, (char *)buffer, max_len,
 MSG_WAITALL, (struct sockaddr *)&server_addr,
 &len);
 buffer[n] = '\0';
 printf("Server : %s\n", buffer);
 printf("Want to send another request? (Yes(1)/No(0))");
 scanf("%d", &ch);
 }
 close(sockfd);
 printf("\nClient socket closed.\n");
 return 0;
}