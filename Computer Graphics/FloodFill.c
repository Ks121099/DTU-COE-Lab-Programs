#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>

void flood(int x,int y,int f,int old)
{
 if(getpixel(x,y)==old)
 {
   putpixel(x,y,f);
   flood(x+1,y,f,old);
   flood(x-1,y,f,old);
   flood(x,y+1,f,old);
   flood(x,y-1,f,old);
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
    flood(x,y,15,BLACK);
    getch();
    closegraph();
    return 0;
}
