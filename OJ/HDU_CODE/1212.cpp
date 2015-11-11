////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-18 23:54:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

int main()
{
int n,i,j;
string s;
while(cin>>s>>n){
      j = 0 ;
      for(i=0; i<s.length(); i++){
               j = ( j*10 % n + (s[i]-'0')%n ) % n ;
               }          
      cout<<j<<endl;       
}    
return 0;
} 

