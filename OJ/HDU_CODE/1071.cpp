////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-05-05 13:50:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
double x[4],y[4];
int main()
{
int T,i;
double a,p1,p2,p3,ans1,ans2;
scanf("%d",&T);
while(T--)
{
for(i=1;i<=3;i++)
scanf("%lf%lf",&x[i],&y[i]);
double k,b;
k=(y[2]-y[3])/(x[2]-x[3]);
b=y[2]-k*x[2];
a=(y[3]-y[1])/((x[3]-x[1])*(x[3]-x[1]));
p1=a/3;p2=-(k+2*a*x[1])/2;p3=(a*x[1]*x[1]+y[1]-b);
ans1=p1*x[3]*x[3]*x[3]+p2*x[3]*x[3]+p3*x[3];
ans2=p1*x[2]*x[2]*x[2]+p2*x[2]*x[2]+p3*x[2];
if(ans1-ans2>=0)
printf("%.2lf\n",ans1-ans2);
else
printf("%.2lf\n",ans2-ans1);
}
return 0;
}