////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-14 15:23:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1577
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<math.h>
using namespace std;

int gcd(int x,int y)
{
if(x==0)
   return y; 
return gcd(y%x,x);
}

int main()
{
int l,x2,y2,x1,y1;
while(cin>>l&&l)
{
   cin>>x2>>y2>>x1>>y1;
   if(abs(x1)>l||abs(y1)>l)
   {
    cout<<"Out Of Range"<<endl;
    continue;
   }
   int x=x1-x2,y=y1-y2;
   x=abs(x),y=abs(y);
   if(gcd(x,y)==1)
   {
    cout<<"Yes"<<endl;
   }
   else
   {
    cout<<"No"<<endl;
   }
}
return 0;
}

