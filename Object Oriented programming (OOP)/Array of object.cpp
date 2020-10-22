#include<iostream>
using namespace std;
class Employee
{
 int age;
 char name[50];
 int emp_id;
 public:
 void setData();
 void displayData();
};
void Employee::setData()
{
 cout<<"Enter name: ";
 cin>>name;
 cout<<"Enter age: ";
 cin>>age;
 cout<<"Enter employee id: ";
 cin>>emp_id;
 }
 void Employee::displayData()
{
 cout<<"Name is "<<name<<endl;
 cout<<"Age is "<<age<<endl;
 cout<<"Employee Id is "<<emp_id<<endl;
 cout<<endl;
 }
int main()
{
 Employee e1[3]; //Array of objects
 for(int i = 0;i < 3; i++)
{
 cout<<"Enter info for employee "<<i + 1<<endl;
 e1[i].setData();
 cout<<endl;
 }
 cout<<"\n*******************************************************\n";
 for(int i = 0;i < 3; i++)
 {
 cout<<"Info for employee "<<i + 1<<endl;
 e1[i].displayData();
 }
 return 0;
}