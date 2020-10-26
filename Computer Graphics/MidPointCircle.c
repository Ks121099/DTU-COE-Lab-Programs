#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
void plotcircle(int xc,int yc,int x,int y)
{

  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  putpixel(xc+y,yc+x,WHITE);
  putpixel(xc-y,yc+x,WHITE);
  putpixel(xc+y,yc-x,WHITE);
  putpixel(xc-y,yc-x,WHITE);
}
void circledraw(int xc, int yc, int r)
{

int x=0;
int y=r;
int p=1-r;

plotcircle(xc,yc,x,y);

while(x<y)
{
 if(p<0)
 {
   x++;
   p+=2*x+1;
 }
 else{
    x++;
    y--;
    p+=2*(x-y)+1;
 }
 plotcircle(xc,yc,x,y);
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
    clrscr();
    circledraw(x,y,r);
    getch();
    closegraph();
    return 0;
}
