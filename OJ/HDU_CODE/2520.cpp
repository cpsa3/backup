////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-16 19:45:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2520
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
int t,i;
double w;
scanf("%d",&t);
while(t--)
{
scanf("%lf",&w);
__int64 s=0;
for(i=1;w>=1;i=i+2,w--)
{
s=(s+i)%10000;
}
s+=i*w;
printf("%I64d\n",s%10000);
}
return 0;
}