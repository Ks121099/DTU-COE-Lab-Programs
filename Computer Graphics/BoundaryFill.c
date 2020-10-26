#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>

void boufill(int x,int y,int f,int b)
{
 if((getpixel(x,y)!=b)&& (getpixel(x,y)!=f))
 {
   putpixel(x,y,f);
   boufill(x+1,y,f,b);
   boufill(x-1,y,f,b);
   boufill(x,y+1,f,b);
   boufill(x,y-1,f,b);
 }
}
int main( )
{
    int x,y,r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\BGI");
    printf("Enter center of circle\n");
    scanf("%d %d", &x, &y);
    printf("Enter radius \n");
    scanf("%d", &r);
    circle(x,y,r);
    printf("Press key to fill colour\n");
    boufill(x,y,15,WHITE);
     getch();
    closegraph();
    return 0;
}
