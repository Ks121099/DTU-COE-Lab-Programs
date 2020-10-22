#include<iostream>
using namespace std;
inline float add(float a, float b)
 {
return a+b;
 }
inline float subrtract(float a, float b)
 {
if(a>b)
 return a-b;
else
return b-a;
 }
inline float multi(float a, float b)
 {
return a*b;
 }
inline float divide(float a, float b)
 {
if(b!=0)
 return a/b;
else
cout<<"\nInvalid statement\n";
 }
int main()
{
 float y,z;
 int x;
 char g;
 do
{
cout<<"Enter two number on which operation is to performed\n";
cin>>y>>z;
cout<<"Select the operation:\n 1) Addition\n 2)Subtraction\n 3)Multiplication\n
4)Division\n";
cout<<"\nEnter the operation you want to per form: ";
cin>>x;
 switch(x)
{
 case 1: cout<<"Result of operation "<<add(y,z);
 break;
 case 2: cout<<"Result of operation "<<subrtract(y,z);
 break;
 case 3: cout<<"Result of operation "<<multi(y,z);
 break;
 case 4: cout<<"Result of operation "<<divide(y,z);
 break;
 default: cout<<"Wrong choice";
}
cout<<"\n Want to perform other operation(Y/N)";
cin>>g;
}while(g=='Y'||g=='y');
 return 0;
}