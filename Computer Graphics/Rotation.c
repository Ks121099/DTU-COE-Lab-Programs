#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
int main()
{
 int x1, x2, y1, y2,x3,y3;
double r11,r12,r21,r22;
double theta;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter intial point\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter end point\n");
    scanf("%d %d", &x2, &y2);
    line(x1, y1, x2, y2);		
    printf("Enter the rotation angle:\n");
    scanf("%lf",&theta);
    r11=cos((theta*3.1428)/180);
r12=-sin((theta*3.1428)/180);
r21=sin((theta*3.1428)/180);
r22=cos((theta*3.1428)/180);
x3=((x2*r11)+(y2*r12));
y3=((x2*r21)+(y2*r22));
printf("Line after Rotation:\n");
line(x1,y1,x3,y3); 	
    getch();
    closegraph();
return 0;
}