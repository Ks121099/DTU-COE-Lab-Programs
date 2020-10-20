#include<iostream>
#include<stdlib.h>
using namespace std;
class look_disk
{
int ref[100];
int ttrk,cur,size,prev;
int sort();
public:
void getdata();
void total_move();
};
int look_disk::sort()
{
int temp;
for(int i=0;i<size-1;i++)
for(int y=0;y<size-1;y++)
if(ref[y]>ref[y+1])
{
temp=ref[y+1];
ref[y+1]=ref[y];
ref[y]=temp;
}
for(int i=0;i<size;i++)
if(ref[i]>cur)
return i;
return size;}
void look_disk::getdata()
{cout<<"Enter total number of tracks : ";
cin>>ttrk;
ttrk--;
cout<<"Enter the current position of head : ";
cin>>cur;
cout<<"Enter previous position of head : ";
cin>>prev;
cout<<"Enter the size of queue : ";
cin>>size;
cout<<"Enter the request for tracks : ";
for(int i=0;i<size;i++)
cin>>ref[i];
}
void look_disk::total_move()
{int num=cur,move=0,ind,dir=cur-prev;
ind=sort();
if(dir>0)
{for(int i=ind;i<size;i++)
{move+=ref[i]-num;
num=ref[i];}
if(ind!=0)
{if(ind==size)
move+=num-ref[ind-1];
else
move+=ref[size-1]-ref[ind-1];
num=ref[ind-1];
for(int i=ind-2;i>=0;i--)
{move+=num-ref[i];
num=ref[i];
}}}
else
{for(int i=ind-1;i>=0;i--)
{move+=num-ref[i];
num=ref[i];}
if(ind==0)
move+=ref[ind]-num;
else if(ind!=size)
move+=ref[ind]-ref[0];
num=ref[ind];
for(int i=ind+1;i<size;i++)
{move+=ref[i]-num;
num=ref[i];
}}
cout<<"Total head movements : "<<move;
}
int main()
{look_disk look;
look.getdata();
look.total_move();
return 0;
}