#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<char> > prod[26];
set<char> first[26], follow[26];
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
int n, m;
bool visited[26];
void findFirst(int x)
{
 int y, i, j;
 visited[x]=1;
 for(i=0;i<prod[x].size();i++)
 {
 vector<char> v=prod[x][i];
 for(j=0;j<v.size();j++)
 {
 char ch=v[j];
 if(isTerminal(ch)||ch=='^')
 {
 first[x].insert(ch);
 break;
 }
 int y=h(ch);
 if(!visited[y])
 findFirst(y);
 set<char> s=first[y];
 set<char>::iterator it;
 for(it=s.begin();it!=s.end();it++)
 {
 if(*it!='^')
 first[x].insert(*it);
 }
 if(s.find('^')==s.end())break;//no epsilon in first
 }
 if(j==v.size())//add epsilon to first[x] as string may be empty
 first[x].insert('^');
 }
}
void findFollow(char ch)
{
 int i, j, k, x, y;
 set<char>::iterator it;
 x=h(ch);
 visited[x]=1;
 //check each production for occurrence of x
 for(i=0;i<26;i++)
 {
 if(prod[i].size()==0)
 continue;
 for(j=0;j<prod[i].size();j++)
 {
 vector<char> s=prod[i][j];
 bool b=0;
 for(k=0;k<s.size();k++)
 {
 if(s[k]==ch)
 {
 b=1;
 continue;
 }
 if(b)
 {
 if(isTerminal(s[k]))
 {
 follow[x].insert(s[k]);
 break;
 }
 if(s[k]=='^')
 continue;
 y=h(s[k]);
 for(it=first[y].begin();it!=first[y].end();it++)
 {
 if(*it!='^')
 follow[x].insert(*it);
 }
 if(first[y].find('^')==first[y].end())break;
 }
 }
 if(b==0)//No occurrence found in this production
 continue;
 if(k==s.size())//Nothing on right of ch...add follow of parent
 {
 if(!visited[i])
 findFollow(i+65);
 for(it=follow[i].begin();it!=follow[i].end();it++)
 follow[x].insert(*it);
 }
 }
 }
}
int main()
{
 cout<<"Note: Denote non-terminals by uppercase alphabets(A-Z) and terminals with lowercase
alphabets(a-z) and digits from(0-9). Epsilon is denoted by '^'\n";
 cout<<"\nEnter number of productions: ";
 cin>>m;
 cout<<"\nEnter each production in a separate line(format S->aB):\n";
 int i, j, st;
 string s;
 for(i=0;i<m;i++)
 {
 cin>>s;
 int x=h(s[0]);
 j=1;
 while(s[j]=='-'||s[j]=='>')
 j++;
 vector<char> v;
 while(j<s.size())
 {
 v.pb(s[j]);
 j++;
 }
 prod[x].pb(v);
 }
 char ch;
 cout<<"\nEnter start symbol: ";
 cin>>ch;
 while(ch==' '||ch=='\n')
 cin>>ch;
 st=h(ch);
 findFirst(st);
 for(i=0;i<26;i++)
 {
 if(!visited[i]&& prod[i].size()>0)
 findFirst(i);
 }
 cout<<"First:\n";
 for(i=0;i<26;i++)
 {
 if(first[i].size()==0)
 continue;
 cout<<rh(i)<<": {";
 set<char>::iterator it;
 for(it=first[i].begin();it!=first[i].end();it++)
 {
 cout<<*it;
 it++;
 if(it!=first[i].end())
 cout<<", ";
 it--;
 }
 cout<<"}\n";
 }
 for(i=0;i<26;i++)
 visited[i]=0;
 follow[st].insert('$');
 findFollow(st+65);
 for(i=0;i<26;i++)
 {
 if(!visited[i])
 findFollow((char)(i+65));
 }
 cout<<"Follow: \n";
 for(i=0;i<26;i++)
 {
 if(follow[i].size()==0)
 continue;
 cout<<rh(i)<<": {";
 set<char>::iterator it;
 for(it=follow[i].begin();it!=follow[i].end();it++)
 {
 cout<<*it;
 it++;
 if(it!=follow[i].end())
 cout<<", ";
 it--;
 }
 cout<<"}\n";
 }
 return 0;
}