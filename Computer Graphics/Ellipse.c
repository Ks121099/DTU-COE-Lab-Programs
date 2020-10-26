#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#define ROUND(a)((int)(a+0.5))
void plotellipse(int xc,int yc,int x,int y)
{

  putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc-y,WHITE);

}
void ellipsedraw(int xc, int yc, int rx,int ry)
{
    int rx2 = rx*rx, ry2 = ry*ry;
    int tworx2 = 2*rx2, twory2=2*ry2;
    int x=0, y=ry;
    int p= ROUND(ry2 + 0.25*rx2 - rx2*ry);
    int px= 0;
    int py = tworx2*ry;

    plotellipse(xc,yc,x,y);
    //REGION 1
    while(px < py)
    {
          x++;
          px += twory2;
          if(p<0)
          p+= px + ry2;
          else
          {
              y--;
              py -= tworx2;
              p+= px+ry2-py;
          }
          plotellipse(xc,yc,x,y);
    }
//REGION 2
    p = ROUND(ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2);
    while (y>0)
    {
          y--;
          py -= tworx2;
          if(p>0)
          {
              p+= rx2-py;
          }
          else
          {
              x++;
              px+=twory2;
              p+=px-py+rx2;
          }
          plotellipse(xc,yc,x,y);
    }
}


int main( )
{
    int x,y,rx,ry;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\BGI");
    printf("Enter center of ellipse\n");
    scanf("%d %d", &x, &y);
    printf("Enter radius  rx\n");
    scanf("%d", &rx);
    printf("Enter radius  ry\n");
    scanf("%d", &ry);
    clrscr();
    ellipsedraw(x,y,rx,ry);
    getch();
    closegraph();
    return 0;
}
