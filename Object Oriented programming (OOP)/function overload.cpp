#include <iostream>
using namespace std;
int area(int l, int b)
{
 return l*b;
}
int area(int s)
 {
 return s*s;
}
float area(float r)
 {
 return 3.14*r*r;
}
int main()
{
 int l,b,s;
 float r;
 cout<<"Enter length and breadth"<<endl;
 cin>>l>>b;
 cout<<"Area of rectangle is "<<area(l, b)<<endl;
 cout<<"Enter side of square"<<endl;
 cin>>s;
 cout<<"Area of square is "<<area(s)<<endl;
 cout<<"Enter radius"<<endl;
 cin>>r;
 cout<<"Area of circle is "<<area(r)<<endl;
 return 0;
}