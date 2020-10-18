#include <iostream>
using namespace std;
struct Process
{
int pid;
int bt;
int priority;
};
void waitingTime(Process p[],int n,intwt[])
{
wt[0] = 0;
for(int i = 1; i< n; i++)
{
wt[i] = p[i-1].bt + wt[i-1];
}
}
void turnAroundTime(Process p[],int n,intwt[],int tat[])
{
for(int i = 0; i< n; i++)
{
tat[i] = p[i].bt + wt[i];
}
}
void avgTime(Process p[],int n)
{
int wt[20],tat[20],total_wt = 0,total_tat = 0;
waitingTime(p,n,wt);
turnAroundTime(p,n,wt,tat);
cout<<"\nProcesses Burst Time Waiting Time Turn Around Time\n";
for(int i = 0; i< n; i++)
{
total_wt += wt[i];
total_tat += tat[i];
cout<<p[i].pid<<" "<<p[i].bt<<" "<<wt[i]<<" "<<tat[i]<<endl;
}
cout<<"Average waiting time = "<<total_wt/(float)(n)<<endl;
cout<<"Average turn around time = "<<total_tat/(float)(n)<<endl;
}
void priorityScheduling(Process p[],int n)
{
for(int i = 0; i< n; i++)
{
for(int j = 0; j < n-1; j++)
{
if(p[j].priority> p[j+1].priority)
{
Process temp = p[j];
p[j] = p[j+1];
p[j+1] = temp;
}
}
}
cout<<"Order of execution : \n";
for(int i = 0; i< n; i++)
{
cout<<p[i].pid<<" ";
}
cout<<endl;
avgTime(p,n);
}
int main()
{
Process p[20];
int n;
cout<<"Enter the no. of processes : ";
cin>>n;
for(int i = 0; i< n; i++)
{
p[i].pid = i+1;
cout<<"Enter the burst time and priority pf process "<<i+1<<": ";
cin>>p[i].bt>>p[i].priority;
}
priorityScheduling(p,n);
return 0;
}