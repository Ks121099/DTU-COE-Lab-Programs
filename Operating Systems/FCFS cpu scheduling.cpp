#include <iostream>
using namespace std;
struct Process
{
int a_t, b_t, c_t, ta_t, w_t;
};
int n;
Process p[100];
void print_table()
{
int i;
cout<<"SNo\tAT\tBT\tCT\tTAT\tWT\n";
for (i = 0; i < n; i++)
 {
cout<<i + 1<<"\t"<<p[i].a_t<<"\t"<< p[i].b_t<<"\t"<<p[i].c_t<<"\t"<<p[i].ta_t<<"\t"<<
p[i].w_t<<"\n";
 }
}
int main()
{
int i, sum_tat = 0, sum_wt = 0;
float avg_tat, avg_wt;
cout<< "Enter the number of processes: \n";
cin>> n;
for (i = 0; i < n; i++)
 {
cin>> p[i].a_t;
cin>> p[i].b_t;
 }
p[0].c_t = p[0].a_t + p[0].b_t;
for (i = 1; i < n; i++)
 {
if (p[i].a_t< p[i - 1].c_t)
p[i].c_t = p[i - 1].c_t + p[i].b_t;
else
p[i].c_t = p[i].a_t + p[i].b_t;
 }
for (i = 0; i < n; i++)
 {
p[i].ta_t = p[i].c_t - p[i].a_t;
p[i].w_t = p[i].ta_t - p[i].b_t;
 }
for (i = 0; i < n; i++)
 {
sum_tat += p[i].ta_t;
sum_wt += p[i].w_t;
 }
avg_tat = (float)sum_tat / n;
avg_wt = (float)sum_wt / n;
print_table();
cout<< "Average turn-around time: " <<avg_tat<< "\n";
cout<< "Average waiting time: " <<avg_wt<< "\n";
return 0;
}