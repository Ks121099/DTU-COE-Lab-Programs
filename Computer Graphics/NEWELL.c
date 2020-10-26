#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define ROUND(a)((int)(a+0.5))





void plotellipse(int xc,int yc,int x,int y)
{

putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);


}


void ell(int  xc,int yc,int rx,int ry)
{

int x=0;
int y=ry;
int r2x=rx*rx;
int r2y=ry*ry;
int p;
p=ROUND(r2y-r2x*ry+(0.25)*r2y);

plotellipse(xc,yc,x,y);


while((2*r2y*x)<(2*r2x*y))
{
if(p<0)
{
x++;
p=p+2*r2y*x+r2y;

}
else{

x++;
y--;
p=p+2*r2y*x+r2y-2*r2x*y;
}

plotellipse(xc,yc,x,y);
}

p=ROUND(r2y*(x+0.5)*(x+0.5)+r2x*(y-0.5)*(y-0.5)-r2x*r2y);
while(y>=0)
{

if(p>0)
{

y--;
p=p-2*r2x*y+r2x;
}
else{
x++;
y--;
p=p-2*r2x*y+r2x+2*r2y*x;

}

plotellipse(xc,yc,x,y);
}




}
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


void cir(int xc,int yc,int r)
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
p=p+(2*x)+1;

}

else{

x++;
y--;
p=p+2*(x-y)+1;

}
plotcircle(xc,yc,x,y);
delay(50);
}




}


int main()
{

int x1,x2,y1,y2,x,y;
int r,r1;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:/TURBOC3/BGI");
printf("Enter 1st coordibnates \n");
scanf("%d%d",&x1,&y1);
scanf("%d%d",&r,&r1);
cleardevice();
ell(x1,y1,r,r1);
getch();
closegraph();
return 0;
}