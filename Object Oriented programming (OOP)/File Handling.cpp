#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
 string result = "";
 string line = "";
 cout<<"\nPlease enter your text here: \n";
 while(getline(cin,line) && !line.empty()) {
 result += line + '\n';
 }
 ifstream infile;
 ofstream outfile;
 outfile.open("abc.txt");
 outfile << result;
 outfile.close();
 char ch;
 int lines = 0;
 int words = 0;
 int chars = 0;
 infile.open("abc.txt");
 while(infile.get(ch)) {
 if(ch == ' '){
 words++;
 } else if(ch == '\n') {
 words++;
 lines++;
 }
 chars++;
 }
 if(words == 0){
 words++;
 }
 else {
 words--;
 cout<<" Lines : "<<lines<<endl;
 cout<<" Words : "<<words<<endl;
 cout<<" Characters : "<<chars<<endl;
 }
 return 0;
}