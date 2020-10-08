#include <iostream> 
#include <fstream> 
using namespace std; 
int checkKeyword(char buffer[]){ 
char keywords[32][10] =  
{"auto","break","case","char","const","continue","default",  "do","double","else","enum","extern","float","for","goto",  "if","int","long","register","return","short","signed", 
"sizeof","static","struct","switch","typedef","union", 
"unsigned","void","volatile","while" 
}; 
int i, flag = 0; 
for(i = 0; i < 32; ++i){ 
if(strcmp(keywords[i], buffer) == 0){ 
flag = 1; 
break; 
} 
} 
return flag; 
} 
bool checkDelimiter(char ch) 
{ 
if (ch == '/' || ch == ',' || ch == ';' || ch == '>' || 
ch == '<' || ch == '(' || ch == ')' || 
ch == '[' || ch == ']' || ch == '{' || ch == '}') 
return (true); 
return (false); 
} 
int main() { 
ifstream readFile; 
readFile.open("/Users/samarthgupta/Ios/Compiler Design/Compiler Design/code.cpp");  int keywords = 0,delimiters = 0,identifiers = 0,operators_count = 0; 
int flag = 0; 
bool isComment = false; 
while(!readFile.eof()){ 
char out[100]; 
readFile.getline(out,100); 
isComment=false; 
for( int i=0; out[i]!='\0'; i++) { 
if (out[i] == '/' && out[i + 1] == '/' && flag == 0) { 
isComment = true; 
break; 
} else if (out[i] == '/' && out[i + 1] == '*' && flag == 0) { 
flag = 1; 
isComment=true; 
} 
if(flag == 1){ 
isComment = true; 
} 
if(out[i] == '*' && out[i+1] == '/' && flag == 1){ 
flag = 0; 
isComment = true; 
break; 
} 
} 
if(!isComment){ 
char ch, buffer[15], operators[] = "+-*/%=&|^"; 
int j=0,i=0; 
for(i=0;out[i]!='\0';i++){ 
ch=out[i]; 
for(int s = 0; s<9; s++){ 
if(ch == operators[s]) 
{ 
operators_count++; 
//cout<<ch<<“ is operator\n"; 
break; 
} 
} 
if(checkDelimiter(ch)){ 
delimiters++; 
//cout<<ch<<“ is delimiter\n"; 
} 
if(isalnum(ch)){ 
buffer[j++] = ch; 
} else if((ch == ' ' || ch == '\n') && (j != 0)){  buffer[j] = '\0'; 
j = 0; 
if(checkKeyword(buffer) == 1){  //cout<<buffer<<“ is keyword\n";  keywords++; 
} else{ 
//cout<<buffer<<“ is indentifier\n";  identifiers++; 
} 
} 
} 
if(out[i]=='\0' && (j!=0)){ 
buffer[j] = '\0'; 
j = 0; 
if(checkKeyword(buffer) == 1){  //cout<<buffer<<“ is keyword\n";  keywords++; 
} 
else{ 
//cout<<buffer<<“ is indentifier\n";  identifiers++; 
}}} 
} 
readFile.close(); 
cout<<"Keywords : "<<keywords<<endl;  cout<<"Identifiers : "<<identifiers<<endl;  cout<<"Operators : "<<operators_count<<endl;  cout<<"Delimiters : "<<delimiters<<endl;  return 0; 
