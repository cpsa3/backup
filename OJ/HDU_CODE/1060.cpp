////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 12:49:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main() 
{ 
int t,n; 
double x = 0.0;
scanf("%d",&t);
while ( t-- )
{
scanf("%d",&n);
x = n*log10( (double)n );
x -= (__int64)x;
x =(int)pow(10.0,x);
printf("%.0lf\n",x); 
} 
return 0;
}
