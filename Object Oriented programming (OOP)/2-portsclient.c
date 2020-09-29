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
 struct sockaddr_in server_addr;
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
 {
 perror("socket creation failed");
 exit(EXIT_FAILURE);
 }
 else
 {
 printf("\nSocket created");
 }
 memset(&server_addr, 0, sizeof(server_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(PORT);
 server_addr.sin_addr.s_addr = INADDR_ANY;
 if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
 {
 printf("\n Error : Connect Failed \n");
 exit(0);
 }
 else
 {
 printf("\nConnection made before transmissions.");
 }
 printf("What task would you like to perform?\n1) Echo Service\n2) Day Time Service\n3)Time of the day\n4)Character Generation\n");
 int ch;
 scanf("%d", &ch);
 char message[256];
 switch (ch)
 {
 case 1:
 strcpy(message, "Echo this message\0");
 break;
 case 2:
 strcpy(message, "2\0");
 break;
 case 3:
 strcpy(message, "3\0");
 break;
 case 4:
 strcpy(message, "4\0");
 break;
 default:
 printf("Wrong choice");
 exit(0);
 }
 int n, len, max_len = 1024;
 sendto(sockfd, (const char *)message, strlen(message),
 MSG_CONFIRM, (const struct sockaddr *)NULL,
 sizeof(server_addr));
 printf("\nRequest sent.\n");
 n = recvfrom(sockfd, (char *)buffer, max_len,
 MSG_WAITALL, (struct sockaddr *)NULL, NULL);
 buffer[n] = '\0';
 printf("Server response : %s\n", buffer);
 close(sockfd);
 printf("\nClient socket closed.\n");2
 
 return 0;
}