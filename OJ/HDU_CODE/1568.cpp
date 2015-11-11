////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-05 23:58:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1568
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*数学题*/
#include <iostream>
#include <cstdio>
#include <cmath>
const double a=log10(1.0/(sqrt(5.0)));
const double b=log10((1+sqrt(5.0))/2);
int f[21]; 
int main() 
{
	int i,N;
	f[0]=0;f[1]=1;
	for(i=2;i<=20;i++)//f[20]=6765;f[21]=10946;
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&N)!=EOF)
	{
		if(N<=20) printf("%d\n",f[N]);
		else
		{
			double ans=(a+N*b);//忽略最后一项无穷小
			ans=ans-(int)ans;
			ans=pow(10.0,ans);
			while(ans<1000) ans*=10;
			printf("%d\n",(int)ans);
		} 
	} 
return 0;
}