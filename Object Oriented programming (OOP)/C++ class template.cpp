#include <iostream>
using namespace std;
template <class T>
class Pair
 {
 T a;
 T b;
 public:
 Pair(T x, T y) {
 a = x;
 b = y;
 }
 T getMax()
{
 return (a > b) ? a : b;
 }
};
int main ()
{
 Pair<int> p(5, 10);
 int max = p.getMax();
 cout<<"Number greater between 5 and 10 is "<<p.getMax()<<"\n";
 Pair<char> p1('a' , 'b');
 cout<<"Greater ASCII value between 'a' and 'b' is "<<p1.getMax()<<"\n";
 return 0;
}