////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 13:03:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
char s[2];
__int64 A(int n,int m)
{
	__int64 ans=1;
	int i;
	for(i=n;i>=n-m+1;i--)
		ans*=i;
	return ans;
}
__int64 C(int n,int m)
{
	//__int64 ans=1;
	return A(n,m)/A(m,m);
} 
int main()
{
	int T,m,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%d%d",s,&n,&m);
		if(s[0]=='A')
			printf("%I64d\n",A(n,m));
		else
			printf("%I64d\n",C(n,m));
	}
return 0;
}