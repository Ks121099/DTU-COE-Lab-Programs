#include <iostream>
using namespace std;
class Complex
{
 float real;
 float imaginary;
 public:
 Complex() //Constructor function
 { real = imaginary = 0;
 }
 void set() // Member function
 {
 cout << "Enter real part: ";
 float a;
 cin >> a;
 cout << "Enter complex part: ";
 float b;
 cin >> b;
 real = a;
 imaginary = b;
 }
 void display()
 {
 cout << real << " + " << imaginary << " i \n";
 }
 Complex operator+(Complex &);
 Complex operator-(Complex &);
 Complex operator*(Complex &);
 Complex operator/(Complex &);
};
Complex Complex::operator+(Complex &c1)
{
 Complex ans;
 ans.real = real + c1.real;
 ans.imaginary = imaginary + c1.imaginary;
 return ans;
}
Complex Complex::operator-(Complex &c1)
{
 Complex ans;
 ans.real = real - c1.real;
 ans.imaginary = imaginary - c1.imaginary;
 return ans;
}
Complex Complex::operator*(Complex &c1)
{
 Complex ans;
 ans.real = real * c1.real - imaginary * c1.imaginary;
 ans.imaginary = imaginary * c1.real + real * c1.imaginary;
 return ans;
}
Complex Complex::operator/(Complex &c1)
{
 Complex ans;
 float den = c1.real * c1.real + c1.imaginary * c1.imaginary;
 ans.real = (real * c1.real + imaginary * c1.imaginary)/den;
 ans.imaginary = (imaginary * c1.real - real * c1.imaginary)/den;
 return ans;
}
int main()
{
 Complex c1, c2, c3; // object of class created
 cout << "First complex no :" << endl;
 c1.set();
 cout << "****************************************\n";
 cout << "Second complex no: " << endl;
 c2.set();
 cout << "****************************************\n";
 cout<<"\n First number: ";
 c1.display();
 cout<<"\n Second number: ";
 c2.display();
 c3 = c1 + c2;
 cout << "\n Sum is :";
 c3.display();
 c3 = c1 - c2;
 cout << "\n Difference is : ";
 c3.display();
 c3 = c1 * c2;
 cout << "\n Product is : ";
 c3.display();
 c3 = c1 / c2;
 cout << "\n Fist divided by Second : ";
 c3.display();
 return 0;
}