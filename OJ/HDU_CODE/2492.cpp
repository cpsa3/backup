////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-07 15:43:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2492
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1880KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAXN=100005;
__int64 c1[MAXN],c2[MAXN];//c1[i]记录i之前小于i的数的个数；c2[i]表示i前面小于i的所有数j的c1[j]之和
int a[MAXN],max;//记录输入的数据
int lowbit(int t)
{return t&(-t);}
__int64 get_sum(int p,__int64 c[])
{
	__int64 ans=0,i;
	for(i=p;i>0;i-=lowbit(i))
		ans+=c[i];
	return ans;
}
void insert(int p,__int64 c[],__int64 v)
{
	int i;
	for(i=p;i<=max;i+=lowbit(i))
		c[i]+=v;
}
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		max=0;
		for(i=1;i<=n;i++)//数据输入
		{
			scanf("%d",&a[i]);
			if(max<a[i])
				max=a[i];
		}
		__int64 ans=0;//记录答案
		memset(c1,0,sizeof(c1[0])*(max+1));
		memset(c2,0,sizeof(c2[0])*(max+1));
		for(i=1;i<=n;i++)
		{
			ans+=get_sum(a[i]-1,c2);
			insert(a[i],c2,get_sum(a[i]-1,c1));
			insert(a[i],c1,1);
		}
		memset(c1,0,sizeof(c1[0])*(max+1));
		memset(c2,0,sizeof(c2[0])*(max+1));
		for(i=n;i>=1;i--)
		{
			ans+=get_sum(a[i]-1,c2);
			insert(a[i],c2,get_sum(a[i]-1,c1));
			insert(a[i],c1,1);
		}
		printf("%I64d\n",ans);
	}
return 0;
}