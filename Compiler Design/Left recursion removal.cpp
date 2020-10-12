#include <bits/stdc++.h>
#include <iostream>
#define pb push_back
using namespace std;
set<string> prod[26], ans[52];
bool used[26];
int h(char ch)
{
 return ch-65;
}
char rh(int x)
{
 return x+65;
}
bool isTerminal(char ch)
{
 if(ch=='^'||(ch>=65&&ch<=90))
 return false;
 return true;
}
void convert_to_right(int i, set<string> conv, set<string> S)
{
 for(set<string>::iterator j=S.begin();j!=S.end();j++)
 {
 string x= *j+rh(i);
 x+="'";
 ans[i].insert(x);
 }
 for(set<string>::iterator j=conv.begin();j!=conv.end();j++)
 {
 string x=(*j).substr(1)+rh(i);
 x+="'";
 ans[i+26].insert(x);
 }
 ans[i+26].insert("^");
}
int main()
{
 int m;
 cout<<"Denote non-terminals by uppercase alphabets(A-Z) and terminals with lowercase
alphabets(a-z) and digits from(0-9). Epsilon is denoted by '^'\n";
 cout<<"\nEnter number of productions: ";
 cin>>m;
 cout<<"\nEnter each production in a separate line(format S->aB|cd):\n";
 int i, st;
 string s;
 for(i=0;i<m;i++)
 {
 cin>>s;
 int x=h(s[0]);
 used[x]=1;
 int j=1;
 while(s[j]=='-'||s[j]=='>')
 j++;
 while(j<s.size())
 {
 string v="";
 while(s[j]==' ')j++;
 while(j<s.size()&&s[j]!='|')
 {
 v+=s[j];
 j++;
 }
 prod[x].insert(v);
 j++;
 }}
 for(i=0;i<26;i++)
 {
 if(prod[i].empty())continue;
 set<string> S=prod[i], conv, aux;
 set<string>::iterator it;
 for(it=S.begin();it!=S.end();it++)
 {
 string v=*it;
 int j=h(v[0]);
 if(j>=0&&j<i)
 {
 //modify this production
 set<string>::iterator k=ans[j].begin();
 while(k!=ans[j].end())
 {
 aux.insert(*k+v.substr(1));
 k++;
 } }
 else
 aux.insert(v);
 }
 for(it=aux.begin();it!=aux.end();it++)
 {
 string v=*it;
 int j=h(v[0]);
 if(j==i)
 conv.insert(v);
 else ans[i].insert(v);
 }
 if(conv.size()==0)continue;
 S=ans[i];
 ans[i].clear();
 convert_to_right(i, conv, S);
 }
 cout<<"Productions after removal of left Recursion\n";
 for(i=0;i<26;i++)
 {
 if(ans[i].empty())continue;
 cout<<rh(i)<<"-> ";
 for(set<string>::iterator j=ans[i].begin();j!=ans[i].end();j++)
 {
 cout<<*j;
 set<string>::iterator k=j;
 k++;
 if(k!=ans[i].end())
 cout<<" | ";
 }
 cout<<endl;
 if(ans[i+26].empty())continue;
 cout<<rh(i)<<"'-> ";
 for(set<string>::iterator j=ans[i+26].begin();j!=ans[i+26].end();j++)
 {
 cout<<*j;
 set<string>::iterator k=j;
 k++;
 if(k!=ans[i+26].end())
 cout<<" | "; }
 cout<<endl;
 }}