#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
long i,n,x,sum=1;
cout<<"1+x+x^2+...+x^n";
cout<<"\nEnter the value of x and n:"; 
cin>>x>>n;
for(i=1;i<=n;++i)
	sum+=pow(x,i);
cout<<"\nSum="<<sum;
getch();
}