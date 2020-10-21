#include <iostream>
using namespace std;
int main ()
{
 int a,b;
 cout<<"Enter two no's to be divided \n";
 cin>>a>>b;
 try
 {
 if(b == 0)
 {
 throw -1;
 }
 cout<<a/b;
 }
 catch(int n)
 {
 cerr<<"Division by zero exception \n";
 }
 int n;
 cout<<"Enter size of array : ";
 cin>>n;
 int *arr = new int [n];
 cout<<"Try to Enter "<<n + 2<<" elements";
 for(int i = 0;i < n + 2; i++) {
 try
 {
 if(i >= n)
{
 throw -1;
 }
 cin>>arr[i];
 }
 catch(int n)
 {
 cerr<<"Index out of bounds exception ";
 }
 }
}