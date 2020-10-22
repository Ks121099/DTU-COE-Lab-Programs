#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
typedef struct resources
{
 int A; char B; int C; char D;
}resources;
int main()
{
 struct sockaddr_in sa; // Socket address data structure
 resources R;
 int n, sockfd; // read and source
 char buff[1025], obuff[256]; // buffer to store the read stream
 int snded, rec;
 sockfd = socket(PF_INET, SOCK_STREAM, 0); // New socket created
 // Checking for valid socket
 if (sockfd < 0)
 {
 printf("Error in creation\n"); exit(0);
 }
 else
 printf("Socket created\n");
 // Clearing and assigning type and address to the socket
 bzero(&sa, sizeof(sa));
 sa.sin_family = AF_INET;
 sa.sin_port = htons(8888);
 // establishing and verifying the connection
 if (connect(sockfd, (const struct sockaddr*)&sa, sizeof(sa)) < 0)
 {
 printf("Connection failed\n");
 exit(0);
 }
 else
 printf("Connection made\n");
 while (1)
 {
 snded = write(sockfd, "PING", 5);
 if (snded > -1)
 printf("SENT PING\n");
 rec = read(sockfd, obuff, 256);
 obuff[rec] = '\0';
 if (strcmp(obuff, "BINGO") == 0)
 {
 usleep(750); FILE *f;
 f = fopen("shared_mem.txt", "r");
 fread(&R, sizeof(R), 1, f);
 fclose(f);
 printf("Read %d, %d, %d, %d from server\n", R.A, R.B, R.C, R.D );
 R.A += 1;
 R.B += 1;
 R.C += 1;
 R.D += 1;
 f = fopen("shared_mem.txt", "w");
 fwrite(&R, sizeof(R), 1, f);
 fclose(f);
 printf("Got access to CS\n");
 snded = write(sockfd, "DONE", 4);
 printf("Freeing Lock\n");
 break;
 }
 }
 close(sockfd);
 return 0;
}
/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter No. of Processes : ";
    cin >> n;
    cout << "Enter Coodinator id    : ";
    int coordinator;
    cin >> coordinator;
    cout << "Enter Resource id      : ";
    char resource;
    cin >> resource;
    int nrl;
    cout << "Enter No. of Requests  : ";
    cin >> nrl;
    cout << "Enter Request List     : ";
    int reqlist[nrl];
    for (int i = 0; i < nrl; i++)
        cin >> reqlist[i];
    cout << "\n";
    cout << "Processes : ";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << " ";
    cout << "\n";
    cout << "Coordinator : Process P" << coordinator << "\n";
    cout << "Resource : R-" << resource << "\n";
    cout << "Request List : ";
    for (int i = 0; i < nrl; i++)
        cout << "P" << reqlist[i] << " ";
    int time = 0;
    vector<int> queue;
    int res_status = 0;
    cout << "\n\n";

    //Blocking Phase
    for (int i = 0; i < nrl; i++) {
        if (res_status == 0) {
            cout << "P" << reqlist[i] << " REQUEST for Resource R-" << resource << "\n";
            cout << "Resource R-" << resource << " is available\n";
            cout << "Coordinator P" << coordinator << " GRANTS R-" << resource << " to P" << reqlist[i] << "\n\n";
            res_status = reqlist[i];
        } else {
            cout << "P" << reqlist[i] << " REQUEST for Resource R-" << resource << "\n";
            cout << "Resource R-" << resource << " is not available\n";
            cout << "Coordinator P" << coordinator << " BLOCKS P" << reqlist[i] << " and adds it to queue\n";
            queue.push_back(reqlist[i]);
            cout << "Queue : ";
            for (int j = 0; j < queue.size(); j++)
                cout << "P" << queue[j] << " ";
            cout << "\n\n";
        }
    }

    //Releasing Phase
    while (!queue.empty()) {
        cout << "P" << res_status << " RELEASES Resource R-" << resource << "\n";
        res_status = queue[0];
        cout << "Coordinator P" << coordinator << " UNBLOCKS P" << res_status << " and GRANTS R-" << resource << "\n";
        queue.erase(queue.begin());
        cout << "Queue : ";
        for (int j = 0; j < queue.size(); j++)
            cout << "P" << queue[j] << " ";
        cout << "\n\n";
    }
    cout << "Request Finished";
    cout << "\n";
    return 0;
}*/