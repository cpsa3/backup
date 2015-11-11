////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
px mul(px a,px b)//����˷�
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
void input()//��������
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
		if(K%2)//K������
		{
			K--;
			p=mul(p,q); //���k������,��ô�Ͳ��ܽ���ƽ���Ķ���,������p����һ����λ[dan wei]����,��֤�䲻��,Ȼ��k--�Ϳ��Խ��ж�����
		}
		else
		{
			K>>=1;//K��2
			q=mul(q,q);//�ص�
		}
	}
	p=mul(p,q);//�õ����վ���
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