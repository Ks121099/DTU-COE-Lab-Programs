#include <iostream>
using namespace std;
class C_Polygon
{
 protected:
 double x, y;
 public:
 void set(double i, double j)
 {
 x = i;
 y = j;
 }
 virtual void area()
 {
 cout << "Calculate area for diff shapes \n ";
 }
};
class C_triangle : public C_Polygon
{
 public:
 void area()
 {
 cout << "Area of triangle with height ";
 cout<< x << " and base "<<y<<" is " ;
 cout << x * 0.5 * y << ".\n";
 }
};
class C_rectangle : public C_Polygon
{
 public:
 void area()
 {
 cout << "Rectangle with dimensions ";
 cout << x << " and " << y;
 cout << " has an area of ";
 cout << x * y << ".\n";
 }
};
int main ()
{
 C_Polygon *c;
 C_rectangle r;
 C_triangle t;
 c = &r;
 int k,l;
 cout<<"\nEnter length and breadth of rectangle :";
 cin>>k>>l;
 c->set(k, l);
 c->area();
 c = &t;
 cout<<"\nEnter perpendicular and base of triangle :";
 cin>>k>>l;
 c->set(k,l);
 c->area();
}