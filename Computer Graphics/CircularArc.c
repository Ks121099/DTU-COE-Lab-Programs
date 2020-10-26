#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define ROUND(a) ((int)(a+0.5))
void arcdraw(int xc, int yc, int r,float a1,float a2){
int x = ROUND(r*cos(a2));
     int y = ROUND(r*sin(a2));
     int xf = ROUND(r*cos(a1));
     int yf = ROUND(r*sin(a1));
     int p=5/4-r;

     putpixel(xc+x,yc+y,15);

     while(x<=xf && y>=yf)
     {
               if(x<y)
               {
                   x++;
                   if(p<0)
                      p+= 2*x+1;
                   else
                   {
                       y--;
                       p+=2*(x-y)+1;
                   }
                   putpixel(xc+x,yc+y,15);
               }
               else
               {
                   y--;
                   if(p>0)
                      p-= 2*y +1;
                   else
                   {
                       x++;
                       p-=2*(y-x)+1;

                   }
                   putpixel(xc+x,yc+y,15);
               }
     }


}
int main( ){
int x,y,r;
float a1,a2;
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\BGI");
printf("Enter center of circle\n");
scanf("%d %d", &x, &y);
printf("Enter radius \n");
scanf("%d", &r);
printf("Enter the start and end angles with x axis\n");
scanf("%f%f",&a1,&a2);
a1=a1*3.142/180;
a2=a2*3.142/180;
cleardevice();
arcdraw(x,y,r,a1,a2);
getch();
closegraph();
return 0;}
