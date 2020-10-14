#include<iostream>
using namespace std;
int main()
{
int a[50];
int i, j, k, n, c, pos;
c = 0;
pos = 0;
cout<<"Enter number of bits:\n";
cin>>n;
cout<<"Enter the bits:\n";
for(i = 0; i < n; i++)
cin>>a[i];
for(i = 0; i < n; i++)
{
if(a[i] == 1)
{
c++;
if(c == 5)
{
pos = i+1;
c = 0;
for(j = n-1; j > pos; j--)
{
k = j+1;
a[k] = a[j];
}
a[pos] = 0;
n++;
}
}
else
c = 0;
}
cout<<"Data after stuffing:\n";
cout<<"01111110";
for(i = 0; i < n; i++)
{
cout<<a[i];
}
cout<<"01111110"<<endl;
return 0;
}
