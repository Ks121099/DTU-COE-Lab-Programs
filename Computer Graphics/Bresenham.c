#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
void bresenhamline(int x1, int y1, int x2, int y2)
{

    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int twody=2*dy;
    int twodydx=2*(dy-dx);
    int p=twody-dx;
    int x,y;
    int end;
    if(x1<x2)
    {
            x=x1;
            y=y1;
            end=x2;
             }
    else if(x2>x1)
    {
     x=x2;
     y=y2;
     end=x1;
    }
    putpixel(x,y,WHITE);

    while(x<end)
    {
               if(p<0)
               {
                 x++;
                 p+=twody;

               }
               else{
                  x++;
                  y++;
                  p+=twodydx;

                    }

         putpixel(x,y,WHITE);
         delay(50);
    }
}

int main( )
{
    int x1, x2, y1, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\TURBOC3\BGI");
    printf("Enter intial point\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter end point\n");
    scanf("%d %d", &x2, &y2);
    clrscr();
    bresenhamline(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
