#include<iostream.h>
#include<conio.h> 
void main()
{
clrscr();
int num,max=0,min=0;
cout<<"Enter The Numbers...\n"; 
do{
cin>>num;
if(num>max)
max=num;
else
min=num;
}while(num!=0);
cout<<"Largest Number= "<<max<<endl;
cout<<"Smallest Number= "<<min<<endl; 
getch();
}