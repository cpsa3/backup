////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-03 15:40:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()
{ int n,s,i;
 while (scanf("%d",&n)!=EOF)
 {      
	 s=n/3+1;//计算3分的      
	 for (i=0;i<=n/3;i++)       
		 s+=(n-3*i)/2;//计算2分的 不过因为已经算过3分的 所以那一部分要先减掉      
	 printf ("%d\n",s); 
} 
 return 0;
}