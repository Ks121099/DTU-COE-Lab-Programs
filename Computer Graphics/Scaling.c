#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
int main()
{
 int x1, x2, y1, y2,x3,y3;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter intial point\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter end point\n");
    scanf("%d %d", &x2, &y2);
    line(x1, y1, x2, y2);		
    printf("Enter the Scaling factors:\n");
    scanf("%d%d",&x3,&y3);
  
x1=x1*x3;
y1=y1*y3;
x2=x2*x3;
y2=y2*y3;
printf("Line after Scaling:\n");
line(x1,y1,x2,y2); 	
    getch();
    closegraph();
return 0;
}