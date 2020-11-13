#include<iostream.h>
#include<conio.h>
#include<math.h> 
void main()
{
clrscr();
int n,m=0,x,y;
cout<<"Enter any three digit number:\n"; 
cin>>n;
y=n;
while(n!=0)
{
x=n%10;
m+=pow(x,3);
n=n/10;
}
if(y==m)
cout<<"The number is an Armstrong number\n"; 
else
cout<<"The number is not an Armstrong number\n"; 
getch();
}