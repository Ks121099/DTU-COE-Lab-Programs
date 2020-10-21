#include<iostream>
#include <string.h>
using namespace std;
class Student
{
 protected:
 int rn;
char * name;
 public :
 void get(int r, const char * n)
 {
 rn = r;
 name = new char[strlen(n) + 1];
 strcpy(name, n);
 }
 void showrn()
 {
 cout<<"\nRoll No. : "<<rn<<"\n";
 cout<<"\nName : "<<name<<"\n";
 }
};
class Test : public Student
 {
 protected:
 int sub1, sub2;
 public:
 void getM(int m1, int m2)
 {
 sub1 = m1;
 sub2 = m2;
 }
 void showM()
 {
 cout<<"\nMarks in subject 1 : "<<sub1<<"\n";
 cout<<"\nMarks in subject 2 : "<<sub2<<"\n";
 }
};
class Result : public Test
{
 protected:
int total;
 public :
 void display()
 {
 total = sub1 + sub2;
 showrn();
 showM();
 cout<<"\nTotal marks : "<<total<<"\n";
 }
};
int main ()
{
 Result r1;
 r1.get(164, "Kunal");
 r1.getM(29 , 30);
 r1.display();
 return 0;
}