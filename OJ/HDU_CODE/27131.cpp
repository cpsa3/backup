////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
b[i] : ǰi �� Ԫ�ص��Ҿ��������������ֵ
c[i] : ǰi �� Ԫ�ص��Ҿ���ż���������ֵ
�� ����b[i]   c[i]  ��û���õ�a[i]���༴��
 
b[i]=max(b[i-1],c[i-1]+a[i])
c[i]=max(c[i-1],b[i-1]-a[i])
����������������b[i]c[i]����Ȼ�������b[n]

̰�ģ�
ÿ�μӵ����������������� ��ȥ�ݼ����������С����~~
���磺7 (2 1) (8) (4 3) (5 6)  ԭ����Ӧ�û���������ʽ��
��ô:+7 -1 +8 -3 +6 = 17
��Ҫ��ʾ����:  ���һ����һ����"+".
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