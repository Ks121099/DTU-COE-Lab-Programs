#include<iostream> 
#include <bits/stdc++.h> 
# define msize 500 
using namespace std; 
int adj[msize][26]; 
bool is_final[26]; 
int main() 
{ 
int n, m; 
cout<<"Enter number of states in DFA: "; 
cin>>n; 
cout<<"\nEnter number of transitions: "; 
cin>>m; 
cout<<"\nEnter Transitions(States are denoted by 0, 1, 2... and symbols are denoted by a,b,......z)";  cout<<"\nTransition in the form state1 input_symbol state2\n"; 
int i, x, y, j, init; 
char sym; 
memset(adj, -1, sizeof adj);//initialize all the elements to -1  for(i=0; i<m; i++) 
{ 
cin>>x; 
cin>>sym; 
while(sym==' '||sym=='\n') 
{cin>>sym; 
} 
cin>>y; 
adj[x][sym-97]=y; 
} 
cout<<"\nEnter initial state: "; 
cin>>init; 
int f; 
cout<<"\nEnter number of final states: "; 
cin>>f; 
cout<<"Enter final states: "; 
for(i=0;i<f;i++){ 
cin>>x; 
is_final[x]=1; } 
cout<<"\nEnter number of queries: "; 
int q; 
cin>>q; 
while(q--){ 
cout<<"Enter string: "; 
string s; 
cin>>s; 
int cur=init; 
for(i=0;i<s.size();i++){ 
if(adj[cur][s[i]-97]==-1){ 
break; } 
cur=adj[cur][s[i]-97]; } 
if(i==s.size()&&is_final[cur]) 
cout<<"String:"<<" "<<s<<" "<<"is accepted by DFA\n"; 
else 
cout<<"String:"<<" "<<s<<" "<<"is not accepted by DFA\n"; }}  