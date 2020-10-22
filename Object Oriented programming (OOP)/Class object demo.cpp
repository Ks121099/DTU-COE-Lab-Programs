#include<iostream>
using namespace std;
class Complex
{
 int real; //pvt data memebers
 int imaginary;
 public:
 Complex()
 { //Constructor function
 real = imaginary = 0;
 }
 void set()
 { // Member function
 cout<<"Enter real part "<<endl;
 int a; cin>>a;
 cout<<"Enter complex part "<<endl;
 int b; cin>>b;
 real = a;
 imaginary = b;
 }
 void display()
 {
 cout<<real<<" + "<<imaginary<<" i";
 }
 void add(Complex& , Complex&); //Member function prototype
};
void Complex::add (Complex& c1, Complex&c2)
{
 real = c1.real + c2.real;
 imaginary = c1.imaginary + c2.imaginary;
 }
int main()
 {
 Complex c1, c2,c3; // object of class created
 cout<<"First complex no :"<<endl;
 c1.set();
 cout<<"****************************************\n";
 cout<<"Second complex no: "<<endl;
 c2.set();
 c3.add(c1, c2);
 cout<<"****************************************\n";
 cout<<"Resultant complex no. is \n";
 c3.display();
 return 0;
}