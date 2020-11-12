#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct rr
{
 int index;
 int id;
 int f;
 char state[10];
}proc[10];
int i, j, k, m, n;
int main()
{
 int temp;
 char str[10];
 cout<<"enter the number of process: ";
 cin>>n;
 for(i=0;i<n;i++)
 {
 cout<<"enter id of process: ";
 cin>>proc[i].id;
 strcpy(proc[i].state,"active");
 proc[i].f=0;
 }
 for(j=0;j<n-1;j++)
 {
 if(proc[j].id>proc[j+1].id)
 {
 temp=proc[j].id;
 proc[j].id=proc[j+1].id;
 proc[j+1].id=temp;
 }
 }
 for(i=0;i<n;i++)
 printf("[%d] %d\t",i,proc[i].id);
 int init, ch, temp1, temp2;
 int arr[10];
 strcpy(proc[n-1].state,"inactive");
 cout<<"\nprocess "<<proc[n-1].id<<" select as coordinator";
 while(1)
 {
 cout<<"\n1)election 2)quit\n";
 scanf("%d",&ch);
 for(i=0;i<n;i++)
 proc[i].f=0;
 switch(ch)
 {
 case 1:
 cout<<"\nenter the process Number who intialised election";
 scanf("%d",&init);
 temp2=init;
 temp1=init+1;
 i=0;
 while(temp2!=temp1)
 {
 if(strcmp(proc[temp1].state,"active")==0 && proc[temp1].f==0 )
 {
 cout<<"process "<<proc[init].id<<" send message to"<<proc[temp1].id<<"\n";
 proc[temp1].f=1;
 init=temp1;
 arr[i]=proc[temp1].id; i++;
 }
 if(temp1==n)
 temp1=0;
 else
 temp1++;
 }
 cout<<"process "<<proc[init].id<<" send message to "<<proc[temp1].id<<"\n";
 arr[i]=proc[temp1].id;
 i++;
 int max=-1;
 for(j=0;j<i;j++)
 {
 if(max<arr[j])
 max=arr[j];
 }
 cout<<"\nprocess "<<max<<" select as coordinator\n";
 for(i=0;i<n;i++)
 {
 if(proc[i].id==max)
 strcpy(proc[i].state,"inactive");
 }
 break;
 }
 break;
 }
 return 0;
}