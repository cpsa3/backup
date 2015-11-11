////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 22:42:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:992KB
//////////////////System Comment End//////////////////
#include<stdio.h>
// if i can be divided exactly by 3 sum(i) = sum(i-1) + i*i*i;else sum(i) = sum(i-1) + i;
__int64 sum[100001];
int main()
{ __int64 i,n;
    sum[0]=0;
  for(i=1;i<=100000;i++) 
  {if(i%3==0) sum[i]=sum[i-1]+i*i*i;
   else sum[i]=sum[i-1]+i;
  }
  while(1)
  {scanf("%I64d",&n);
   if(n<0) break;
   printf("%I64d\n",sum[n]);
  }
    return 1;
}

