#include<iostream>
using namespace std;
class A
 {
 int x;
 int y;
 public:
 friend void swap(A&);
 void setData(int a, int b)
{
 x = a; y = b;
 }
};
void swap(A& a)
 {
 cout<<"\nBefore swapping : x = "<<a.x<<" , y = "<<a.y<<"\n";
 int A::* px = &A :: x;
 int A::* py = &A :: y;
 A *pm = &a;
 int temp = a.*px; //object-name .* pointer to member function
 a.*px = pm->*py; //pointer to object ->* pointer to member function
 pm->*py = temp;
 cout<<"\nAfter swapping : x = "<<a.x<<" , y = "<<a.y<<"\n";
}
int main ()
{
 A a1;
 int a,b;
 cout<<"Enter First number \t";
 cin>>a;
 cout<<"Enter Second number \t";
 cin>>b;
 void (A::*pf)(int , int) = &A :: setData;
 (a1.*pf)(a,b); //Pointer to member function
 swap(a1);
 return 0;
}