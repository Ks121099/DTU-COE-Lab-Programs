#include<iostream>
using namespace std;
int mod(int a){
if (a<0){
return -a;
}
return a;}
int find_min(int *q, int n){
int key=0;
for (int i=0;i<n;i++){
if (q[i] != -1 && q[key] > q[i]){
key = i;
}
}
return q[key];
}
int check_prcss(int p, int h){
if (p == -1){
return 0;
}
else{
if (p >= h)
 return 1;
return 0;
}
}
int forward_movement(int *q, int ch,int n){
int idx =-1;
for(int i=0;i<n;i++){
if(check_prcss(q[i],ch) == 1){
if (idx ==-1 || q[idx] > q[i]){
 idx=i;}
}}
return idx;
}
int CLOOK(int *q, int n, int h){
int head_movement = 0;
int prev_head = h;
int curr_head = h;
int counter = 0;
int idx = -1;
cout<<"Queue of Processes : \n";
while(counter < n){
for(int i=0;i<n;i++){
idx = forward_movement(q,prev_head,n);
 if(idx!= -1){
 cout<<"P"<<idx+1<<"( "<<q[idx]<<" )"<<" ->";
 curr_head = q[idx];
 int diff = mod(prev_head - curr_head);
 head_movement = head_movement + diff;
 prev_head = curr_head;
 q[idx] =-1;
 counter++; } }
int pre = find_min(q,n);
head_movement = head_movement + (prev_head - pre);
prev_head = pre;
}
cout<<"\nTotal head movement = ";
return head_movement;
}
int main(){
int prcss_no;
cout<<"\nEnter number of processes = ";
cin>>prcss_no;
int *queue;
queue=new int[prcss_no];
cout<<"\nEnter the memory requirement for each process :";
for(int i=0;i<prcss_no;i++)
 {
 cout<<"\nProcess No. "<<i+1<<" : ";
 cin>>queue[i];
 }
int head;
cout<<"\nEnter current head location = ";
cin>>head;
cout<<"\nAssuming no. of cylinders varry from 0 to 200 and head works in forward
direction(200).";
cout<<CLOOK(queue,prcss_no,head);
delete queue;
return 0;
}