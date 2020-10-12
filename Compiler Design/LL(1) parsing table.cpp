#include<bits/stdc++.h>
using namespace std;
string char2string(char c){
 string s="";
 s=s+c;
 return s;
}
set<string> setunion(set<string> a,set<string> b){
 set<string>::iterator it;
 for(it=b.begin();it!=b.end();it++)
 {
 if(*it=="{")
 {
 continue;
 }
 a.insert(*it);
 }
 return a;}
set<string> fos(string s, map<char,set<string>> m){
 set<string> result;
 for(int i=0;i<s.length();i++)
 {
 if(!isupper(s[i]))
 {
 result.insert(char2string(s[i]));
 return result;
 }
 else
 {
 result = setunion(result,m[s[i]]);
 if(m[s[i]].find("{")==m[s[i]].end())
 {
 return result; }} }
 result.insert("{");
 return result;
}
set<string> firststr(map<char,set<string>> t,string s1){
 char c=s1[0];
 set<string> s;
 string temp="";
 if(islower(c)) {
 s.insert(char2string(c));
 return s;}
 set<string> b=t[c];
 int i=0;
 for(set<string>::iterator it1=b.begin();it1!=b.end();it1++){
 temp=*it1;
 int n=temp.length();
 if(isupper(temp[i])){
 set<string> temp2=firststr(t,char2string(temp[n-1]));
 temp2.clear();
 while(1){
 if(i<n) {
 set<string> temp1=firststr(t,char2string(temp[i]));
 set<char>::iterator it;
 if(temp1.find("{")!=temp1.end()){
 i++;
 s=setunion(s,temp1);
 temp1.clear();}
 else{
 s=setunion(s,temp1);
 break; }
 }
 else{
 break;}
 if(temp2.find("{")!=temp2.end()&&i==n-1){
 s.insert("{"); } } }
 else if(temp[i]=='{'){
 s.insert("{"); }
 else{
 s.insert(char2string(temp[i])); }
 i=0;}
 return s;}
void follow(map<char,set<string>> &result, multimap<char,string> prod, map<char,set<string>>
first_res,char c,map<char,int> &encountered){
 encountered[c]=1;
 multimap<char,string>::iterator mmit;
 for(mmit=prod.begin();mmit!=prod.end();mmit++) {
 if((mmit->second).find(char2string(c))!=(-1)) {
 int p=(mmit->second).find(char2string(c));
 if(p==(mmit->second).length()-1 && (mmit->first)==c)
 {
 continue;
 }
 string ss=(mmit->second).substr(p+1,(mmit->second).length()-p);
 set<string> s =fos(ss,first_res);
 result[c]=setunion(result[c],s);
 if(s.find("{")!=s.end()) {
 if(encountered[mmit->first]==1 && result[mmit->first].size()==0){
 continue;}
 follow(result,prod,first_res,mmit->first,encountered);
 result[c]= setunion(result[c],result[mmit->first]); } } }}
int main(){
 int n;
 cout<<"Enter the no of productions\n";
 cin>>n;
 char starting;
 map<char,set<string>> m;
 set<string> s;
 for(int i=0;i<n;i++){
 char p;
 cin>>p;
 if(i==0) {
 starting = p;}
 string s1="";
 while(1) {
 cin>>s1;
 if(s1=="-1") {
 break; }
 s.insert(s1); }
 s1="";
 m.insert(make_pair(p,s));
 s.clear(); }
 set<string> ss;
 multimap<char,string> mm;
 map<char,int> en;
 for (auto it=m.begin(); it!=m.end(); ++it){
 en.insert(make_pair(it->first,0)); }
 for (map<char,set<string>>::iterator it=m.begin(); it!=m.end(); ++it){
 ss=it->second;
 set<string>::iterator it1;
 for(it1=ss.begin();it1!=ss.end();it1++){
 mm.insert(make_pair(it->first,*it1));}}
 map<char,set<string>> first_res;
 set<string> q;
 for (map<char,set<string>>::iterator it=m.begin(); it!=m.end(); ++it){
 q=firststr(m,char2string(it->first));
 first_res.insert(make_pair(it->first,q));
 q.clear();}
 set<string> p;
 map<char,set<string>> results;
 set<string> temporary;
 temporary.insert("$");
 results.insert(make_pair(starting,temporary));
 for(auto it=m.begin();it!=m.end();it++){
 follow(results,mm,first_res,it->first,en);}
 set<string> temp;
 map<char,map<char,string>> pt_result;
 for(auto it=mm.begin();it!=mm.end();it++){
 temp=fos(it->second,first_res);
 for(auto it1=temp.begin();it1!=temp.end();it1++) {
 string temp1=char2string(it->first)+"="+it->second;
 if(*it1=="{"){
 continue;}
 pt_result[it->first].insert(make_pair((*it1)[0],temp1));}
 if(temp.find("{")!=temp.end()) {
 p=results[it->first];
 for(auto it1=p.begin();it1!=p.end();it1++){
 string temp1=char2string(it->first)+"="+it->second;
 pt_result[it->first].insert(make_pair((*it1)[0],temp1)); } }}
 map<char,string> z;
 cout<<endl;
 cout<<"The LL1 Parsing table for the above grammar is:-";
 cout<<endl;
 for(auto it=pt_result.begin();it!=pt_result.end();it++){
 cout<<it->first<<endl;
 z=it->second;
 for(auto it1=z.begin();it1!=z.end();it1++)
 {
 cout<<it1->first<<":"<<it1->second<<"\t"; }
 cout<<endl;
 cout<<endl; }
 return 0;
}