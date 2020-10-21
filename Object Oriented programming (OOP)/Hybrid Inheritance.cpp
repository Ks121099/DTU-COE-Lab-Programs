#include<iostream>
using namespace std;
typedef enum{Manager, CTO, CEO} Post;
const char *posts[]={ "Manager","CTO","CEO" };
class Person
 {
 protected:
 int age;
 char * name;
 public :
 void getR(int r, const char * n)
{
 age = r;
 name = new char[strlen(n) + 1];
 strcpy(name, n);
 }
 void showR()
{
 cout<<"Name : "<<name<<"\n";
 cout<<"Age : "<<age<<"\n";
 }
};
class Employee : public Person
{
 protected:
 int empId;
 Post post;
 public:
 void getE(int r, Post p)
{
 empId = r;
 post = p;
 }
 void showE()
{
 cout<<"Employee ID : "<<empId<<"\n";
 cout<<"Post : "<<posts[post]<<"\n";
 }
};
class Salary {
 protected: double salary;
 public :
 void showS()
 {

 cout<<fixed<<setprecision(1)<<"Total salary : "<<salary<<" pa \n";
 }
 };
class Increment : public Salary, public Employee
{
 protected: double inc;
 public:
 void display()
{
 switch(post)
{
 case(0) :
 inc = 1.0;
 salary = 1000000;
 break;
 case(1) :
 inc = 1.5;
 salary = 2000000;
 break;
 case(2) :
 inc = 2.0;
 salary = 3000000;
 break;
 }
 showR();
 showE();
 showS();
 cout<<"Increment : "<<inc<<" percent pa \n";
 }
};
int main ()
 {
 Increment r1;
 r1.getR(23, "Kunal");
 Post p = CEO;
 r1.getE(109 , p);
 r1.display();
 return 0;
}