////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-12 15:01:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
struct px
{
	int a,b;
};
int p[1000];//�����丸�ڵ�
struct px stu[10000];
int find_set(int x)//�ҵ�x�ĸ����
{
	if(x!=p[x])
		p[x]=find_set(p[x]);//�ؼ���
	return p[x];
}
main ()
{
	int n,m,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",&stu[i].a,&stu[i].b);
		for(i=0;i<1000;i++)
			p[i]=i;//��ʼ��
		int x,y,k=0;
		for(i=1;i<=m;i++)
		{
			x=find_set(stu[i].a);
			y=find_set(stu[i].b);
			if(x!=y)
			{
				k++;
				if(k==n-1)//��ǰ�˳���Ϊ�Ѿ�����
					break;
				p[x]=y;
			}
		}
		printf("%d\n",n-1-k);
	}
return 0;
}