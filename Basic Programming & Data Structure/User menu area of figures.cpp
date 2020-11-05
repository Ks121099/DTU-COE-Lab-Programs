#include<iostream.h>
#include<conio.h> 
void main()
{
clrscr(); 
int ch;
double rad,base,height,length,breadth,area;
    cout<<"ENTER YOUR CHOICE FOR FINDING AREA OF:\n"
	<<"1)CIRCLE\n"
	<<"2)RECTANGLE\n"
	<<"3)SQUARE\n"
	<<"4)TRIANGLE\n";
cin>>ch;
switch(ch)
{
case 1: cout<<"ENTER RADIUS OF CIRCLE:\n"; 
	cin>>rad;
	area=(22*rad*rad)/7;
	cout<<"AREA OF CIRCLE= "<<area;
	break;
case 2: cout<<"ENTER LENGTH AND BREADTH OF RECTANGLE:\n";
	cin>>length>>breadth;
	area=length*breadth;
	cout<<"AREA OF THE RECTANGLE= "<<area;
	break;
case 3: cout<<"ENTER SIDE OF SQUARE:\n";
	cin>>length;	
	area=length*length;
	cout<<"AREA OF SQUARE= "<<area;
	break;
case 4: cout<<"ENTER HEIGHT AND BASE OF TRIANGLE:\n";
	cin>>height>>base;
	area=(base*height)/2;
	cout<<"AREA OF TRIANLGE= "<<area;
	break;
default: cout<<"YOU ENTERED A WRONG CHOICE.....\n";
}
getch();
}