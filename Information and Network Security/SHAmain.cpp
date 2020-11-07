#include "sha1.h"
#include <string>
#include <iostream>
using namespace std;
int main(int /* argc */, const char ** /* argv */)
{
 cout<<"Enter the plain text : ";
 string input;
 cin>>input;
 SHA1 checksum;
 checksum.update(input);
 const string hash = checksum.final();
 cout << "\nThe SHA-1 of \"" << input << "\" is: " << hash << endl;
 return 0;
}