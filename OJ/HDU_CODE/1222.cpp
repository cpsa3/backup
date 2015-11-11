////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-06 14:57:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1222
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*最大公约数*/
#include <iostream>
int gcd(int a,int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		if(gcd(n,m)!=1) printf("YES\n");
		else printf("NO\n");
	}
return 0;
}