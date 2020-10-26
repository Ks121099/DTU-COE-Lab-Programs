#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a+0.5))

void arcellipse(int xc, int yc, int Rx, int Ry,float a1,float a2)
 {
  int Rx2= Rx*Rx;
  int Ry2=Ry*Ry;
  int twoRx2= 2*Rx2;
  int twoRy2= 2*Ry2;
  int p;
  int x=ROUND(Rx*cos(a2));
  int y=ROUND(Ry*sin(a2));
  int xf=ROUND(Rx*cos(a1));
  int yf=ROUND(Ry*sin(a1));
  int px= twoRy2*x;
  int py= twoRx2*y;

  putpixel(xc+x,yc+y,15);
  p=ROUND(Ry2-(Rx2*Ry)+(0.25*Rx2));
  while(px<py)
  {
    x++;
    px+=twoRy2;
    if(p<0)
           p+= Ry2+px;
    else
    {
           y--;
           py-=twoRx2;
           p+=Ry2-py+px;
     }
   putpixel(xc+x,yc+y,WHITE);
   }
   p= ROUND(Ry2*(x+0.5)*(x+0.5)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
  while(y>yf)
  {
   y--;
   py-=twoRx2;
   if(p>0)
          p+=Rx2-py;
   else
   {
          x++;
          px+=twoRy2;
          p+=Rx2-py+px;
   }
   putpixel(xc+x,yc+y,WHITE);
   }
}

int main()
{
  int xc,yc, Rx, Ry;
  float a1,a2;
  int gdriver = DETECT, gmode, errorcode;
  printf("Enter center of ellipse\n");
  scanf("%d %d", &xc, &yc);
  printf("Enter the x-radius and y-radius\n");
  scanf("%d %d",&Rx,&Ry);
  printf("Enter the start and end angles with x-axis\n");
  scanf("%f %f",&a1,&a2);
  a1=a1*3.142/180;
  a2=a2*3.142/180;
  arcellipse(xc,yc,Rx,Ry,a1,a2);
  getch();
  closegraph();
  return 0;
}

