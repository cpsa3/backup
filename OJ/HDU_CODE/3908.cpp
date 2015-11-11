////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-11 17:10:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3908
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*≈≈¡–◊È∫œ*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 805
using namespace std;
int W[MAXN],prime[MAXN],unprime[MAXN],N;
int gcd(int n,int m)
{
	if(m==0) return n;
	return gcd(m,n%m);
}
void Init()
{
	int i,j;
	memset(prime,0,sizeof(prime));
	memset(unprime,0,sizeof(unprime));
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&W[i]);
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			if(gcd(W[i],W[j])==1)
			{
				prime[i]++;
				prime[j]++;
			}
			else 
			{
				unprime[i]++;
				unprime[j]++;
			}
		}
	}
}
void Solve()
{
	int i;
	int sum=0;
	for(i=1;i<=N;i++)
		sum+=prime[i]*unprime[i];
	printf("%d\n",N*(N-1)*(N-2)/6-sum/2);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}