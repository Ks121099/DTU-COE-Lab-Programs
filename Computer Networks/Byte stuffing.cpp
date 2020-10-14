#include<iostream>
using namespace std;
int main()
{
int i,j,k,data[100],n;
cout<<"Enter the no. of bits: "<<endl;
cin>>n;
cout<<"Enter the bits to be transmitted: "<<endl;
for(i=0;i<n;i++)
{
cin>>data[i];
}
cout<<endl;
cout<<"The bits entered are: "<<endl;
for(i=0;i<n;i++)
{
cout<<data[i];
}
cout<<endl;
cout<<"The byte stuffed array is: "<<endl;
cout<<"01111110 ";
for(i=0;i<n;i++)
{
if(data[i]==0 && data[i+1]==1 && data[i+2]==1 && data[i+3]==1 && data[i+4]==1 &&
data[i+5]
&& data[i+6]==1 && data[i+7]==0)
{
cout<<"0111111001111110";
i=i+7;
}
else cout<<data[i];
}
cout<<" 01111110"<<endl;
return 0;
}
