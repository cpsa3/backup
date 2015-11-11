////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-06 14:36:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1290
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*平面分割空间(递推)*/
/*f[n]=f[n-1]+(n-1)*n/2+1*/
#include <iostream>
#include <cstdio>
int f[1005];
int main()
{
	int i,N;
	f[1]=2;
	for(i=2;i<=1000;i++)
		f[i]=f[i-1]+(i-1)*i/2+1;
	while(scanf("%d",&N)!=EOF)
		printf("%d\n",f[N]);
return 0;
}