#include<iostream.h>
#include<conio.h> 
void main()
{
clrscr();
int num,lim;
cout<<"Enter a Number For it's Table\n"; 
cin>>num;
cout<<"Enter Till Which Number You Want It to be Printed\n"; 
cin>>lim;
for(int i=1;i<=lim;++i)
	cout<<num<<" x "<<i<<" = "<<num*i<<endl; 
getch();
}