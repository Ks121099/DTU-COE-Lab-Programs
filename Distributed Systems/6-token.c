#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
void CS(int MY_PORT)
{
 time_t s = time(NULL);
 struct tm *current_time;
 printf("Entering the critical section at: ");
 current_time = localtime(&s);
 printf("%02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min,current_time->tm_sec);
 sleep(5);
 FILE *fp;
 fp = fopen("token_based.txt", "a");
 fprintf(fp, "Written by process %d\n", MY_PORT);
 fprintf(fp,"At time %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min,current_time->tm_sec);
 fclose(fp);
}
int makeconnection(int PORT)
{
 int sockfd;
 struct sockaddr_in servaddr;
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
 {
 perror("socket creation failed");
 exit(EXIT_FAILURE); 
 }
 int optval = 1;
 setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval,sizeof(int));
 memset(&servaddr, 0, sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // loopback address 
 servaddr.sin_port = htons(PORT);
 if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
 {
 perror("bind failed");
 exit(EXIT_FAILURE);
 }
 return sockfd;
}
int main(int argc, char *argv[])
{
 int len, n;
 char buffer[1024];
 int MY_PORT = atoi(argv[1]);
 int NEXT_CLIENT_PORT = atoi(argv[2]);
 int IS_INITIATOR = atoi(argv[3]);
 printf("Initialising the server at port %d ...\n", MY_PORT);
 int sockfd = makeconnection(MY_PORT);
 struct sockaddr_in next_client_addr, prev_client_addr;
 char response[1024];
 memset(&next_client_addr, 0, sizeof(next_client_addr));
 next_client_addr.sin_family = AF_INET;
 next_client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 next_client_addr.sin_port = htons(NEXT_CLIENT_PORT);
 if (IS_INITIATOR)
 {
 CS(MY_PORT);
 strcpy(response, "ACK");
 printf("Printing %s to port %d. \n", response, NEXT_CLIENT_PORT);
 int check = sendto(sockfd, (const char *)response, strlen(response),
MSG_CONFIRM, (const struct sockaddr *)&next_client_addr,sizeof(next_client_addr));
 memset(&prev_client_addr, 0, sizeof(prev_client_addr));
 n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&prev_client_addr, &len);
 buffer[n] = '\0';
 if (!strcmp(buffer, "ACK"))
 {
 strcpy(response, "TERM");
 sendto(sockfd, (const char *)response, strlen(response),
MSG_CONFIRM, (const struct sockaddr *)&next_client_addr,sizeof(next_client_addr));
 time_t s = time(NULL);
 struct tm *current_time;
 printf("Exiting at: ");
 current_time = localtime(&s);
 printf("%02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
 }
 else
 {
 printf("Invalid message received\n");
 }
 exit(0);
 }
 else
 {
 while (1)
 {
 memset(&prev_client_addr, 0, sizeof(prev_client_addr)); 
 printf("Ready to Listen \n");
 n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&prev_client_addr, &len);
 buffer[n] = '\0';
 if (!strcmp(buffer, "ACK"))
 {
 CS(MY_PORT);
printf("Printing %s to port %d. \n", buffer,NEXT_CLIENT_PORT);
 sendto(sockfd, (const char *)buffer, strlen(buffer),MSG_CONFIRM, (const struct sockaddr *)&next_client_addr,sizeof(next_client_addr));
 }
 else if (!strcmp(buffer, "TERM"))
 {
 printf("Printing %s to port %d. \n", buffer,NEXT_CLIENT_PORT);
 sendto(sockfd, (const char *)buffer, strlen(buffer),MSG_CONFIRM, (const struct sockaddr *)&next_client_addr,sizeof(next_client_addr));
 time_t s = time(NULL);
 struct tm *current_time;
 printf("Exiting at: ");
current_time = localtime(&s);
 printf("%02d:%02d:%02d\n", current_time->tm_hour,current_time->tm_min, current_time->tm_sec);
 exit(0);
 }
 else
 {
 printf("Invalid message received\n");
 }
 }
 }
}