////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-02 23:49:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *x,const void *y)
{
return *((int *)x)-*((int *)y);
}

main ()
{
int t,n,i,a[1001];
scanf("%d",&t);
while(t--)
{
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   qsort(a,n,sizeof(int),cmp);
   for(i=0;i<n-1;i++)
   printf("%d ",a[i]);
   printf("%d\n",a[i]);
}

return 0;
}
