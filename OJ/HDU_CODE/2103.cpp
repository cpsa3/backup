////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-29 15:05:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2103
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int v[100];
int main()
{
	int T,i,flag,N,M;
	__int64 ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&M,&N);
		for(i=1;i<=N;i++)
			scanf("%d",&v[i]);
		if(M>=N)
		{
			flag=0;
			ans=0;
			for(i=1;i<=N;i++)
			{
				if(flag)//һ�������к�����������Υ�棬�������������л���Ů
					{ans+=flag;flag*=2;}//ע���һ���к�����Υ��
				else
				{
					if(v[i])
						flag=1;
				}
			}
		}
		else
		{
			flag=0;
			ans=0;
			for(i=1;i<=M;i++)
			{
				if(flag)//һ�������к�����������Υ�棬�������������л���Ů
					{ans+=flag;flag*=2;}//ע���һ���к�����Υ��
				else
				{
					if(v[i])
						flag=1;
				}
			}
			if(flag)
			{
				for(i=M+1;i<=N;i++)
				{
					ans+=flag;
					flag*=2;
				}
			}
			else
			{
				flag=1;
				for(i=M+1;i<=N;i++)
				{
					ans+=flag;
					flag*=2;
				}
			}
		}
		ans*=10000;
		printf("%I64d RMB\n",ans);
	}
return 0;
}