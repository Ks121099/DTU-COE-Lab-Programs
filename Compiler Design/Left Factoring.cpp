#include<bits/stdc++.h>
using namespace std;
set<string> prod[26], ans [52];
bool used[26], vis[26];
vector<int> fr;
int fc;
int h(char ch){
 return ch-65;}
char rh(int x){
 return x+65;}
bool isTerminal(char ch){
 if(ch=='^'||(ch>=65 && ch<=90))
 return false;
 return true;}
void left_factor(){
 int i, j;
 queue<int> Q;
 for(i=0;i<26;i++){
 if(!prod[i].empty())
 Q.push(i);}
 while(!Q.empty()){
 i=Q.front();
 Q.pop();
 set<string> S=prod[i], cur;
 while(1){
 cur.clear();
 bool b=0;
 set<string>::iterator it=S.begin(), f;
 it=S.begin();
 while(it!=S.end()){
 string x=*it;
 f=it;
 f++;
 if(f==S.end())//*it is last production in this set{
 cur.insert(x);
 break; }
 string match="";
 string y=*f;
 for(j=0;j<x.size() && j<y.size();j++){
 if(x[j]==y[j]) {
 match+=x[j];
 b=1; }
 else
 break;}
 if(match=="")//No prefix matching {
 cur.insert(x);
 it=f;
 continue; }
 //Now at-least 2 strings have common prefix for sure
 f++;
 //search all productions with match as common prefix
 while(f!=S.end()) {
 y=*f;
 if(match.size()>y.size())
 break;
 for(j=0;j<match.size();j++) {
 if(match[j]!=y[j])
 break; }
 if(j!=match.size())break;
 f++; }
 //add matchX production to cur i.e i->matchX
 int k=fr[fc];
 cur.insert(match+rh(k));
 //add X->remaining part that did not match from it to f
 while(it!=f) {
 if((*it).size()>match.size())
 prod[k].insert((*it).substr(match.size()));
 else//add null production
 prod[k].insert("^");
 it++; }
 //add k to queue
 Q.push(k);
 //increment free terminals counter
 fc++; }
 S=cur;
 if(!b)
 break; }
 //set ans[i] to cur
 ans[i]=cur; }}
int main(){
 int m;
 cout<<"Denote non-terminals by uppercase alphabets(A-Z) and terminals with lowercase
alphabets(a-z) and digits from(0-9). Epsilon is denoted by '^'\n";
 cout<<"\nEnter number of productions: ";
 cin>>m;
 cout<<"\nEnter each production in a separate line(format S->aB|cd):\n";
 int i, st;
 string s;
 for(i=0;i<m;i++){
 cin>>s;
 int x=h(s[0]);
 used[x]=1;
 int j=1;
 while(s[j]=='-'||s[j]=='>')
 j++;
 while(j<s.size()){
 string v="";
 while(s[j]==' ')j++;
 while(j<s.size()&&s[j]!='|') {
 v+=s[j];
 j++; }
 prod[x].insert(v);
 j++; } }
 for(i=0;i<26;i++)
 if(!used[i])fr.push_back(i);
 left_factor();
 cout<<"After factoring\n";
 for(i=0;i<26;i++) {
 if(ans[i].empty())continue;
 cout<<rh(i)<<"-> ";
 for(set<string>::iterator j=ans[i].begin();j!=ans[i].end();j++) {
 cout<<*j;
 set<string>::iterator k=j;
 k++;
 if(k!=ans[i].end())
 cout<<" | "; }
 cout<<endl; }}
