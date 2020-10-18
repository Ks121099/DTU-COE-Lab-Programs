#include <iostream>
#include <queue>
using namespace std;
// Class to encapsulate Process properties
class Process
{
public:
int a_t, b_t, c_t, ta_t, w_t, index;
};
// Function to overaload < operator
bool operator<(const Process &p1, const Process &p2)
{
return p2.b_t < p1.b_t;
}
int main()
{
int n, i, sum_tat = 0, sum_wt = 0;
float avg_tat, avg_wt;
Process p[100];
// Priority Q to get shortest burst time of processes added
priority_queue<Process> q;
cin >> n;
for (i = 0; i < n; i++)
{
cin >> p[i].a_t;
cin >> p[i].b_t;
p[i].index = i + 1;
}
int time = p[0].a_t, temp = 0;
for (i = 0; i < n; i++)
{
if (p[i].a_t <= time)
{
q.push(p[i]);
temp = i;
}
}
// Calculation of completion time for processes
while (!q.empty())
{
Process proc = q.top();
cout << "Executing process number: " << proc.index << "\n";
p[proc.index - 1].c_t = time + proc.b_t;
time = time + proc.b_t;
q.pop();
for (i = temp + 1; i < n; i++)
{
if (p[i].a_t <= time)
{
q.push(p[i]);
temp = i;
}}}
// Calculation of waiting and turn-around time
for (i = 0; i < n; i++)
{
p[i].ta_t = p[i].c_t - p[i].a_t;
p[i].w_t = p[i].ta_t - p[i].b_t;
}
// Calculation of average waiting and turn-around time
for (i = 0; i < n; i++)
{
sum_tat += p[i].ta_t;
sum_wt += p[i].w_t;
}
avg_tat = (float)sum_tat / n;
avg_wt = (float)sum_wt / n;
// Printing table
cout<<"\nSNo\tAT\tBT\tCT\tTAT\tWT\n";
for (i = 0; i < n; i++)
cout<<p[i].index<<"\t"<<p[i].a_t<<"\t"<<
p[i].b_t<<"\t"<<p[i].c_t<<"\t"<<p[i].ta_t<<"\t"<<p[i].w_t<<"\n";
cout << "Average turn-around time: " << avg_tat << "\n";
cout << "Average waiting time: " << avg_wt << "\n";
return 0;
}