#include<graphics.h>
#include<stdio.h>
#define TOP 0x1
#define BOTTOM 0x2
#define RIGHT 0x4
#define LEFT 0x8
#define ROUND(a) ((int)(a+0.5))

void ddaline(int x1, int y1, int x2, int y2)
{
     float xsteps, ysteps, x=x1, y=y1;
     int dx = x2-x1;
     int dy = y2-y1;
     int steps,k=1;
     if(abs(dx)>=abs(dy))
     steps=abs(dx);
     else steps=abs(dy);
     
     xsteps= dx/(float)steps;              
     ysteps= dy/(float)steps;
     putpixel(ROUND(x),ROUND(y),15);
     while(k<=steps)
     {
           x+=xsteps;
           y+=ysteps;
           putpixel(ROUND(x), ROUND(y),15);
           k++;         
     }
}

int calcode (float x,float y,float xwmin, float ywmin,float xwmax,float ywmax)
{
int code =0;

if(y> ywmax)
code |=TOP;
else if( y<ywmin)
code |= BOTTOM;
else if(x > xwmax)
code |= RIGHT;	
else if ( x< xwmin)
code |= LEFT;

return(code);
}

void lineclip(float x0,float y0,float x1,float y1,float xwmin,float ywmin,float xwmax,float ywmax )
{
unsigned int code0,code1,codeout;
int accept = 0, done=0;

code0 = calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
code1 = calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
do{
if(!(code0 | code1))
{ accept =1 ; done =1; }
else
if(code0 & code1) done = 1;
else
{
float x,y;
codeout = code0 ? code0 : code1;
if(codeout & TOP)
{
x = x0 + (x1-x0)*(ywmax-y0)/(y1-y0);
y = ywmax;
}
else
if( codeout & BOTTOM)
{
x = x0 + (x1-x0)*(ywmin-y0)/(y1-y0);
y = ywmin;
}
else
if ( codeout & RIGHT)
{
y = y0+(y1-y0)*(xwmax-x0)/(x1-x0);
x = xwmax;
}
else
{
y = y0 + (y1-y0)*(xwmin-x0)/(x1-x0);
x = xwmin;
}
if( codeout == code0)
{
x0 = x; y0 = y;
code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
}
else
{
x1 = x; y1 = y;
code1 = calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
}
}
} while( done == 0);

if(accept) ddaline(x0,y0,x1,y1);
ddaline(xwmin,ywmin,xwmin,ywmax);
ddaline(xwmin,ywmax,xwmax,ywmax);
ddaline(xwmax,ywmax,xwmax,ywmin);
ddaline(xwmax,ywmin,xwmin,ywmin);

getch();
}

int main()
{

 float x2,y2,x1,y1,xwmin,ywmin,xwmax,ywmax;
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\BGI");
printf("Enter the starting point\n");
  scanf("%f %f", &x1, &y1);
  printf("Enter the ending point\n");
  scanf("%f %f", &x2, &y2);
  printf("Enter xwmin, ywmin, xwmax, ywmax\n");
  scanf("%f %f %f %f",&xwmin,&ywmin,&xwmax,&ywmax);  
cleardevice();
lineclip(x1,y1,x2,y2,xwmin,ywmin,xwmax,ywmax );
getch();
closegraph();
  return 0;
}
