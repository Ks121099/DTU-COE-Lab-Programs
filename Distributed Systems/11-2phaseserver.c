#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define ML 1024
#define MPROC 32
typedef struct wireless_node
{
 int priority;
 int parent;
}wireless_node;
wireless_node w;
int max(int a, int b)
{
 return a >= b? a:b;
}
int connect_to_port(int connect_to)
{
 int sock_id;
 int opt = 1;
 struct sockaddr_in server;
 if ((sock_id = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
 {
 perror("unable to create a socket");
 exit(EXIT_FAILURE);
 }
 setsockopt(sock_id, SOL_SOCKET, SO_REUSEADDR, (const void*)&opt, sizeof(int));
 memset(&server, 0, sizeof(server));
 server.sin_family = AF_INET;
 server.sin_addr.s_addr = INADDR_ANY;
 server.sin_port = htons(connect_to);
 if (bind(sock_id, (const struct sockaddr *)&server,sizeof(server)) < 0)
 {
 perror("unable to bind to port");
 exit(EXIT_FAILURE);
 }
 return sock_id;
}
void send_to_id(int to, int from, char message[ML])
{
 struct sockaddr_in cl;
 memset(&cl, 0, sizeof(cl));
 cl.sin_family = AF_INET;
 cl.sin_addr.s_addr = INADDR_ANY;
 cl.sin_port = htons(to);
 sendto(from, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&cl, sizeof(cl));
}
void begin_commit(int id, int *procs, int num_procs)
{
 int itr;
 char message[ML];
 sprintf(message, "%s", "SCMT");
 for (itr = 0; itr < num_procs; itr++)
 {
 printf("Sending begin commit to: %d\n", procs[itr]);
 send_to_id(procs[itr], id, message);
 }
}
void announce_action(int self, int *procs, int num_procs, char msg[ML])
{
 int itr;
 for (itr = 0; itr < num_procs; itr++)
 send_to_id(procs[itr], self, msg);
}
int main(int argc, char* argv[])
{
 int self = atoi(argv[1]), n_procs = atoi(argv[2]), procs[MPROC];
 int sender, okcnt = 0, nocnt = 0, dncnt = 0;
 int sock_id, coord_id, itr, len, n, start, ix;
 char buffer[ML], flag[ML], p_id[ML], msg[256];
 struct sockaddr_in from;
 for(itr = 0; itr < n_procs; itr += 1)
 procs[itr] = atoi(argv[3 + itr]);
 printf("Creating node at %d\n", self);
 sock_id = connect_to_port(self);
 begin_commit(sock_id, procs, n_procs);
 while(TRUE)
 {
 sleep(2);
 memset(&from, 0, sizeof(from));
 n = recvfrom(sock_id, (char *)buffer, ML, MSG_WAITALL, (struct sockaddr *)&from, &len);
 buffer[n] = '\0';
 printf("Recieved: %s\n", buffer);
 if (strcmp(buffer, "CMOK") == 0)
 okcnt += 1;
 else if (strcmp(buffer, "CMNO") == 0)
 nocnt += 1;
 if ((nocnt + okcnt) == n_procs)
 {
 printf("Recieved replies from all clients\n");
 if (okcnt == n_procs)
 {
 printf("Announcing complete commit\n");
 announce_action(sock_id, procs, n_procs, "CDON");
 }
 else
 {
 printf("Announcing abort commit\n");
 announce_action(sock_id, procs, n_procs, "CABT");
 }
 }
 if (strcmp(buffer, "DONE") == 0)
 {
 dncnt += 1;
 printf("clients confirmed commit\n");
 if (dncnt == n_procs)
 {
 printf("All process announced commit action\n");
 exit(EXIT_SUCCESS);
 }
 }
 }
 return 0;
}