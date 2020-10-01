#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
void error(const char *msg) 
{
 perror(msg);
 exit(1);
}
char buffer[256];
int n;
int l_clock = 0, tot = 0, avg = 0, cnt = 0, t = 0;
void Berkeley(long newsockfd)
{
 bzero(buffer, 256);
 stringstream ss, ss1, ss2;
 ss << l_clock;
 string tmpstr1 = ss.str();
 strcpy(buffer, tmpstr1.c_str());
 n = write((long)newsockfd, buffer, strlen(buffer));
 if (n < 0)
 error("ERROR writing to socket");
 bzero(buffer, 256);
 read((long)newsockfd, buffer, 255);
 cout << "Time Difference of Machine '" << newsockfd << "' : " << buffer << endl;
 ss1 << buffer;
 bzero(buffer, 256);
 cout << "buffer:" << buffer << endl;
 string tmpstr2 = ss1.str();
 cout << "tmpstr2:" << tmpstr2 << endl;
 int diff = atoi(tmpstr2.c_str());
 cout << "diff:" << diff << endl;
 tot = tot + diff;
 sleep(2);
 avg = tot / (cnt + 1);
 cout << "avg:" << avg << endl;
 int adj_clock = avg - diff;
 cout << "adj_clock:" << adj_clock << endl;
 bzero(buffer, 256);
 ss2 << adj_clock;
 string tmpstr3 = ss2.str();
 strcpy(buffer, tmpstr3.c_str()); 
 n = write((long)newsockfd, buffer, strlen(buffer));
 if (n < 0)
 error("ERROR writing to socket");
}
void *NewConnection(void *newsockfd)
{
 if ((long)newsockfd < 0)
 error("ERROR on accept");
 cout << "Connected to Machine Number: " << (long)newsockfd << endl;
 cnt++;
 while (cnt != t)
 {
 continue;
 }
 Berkeley((long)newsockfd);
 close((long)newsockfd);
 pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
 long sockfd, newsockfd[10], portno;
 socklen_t clilen;
 struct sockaddr_in serv_addr, cli_addr;
 pthread_t threads[10];
 srand(time(0));
 l_clock = (rand() % 10) + 5; //genrate a random number to be taken as the clock time
 // instead of actually using the time
 if (argc < 2)
 {
 fprintf(stderr, "ERROR, no port provided\n");
 exit(1);
 }
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if (sockfd < 0)
 error("ERROR opening socket");
 bzero((char *)&serv_addr, sizeof(serv_addr));
 portno = atoi(argv[1]);
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = INADDR_ANY;
 serv_addr.sin_port = htons(portno);
 int reuse = 1;
 if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuse,
sizeof(reuse)) < 0) //To reuse socket address in case of crashes and failures
 perror("setsockopt(SO_REUSEADDR) failed");
#ifdef SO_REUSEPORT
 if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (const char *)&reuse,
sizeof(reuse)) < 0)
 perror("setsockopt(SO_REUSEPORT) failed");
#endif
 if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
 error("ERROR on binding");
 listen(sockfd, 10);
 clilen = sizeof(cli_addr);
 cout << "Enter the total number of machines to connect: ";
 cin >> t;
 cout << "Time Daemon's Logical Clock: " << l_clock << endl;
 int sock_index = 0;
 for (int i = 0; i < t; i++)
 {
 newsockfd[sock_index] = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
 pthread_create(&threads[i], NULL, NewConnection, (void *)newsockfd[sock_index]);
 sock_index = (sock_index + 1) % 100;
 }
 for (int i = 0; i < t; i++)
 {
 int rc = pthread_join(threads[i], NULL);
 if (rc)
 {
 printf("Error in joining thread :\n");
 cout << "Error: " << rc << endl;
 exit(-1);
 }
 }
 cout << "Clock adjustment: " << avg << endl;
 l_clock = l_clock + avg;
 cout << "My Adjusted clock: " << l_clock << endl;
 close(sockfd);
 pthread_exit(NULL);
 return 0;
}