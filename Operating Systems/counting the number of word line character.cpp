#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int get_words(char s[])
{
int len = strlen(s), count = 0;
for(int i=0; i<len; i++)
 {
if (s[i] == ' ')
 {
count++;
while (s[++i] == ' ');
i--;
 }
 }
return count + 1;
}
int main()
{
ofstream fout;
fout.open("files.txt");
fout<<"Hello How are you\nI am good, What about you?";
fout.close();
ifstream fin;
fin.open("files.txt");
int num_char = 0, num_spaces = 0, num_lines = 0, num_words = 0;
char ch, s[100];
while (!fin.eof())
 {
fin.get(ch);
if (ch != 32)
num_char++;
 }
cout<< "Number of characters: " <<num_char<< "\n";
fin.clear();
fin.seekg(0,ios::beg);
while(!fin.eof())
 {
fin.getline(s, 100, '\n');
num_lines++;
 }
cout<< "Number of lines: " <<num_lines<< "\n";
fin.clear();
fin.seekg(0,ios::beg);
while (!fin.eof())
 {
fin.get(ch);
if (ch == 32)
num_spaces++;
 }
cout<< "Number of spaces: " <<num_spaces<< "\n";
fin.clear();
fin.seekg(0,ios::beg);
while (!fin.eof())
 {
fin.getline(s, 100, '\n');
num_words += get_words(s);
 }
cout<< "Number of words: " <<num_words<< "\n";
fin.close();
}