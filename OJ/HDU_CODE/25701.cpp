////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-01-17 21:23:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define eps 1e-6
using namespace std;
int N;
double V,W;
double P[105];
void Init()
{
	int i;
	scanf("%d%lf%lf",&N,&V,&W);
	for(i=1;i<=N;i++)
		scanf("%lf",&P[i]);
	sort(P+1,P+1+N);
}
void Solve()
{
	int i;
	if(P[1]>W+eps) {printf("0 0.00\n");return;}
	double a=0,b=0;
	for(i=1;i<=N;i++)
	{
		a+=V*P[i]*1.0/100;
		b+=V;
		if(a/b*100>W+eps)
		{
			a-=V*P[i]*1.0/100;
			b-=V;
			break;
		}
	}
	printf("%.0lf %.2lf\n",b,a/b);
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