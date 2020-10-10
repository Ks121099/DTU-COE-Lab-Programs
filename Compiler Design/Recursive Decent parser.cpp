#include<bits/stdc++.h>
using namespace std;
fstream file1;
char l;
void T();
void E();
void T1();
void E1();
void F();
void match(char t){
 if(l==t)
 file1.get(l);
 else
 cout<<"Error in parsing";}
void E(){
 cout<<"E=TE' production is used"<<endl;
 T();
 E1();}
void T(){
 cout<<"T=FT' production is used"<<endl;
 F();
 T1();}
void E1(){
 if(l=='+'){
 cout<<"E'=+TE' production is used"<<endl;
 match('+');
 T();
 E1();}
 else{
 cout<<"E'={ production is used"<<endl;
 return ;}}
void F(){
 if(l=='i'){
 cout<<"F=i production is used"<<endl;
 match('i');}
 else if(l=='('){
 cout<<"F=(E) production is used"<<endl;
 match('(');
 E();
 match(')'); }}
void T1(){
 if(l=='*')
 {
 cout<<"T'=*FT' production is used"<<endl;
 match('*');
 F();
 T1();
 }
 else
 {
 cout<<"T'={ production is used"<<endl;
 return;
 }
}
int main()
{
 file1.open("recursive.txt",ios::in);
 file1.get(l);
 E();
 if(l=='$')
 cout<<"Parsing Successful";
}
