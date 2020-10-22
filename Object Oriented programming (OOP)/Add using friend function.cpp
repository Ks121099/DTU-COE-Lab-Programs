#include<iostream>
using namespace std;
class B; //forward declaration
class A
{
 int x;
 friend int mean(A&, B&);
 public:
 void getData()
{
 cout<<"\nEnter First number: \t";
 cin>>x;
 }
};
class B
{
 int y;
 friend int mean(A& , B&);
 public:
 void getData()
 {
 cout<<"\nEnter Second number: \t";
 cin>>y;
 }
};
int mean(A& a, B& b)
{
 return (a.x + b.y)/2;
}
int main ()
 {
 A a;
 B b;
 a.getData();
 b.getData();
 cout<<"\nMean of the two numbers is :"<<mean(a, b);
 return 0;
}