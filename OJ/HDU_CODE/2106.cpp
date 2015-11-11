////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-12-29 15:32:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int mypow(int a,int n)
{
	int ans=1,i;
	for(i=1;i<=n;i++)
		ans*=a;
	return ans;
}
int get_num(char s[1000])
{
	int len=strlen(s);
	int base=0,flag=0,i,k;
	int c[100];
	for(i=0,k=0;i<len-1;i++)
	{
		if(flag)
			base=base*10+s[i]-'0';
		else
		{
			if(s[i]=='(')
				flag=1;
			else
			{c[k++]=s[i]-'0';}
		}
	}
	//printf("%d\n",base);
	int ans=0;
	for(i=0;i<k;i++)
		ans+=c[i]*mypow(base,k-1-i);//¾ÓÈ»Ð´³ÉÁËc[k]£¡£¡£¡£¡
	//printf("%d\n",ans);
	return ans;
}
int main()
{
	int N,i;
	char a[1000];
	while(scanf("%d",&N)!=EOF)
	{
		int ans=0;
		for(i=1;i<=N;i++)
		{
			scanf("%s",a);
			ans+=get_num(a);
		}
		printf("%d\n",ans);
	}
	return 0;
}