#include<stdio.h>
#include<graphics.h>
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

void lineclip(float xwmin,float ywmin,float xwmax,float ywmax,float x1,float y1,float x2,float y2)
{
  float x11,y11,x21,y21;
  float xdelta=x2-x1;
  float ydelta=y2-y1;
  float p=0,q=0,r=0;
  float t0=0;
  float t1=1;
  int edge;
  for(edge =0;edge<4;edge++)
  {
	if(edge==0)
	{
		p=-xdelta;
		q=-(xwmin-x1);
	}
	else if(edge==1)
	{
		p=xdelta;
		q=(xwmax-x1);
	}
	else if(edge==2)
	{
		p=-ydelta;
		q=-(ywmin-y1);
	}
	else if(edge==3)
	{
		p=ydelta;
		q=(ywmax-y1);
	}
	r=q/p;
	if(p==0 && q<0)
	{
        		printf("The line is totaly outside the clipping window.\n");
		return ;
	}
	if(p<0)
	{
		if(r>t1)
		{
            			printf("The line is totaly outside the clipping window.\n");
			return ;
		}
		else if(r>t0)
		t0=r;
	}
	else if(p>0)
	{
		if(r<t0)
		{
            		    printf("The line is totaly outside the clipping window.\n");
		    return ;
		}
		else if(r<t1)
		t1=r;
	}
  }
 if(t0>0)
 {	x11=x1+t0*xdelta;
 	y11=y1+t0*ydelta;
 }
 if(t1<1)
 {
	x21=x1+t1*xdelta;
	y21=y1+t1*ydelta;
 }
 ddaline(x11,y11,x21,y21);

 ddaline(xwmin,ywmin,xwmin,ywmax);
 ddaline(xwmin,ywmax,xwmax,ywmax);
 ddaline(xwmax,ywmax,xwmax,ywmin);
 ddaline(xwmax,ywmin,xwmin,ywmin);
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
  lineclip(xwmin,ywmin,xwmax,ywmax,x1,y1,x2,y2);
  getch();
  closegraph();
  return 0;
}

