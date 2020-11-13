#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{
clrscr();
int a,b,c,e=1;
char g,f;
lb:
cout<<"ENTER YOUR CHOICE:\n"
	<<"1) Pattern 1\n"
	<<"2) Pattern 2\n" 
	<<"3) Pattern 3\n"
	<<"4) Pattern 4\n" 
	<<"5) Exit\n";
cin>>a;
switch(a)
{
case 1: for(b=1;b<=6;++b)
	{
	cout<<"\n";
	for(c=1;c<=b;++c)
		cout<<"A";
	}
	break;
case 2: for(char i=65;i<=70;i++)
	{
	cout<<"\n";
	for(char j=65;j<=i;j++) 
		cout<<j;
	}
	break;
case 3: for(b=1;b<=6;++b)
	{
	cout<<"\n";
	for(c=1;c<=b;++c)
		cout<<"1";
	}
	break;
case 4: for(b=0;b<=6;++b)
	{
	cout<<"\n";
	for(c=0;c<=b;++c)
	cout<<e+c;
	}
	break;
case 5: exit(0);
default: cout<<"YOU ENTERED A WRONG CHOICE........\n"; 
	break;
}
cout<<"\nDO YOU WANT TO CONTINUE(y/n)????\n";
cin>>g;
if(g=='y'|| g=='Y')
	goto lb;
if(g=='n'|| g=='N')
	exit(0);
getch();
}