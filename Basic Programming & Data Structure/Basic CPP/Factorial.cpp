#include<iostream.h>
#include<conio.h> 
void main()
{
clrscr();
unsigned long num , fact=1;
cout<<"ENTER THE NUMBER FOR IT'S FACTORIAL\n";
cin>>num;
for(int i=num;i>=1;--i) 
	fact*=i;
cout<<"FACTORIAL = "<<fact<<endl; 
getch();
}