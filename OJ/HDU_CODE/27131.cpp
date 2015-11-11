////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2012-03-17 12:09:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2713
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:808KB
//////////////////System Comment End//////////////////
/*
DP:
a[i] : input data
b[i] : 前i 个 元素的且经历奇数步的最高值
c[i] : 前i 个 元素的且经历偶数步的最高值
则 根据b[i]   c[i]  有没有用到a[i]分类即可
 
b[i]=max(b[i-1],c[i-1]+a[i])
c[i]=max(c[i-1],b[i-1]-a[i])
可用两个变量代替b[i]c[i]。显然结果就是b[n]

贪心：
每次加递增序列里的最大数！ 减去递减数列里的最小数！~~
例如：7 (2 1) (8) (4 3) (5 6)  原数列应该划分如左形式：
那么:+7 -1 +8 -3 +6 = 17
需要提示的是:  最后一个数一定是"+".
*/
#include <iostream>
#include <cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MAXN 150005
using namespace std;

int N;
int a[MAXN],b,c;
void Init()
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&a[i]);
}
void Solve()
{
	int i,t;
	b=a[1];
	c=0;
	for(i=2;i<=N;i++)
	{
		t=b;
		b=max(b,c+a[i]);
		c=max(c,t-a[i]);
	}
	printf("%d\n",b);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
	Init();
	Solve();
	}
return 0;
}