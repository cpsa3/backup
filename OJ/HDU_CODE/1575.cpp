////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-21 11:49:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=12;
const int MOD=9973;
struct px
{
	int map[MAX][MAX];
};
struct px unit,qs;
int N,K;
px mul(px a,px b)//矩阵乘法
{
	px c;
	int i,j,k;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			c.map[i][j]=0;
			for(k=1;k<=N;k++)
				c.map[i][j]+=a.map[i][k]*b.map[k][j];
			c.map[i][j]%=MOD;
		}
return c;
}
void input()//数据输入
{
	int i,j;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			scanf("%d",&qs.map[i][j]);
			if(i==j)
				unit.map[i][j]=1;
			else
				unit.map[i][j]=0;
		}

}
int getans()
{
	int i;
	px p,q;
	p=unit;
	q=qs;
	while(K!=1)
	{
		if(K%2)//K是奇数
		{
			K--;
			p=mul(p,q); //如果k是奇数,那么就不能进行平均的二分,所以让p乘以一个单位[dan wei]矩阵,保证其不变,然后k--就可以进行二分了
		}
		else
		{
			K>>=1;//K除2
			q=mul(q,q);//重点
		}
	}
	p=mul(p,q);//得到最终矩阵
	int ans=0;
	for(i=1;i<=N;i++)
	{
		ans+=p.map[i][i];
		ans%=MOD;
	}
return ans;
}
main ()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		input();
		printf("%d\n",getans());
	}
return 0;
}