#include <iostream>
using namespace std;
int main()
{
char c[50],d[50],t[50];
int i,m,j;
cout << "Enter the number of characters : ";
cin >> m;
cout << "\nEnter the characters (without spaces) : ";
for(i=0;i<m;i++)
cin >> c[i];
printf("\nOriginal data : ");
for(i=0;i<m;i++)
cout << c[i];
d[0]='d';
d[1]='l';
d[2]='e';
d[3]='s';
d[4]='t';
d[5]='x';
for(i=0,j=6;i<m;i++,j++)
{
if((c[i]=='d'&&c[i+1]=='l'&& c[i+2]=='e'))
{
d[j]='d';
j++;
d[j]='l';
j++;
d[j]='e';
j++;
m=m+3;
}
d[j]=c[i];
}
m=m+6; m++;
d[m]='d'; m++;
d[m]='l'; m++;
d[m]='e' m++;
d[m]='s'; m++;
d[m]=’t'; m++;
d[m]=‘x'; m++;
cout << "\n\nTransmitted data: ";
for(i=0;i<m;i++)
cout << d[i];
for(i=6,j=0;i<m-6;i++,j++)
{
if(d[i]=='d'&&d[i+1]=='l'&&d[i+2]=='e'&&d[i+3]=='d'&&d[i+4]=='l'&&d[i+5]=='e')
i=i+3;
t[j]=d[i];
}
cout << "\nReceived data:";
for(i=0;i<j;i++)
{
cout << t[i];
}
}