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
 int sockfd, connfd, len;
 struct sockaddr_in server_addr, client_addr;
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
 memset(&client_addr, 0, sizeof(client_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_addr.s_addr = INADDR_ANY;
 server_addr.sin_port = htons(PORT);
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
 while (1)
 {
 char response[256], buffer[1024], client_req[256];
 int n;
 strcpy(response, "");
 strcpy(client_req, "");
 int cli_len = sizeof(client_addr);
 n = recvfrom(sockfd, client_req, sizeof(client_req), 0, (struct sockaddr *)&client_addr,
&cli_len);
 client_req[n] = '\0';
 printf("%s\n", client_req);
 if (client_req[0] == '2')
 {
 time_t ticks;
 ticks = time(NULL);
 snprintf(response, sizeof(response), "%24s", ctime(&ticks));
 }
 else if (client_req[0] == '3')
 {
 time_t now;
 struct tm *now_tm;
 int hour;
 int mints, secs;
 now = time(NULL);
 now_tm = localtime(&now);
 hour = now_tm->tm_hour;
 mints = now_tm->tm_min;
 secs = now_tm->tm_sec;
 snprintf(response, sizeof(response), "Time: %02d:%02d:%02d", hour, mints, secs);
 }
 else if (client_req[0] == '4')
 {
 srand(time(0));
 snprintf(response, sizeof(response), "%c", (char)(rand() % 128));
 }
 else
 {
 snprintf(response, sizeof(response), "%s", client_req);
 sendto(sockfd, response, sizeof(response), 0, (struct sockaddr *)&client_addr,
sizeof(client_addr));
 }
 sendto(sockfd, response, sizeof(response), 0, (struct sockaddr *)&client_addr,
sizeof(client_addr));
 }
 close(sockfd);
 return 0;
}