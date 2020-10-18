#include <iostream>
#include <queue>
using namespace std;
class Process
{
public:
int index, arr_t, burst_t, comp_t, wait_t, ta_t, rem_t;
};
Process p[100];
int n;
int main()
{
int i;
queue <Process> q;
cin >> n;
for(i=0; i<n; i++)
{
cin >> p[i].arr_t;
cin >> p[i].burst_t;
p[i].rem_t = p[i].burst_t;
p[i].index = i+1;
}
int quant;
cin>>quant;
 i = 0;
 int pInQue=0;
 int time = p[0].arr_t;
 while(time == p[i].arr_t && i<n)
 {
 q.push(p[i]);
 pInQue++;
 i++;
 }
 Process processToBeScheduled;
 while(!q.empty())
 {
 processToBeScheduled = q.front();
 q.pop();
 int index = processToBeScheduled.index-1;
 int executionTime;
 int remainingTime = p[index].rem_t;
 if(remainingTime >= quant)
 executionTime = quant;
 else
 executionTime = remainingTime;
 p[index].rem_t = remainingTime - executionTime;
 time = time + executionTime;
 int j= pInQue;
 while(j<n && time >= p[j].arr_t)
 {
 q.push(p[j]);
 pInQue++;
 j++;
 }
 if(p[index].rem_t == 0)
 p[index].comp_t = time;
 else
 q.push(p[index]);
 if(q.empty() && pInQue!=n)
 {
 time = p[j].arr_t;
 while(time >= p[j].arr_t && j<n)
 {
 q.push(p[j]);
 pInQue++;
 j++;
 }
 }
 }
 // Calculation of waiting and turn-around time
 int sum_tat = 0, sum_wt = 0;
 float avg_tat, avg_wt;
 for (i = 0; i < n; i++)
 {
 p[i].ta_t = p[i].comp_t - p[i].arr_t;
 p[i].wait_t = p[i].ta_t - p[i].burst_t;
 }
 // Calculation of average waiting and turn-around time
 for (i = 0; i < n; i++)
 {
 sum_tat += p[i].ta_t;
 sum_wt += p[i].wait_t;
 }
 avg_tat = (float)sum_tat / n;
 avg_wt = (float)sum_wt / n;
 // Printing table
 cout<<"\nSNo\tAT\tBT\tCT\tTAT\tWT\n";
 for (i = 0; i < n; i++)
cout<<p[i].index<<"\t"<<p[i].arr_t<<"\t"<<p[i].burst_t<<"\t"<<p[i].comp_t<<"\t"<<p[i].ta_t<<"
\t"<<p[i].wait_t<<"\n";
 cout << "\nAverage turn-around time: " << avg_tat << "\n";
 cout << "Average waiting time: " << avg_wt << "\n";
return 0;
}