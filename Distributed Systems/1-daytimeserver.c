#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
 struct sockaddr_in server_addr, client_addr;
 char time_str[1024];
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
 {
 perror("socket creation failed");
 exit(EXIT_FAILURE);
 }
 memset(&server_addr, 0, sizeof(server_addr));
 memset(&client_addr, 0, sizeof(client_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_addr.s_addr = INADDR_ANY;
 server_addr.sin_port = htons(PORT);
 // Bind the socket with the server address
 if (bind(sockfd, (const struct sockaddr *)&server_addr,
 sizeof(server_addr)) < 0)
 {
 perror("bind failed");
 exit(EXIT_FAILURE);
 }
 else
 {
 printf("\nSocket binded.\n");
 }
while(1){
 time_t t = time(NULL);
 struct tm tm = *localtime(&t);
 snprintf(time_str, sizeof(time_str), "Now: %d-%02d-%02d %02d:%02d:%02d\n",
 tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 int n, len, max_len = 1024;
 len = sizeof(client_addr);
 n = recvfrom(sockfd, (char *)buffer, max_len,
 MSG_WAITALL, (struct sockaddr *)&client_addr,
 &len);
 buffer[n] = '\0';
 printf("Client : %s\n", buffer);
 sendto(sockfd, (const char *)time_str, strlen(time_str),
 MSG_CONFIRM, (const struct sockaddr *)&client_addr,
 len);
 printf("Message sent.\n");
 }
 return 0;
}
