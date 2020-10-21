#include <iostream>
#include <string.h>
using namespace std;
class String
{
 char *s;
 int len;
 public:
 String()
 { //Constructor function
 s = NULL;
 len = 0;
 }
 String(const char *p)
{
 len = strlen(p);
 s = new char[len + 1];
 strcpy(s, p);
 }
 void display()
 {
 cout << s <<"\n";
 }
 friend int operator <= (String & , String&);
 friend String operator+ (String &, String&);
};
String operator+ (String &c1, String &c2)
 {
 String ans;
 ans.len = strlen(c1.s) + + strlen(c2.s);
 ans.s = new char[ans.len + 1];
 strcpy(ans.s, strcat(c1.s, c2.s));
}
int operator<= (String &c1, String &c2)
 {
 int n = strlen(c1.s);
 int m = strlen(c2.s);
 if(n <= m) {
 return 1;
 }
 return 0;
}
int main()
{
 String s1 = "New";
 String s2("York");
 String s3("Delhi");
 cout<<"\nS1 = ";
 s1.display();
 cout<<"\nS2 = ";
 s2.display();
 cout<<"\nS3 = ";
 s3.display();
 String s4 = (s2 <= s3) ? s3 : s2;
 cout<<"\nS1 + bigger(S2, S3) = ";
 (s1 + s4).display();
 return 0;
}