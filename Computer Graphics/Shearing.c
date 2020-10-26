#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
int main()
{
 int x1, x2, y1, y2;
 int choice;
 int shx,shy;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter top left coordinate\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter bottom right coordinate\n");
    scanf("%d %d", &x2, &y2);
    printf("Before shearing \n");
    rectangle(x1, y1, x2, y2);
    getch();
    cleardevice();
    printf("1.X direction shear \n");
    printf("2.Y direction shear \n");
    printf("3.X direction and Y direction shear\n");
    printf("Enter choice \n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:{
            printf("Enter shx\n");
            scanf("%d",&shx);
            y1=y1+shx*x1;
            y2=y2+shx*x2;
            rectangle(x1,y1,x2,y2);
            break;
    }
    case 2:{
            printf("Enter shy\n");
            scanf("%d",&shy);
            x1=x1+shy*y1;
            x2=x2+shy*y2;
            rectangle(x1,y1,x2,y2);
            break;
    }
    case 3:{
            printf("Enter shx and shy\n");
            scanf("%d%d",&shx,&shy);
            y1=y1+shx*x1;
            y2=y2+shx*x2;
            x1=x1+shy*y1;
            x2=x2+shy*y2;
            rectangle(x1,y1,x2,y2);
            break;
    }
    }
    getch();

    closegraph();




return 0;
}
