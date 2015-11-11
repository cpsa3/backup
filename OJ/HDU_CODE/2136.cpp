////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-12 00:56:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2136
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:4136KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#define MAXN 1000005
int e[MAXN];
bool isPrime(int x)
{
	if(x==0||x==1) return false;
	if(x==2||x==3) return true;
	if(x%2==0) return false;
	int i,temp=sqrt((double)x);
	for(i=3;i<=temp;i++)
	{if(x%i==0) return false;}
	return true;
}
void Init()
{
	e[1]=0;
	int cnt=1,i,j;
	for(i=2;i<MAXN;i++)
	{
		if(isPrime(i))
		{
			for(j=i;j<MAXN;j+=i)
				e[j]=cnt;
			cnt++;  
		} 
	} 
}
int main()
{
	Init();//¥Ú±Ì
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",e[n]);
	}
return 0;
}