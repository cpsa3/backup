////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-11-20 14:47:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1598
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
const int INF=99999999;
struct px
{
	int x,y,d;
};
struct px stu[1005];
int cmp(const void *p1,const void *p2)
{
	return ((px *)p1)->d-((px *)p2)->d;
}
int p[205];//p[x]������¼x��ĸ����
int N,M,Q;
int set_find(int x)//Ѱ�Ҹ��ڵ�
{
	if(x==p[x])
		return x;
	else
		p[x]=set_find(p[x]);
	return p[x];
}
void set_unit(int x,int y)
{
	int dx=set_find(x);
	int dy=set_find(y);
	p[dx]=dy;
}
main ()
{
	int i,j,s,e;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i=1;i<=M;i++)
			scanf("%d%d%d",&stu[i].x,&stu[i].y,&stu[i].d);
		qsort(stu+1,M,sizeof(stu[0]),cmp);//��С�������򣬱���ö��
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d%d",&s,&e);
			int min=INF;
			for(i=1;i<=M;i++)//�Ͻ磺ö�ٱ�
			{
				for(j=1;j<=N;j++)//��ʼ��
					p[j]=j;
				for(j=i;j<=M;j++)//һ��Ҫ��i��ʼ����ȻWA���½�
				{
					set_unit(stu[j].x,stu[j].y);
					if(set_find(s)==set_find(e))
					{
						if(min>stu[j].d-stu[i].d)
							min=stu[j].d-stu[i].d;
						break;//�����Ź��򣬿�ֱ��̰��
					}
				}
			}
			if(min==INF) 
				min=-1;
			printf("%d\n",min);
		}
	}
return 0;
}


