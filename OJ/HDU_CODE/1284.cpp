////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
	 s=n/3+1;//����3�ֵ�      
	 for (i=0;i<=n/3;i++)       
		 s+=(n-3*i)/2;//����2�ֵ� ������Ϊ�Ѿ����3�ֵ� ������һ����Ҫ�ȼ���      
	 printf ("%d\n",s); 
} 
 return 0;
}