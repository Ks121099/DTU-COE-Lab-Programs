#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

int main()
{
 int x1, x2, y1, y2,choice;
int y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter intial point\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter end point\n");
    scanf("%d %d", &x2, &y2);
    line(x1, y1, x2, y2);
printf("Enter the value about which line is to be reflected:\n");
scanf("%d",&y);
printf("Reflection about x axis\n");
printf("Reflection about y axis\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice){

case 1:{
	line(0,y,400,y);
        line(x1,2*y-y1,x2,2*y-y2);
	break;
       }
case 2:{
	line(y,0,y,400);
  	line(2*y-x1,y1,2*y-x2,y2);
	break;
       }

}		 	
    getch();
    closegraph();
return 0;
}