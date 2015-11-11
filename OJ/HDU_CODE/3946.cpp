////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-17 19:59:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3946
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*贪心*/
/*先尽可能排最多的3，然后依次减少一个3增加若干个二，同时更新答案*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 10006
#define max(a,b) (a>b?a:b)
using namespace std;
int num2[MAXN],num3[MAXN];
int c,r,n2,n3,cas;
bool cmp(int a,int b)
{
	return a>b;
}
void Init()
{
	int i,t;
	num2[0]=num3[0]=0;
	scanf("%d%d%d%d",&r,&c,&n2,&n3);

	if(r>c) {t=r;r=c;c=t;}
	for(i=1;i<=n2;i++)
		scanf("%d",&num2[i]);
	for(i=1;i<=n3;i++)
		scanf("%d",&num3[i]);
}
void Print()
{
	int i;
	printf("----------------------\n");
	for(i=1;i<=n2;i++)
		printf("%d ",num2[i]);
	printf("\n");
	printf("----------------------\n");
}
void Solve()
{
	int i,index2,index3,Max;
	sort(num2+1,num2+1+n2,cmp);
	sort(num3+1,num3+1+n3,cmp);

	//Print();
	for(i=1;i<=n2;i++)
		num2[i]+=num2[i-1];
	for(i=1;i<=n3;i++)
		num3[i]+=num3[i-1];
	printf("Case #%d: ",cas++);
	if(n2==1&&n3==1) 
		printf("0\n");
	else
	{
		if(r==2)//要注意对2*N的情况特殊考虑
			index3=(c/3)*2;
		else
			index3=c*r/3;
		if(index3>n3) index3=n3;
		index2=(r*c-index3*3)/2;

		if(index2>n2) index2=n2;

		Max=num3[index3]+num2[index2];
		for(i=index3-1;i>=0;i--)
		{
			index2=(r*c-i*3)/2;
			if(index2>n2)
			{
				index2=n2;
				Max=max(Max,num2[index2]+num3[i]);
				break;
			}
			else
				Max=max(Max,num2[index2]+num3[i]);
		}
	}
	printf("%d\n",Max);
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}