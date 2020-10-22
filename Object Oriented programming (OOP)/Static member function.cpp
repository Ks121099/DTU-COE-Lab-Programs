#include <iostream>
using namespace std;
class B
{
 int length;
 int breadth;
 int height;
 public:
 static int objectCount; //static data member
 B(int l = 2, int b = 2, int h = 2) //parameterized constructor
 {
 cout <<"Constructor called." << endl;
 length = l;
 breadth = b;
 height = h;
 objectCount++; //will calculate number of objects
 }
 double Volume()
 {
 return length * breadth * height;
 }
};
// Initialize static member of class Box
int B::objectCount = 0;
int main(void)
 {
 B x1(3, 1, 1);
 B x2(8, 6, 2);
 cout << "Total objects: " << B::objectCount << endl;
 return 0;
}