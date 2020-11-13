#include<iostream.h>
#include<conio.h> 
void main()
{
clrscr();
unsigned long a=0,b=1,c,d; 
cout<<"HOW MANY ELEMENTS(>5)?\n";
cin>>d;
cout<<"FIBONACCI SERIES :\n" <<a<<" "<<b;
for(int i=2;i<d;++i)
{
c=a+b;
cout<<" "<<c;
a=b;
b=c;
}
getch();
}