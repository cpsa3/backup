////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-06 18:50:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2586
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1972KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
int N,M,s,e;
struct py
{
	int flag,sum,id;
};
struct py mark[40005];
struct px
{
	int a,b,l,sum;
};
struct px stu1[40005],stu2[40005];
int cmp(const void *p1,const void *p2)
{
	return ((struct px *)p1)->a-((struct px *)p2)->a;
}
int binary1(int x)
{
	int l=1,r=N-1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(stu1[mid].a==x)
			r=mid;
		else if(stu1[mid].a>x)
			r=mid-1;
		else
			l=mid+1;
	}
	if(stu1[l].a==x)
		return l;
	return 0;
}
int binary2(int x)
{
	int l=1,r=N-1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(stu2[mid].a==x)
			r=mid;
		else if(stu2[mid].a>x)
			r=mid-1;
		else
			l=mid+1;
	}
	if(stu2[l].a==x)
		return l;
	return 0;
}
queue<py>Q;
void bfs()
{
	int i,j;
	while(!Q.empty())
		Q.pop();
	for(i=1;i<=N;i++)
		mark[i].flag=mark[i].sum=0;
	mark[s].flag=1;
	Q.push(mark[s]);
	struct py temp,t;
	while(!Q.empty())
	{
		t=Q.front();
		Q.pop();
		if(t.id==e)
		{printf("%d\n",t.sum);return;}
		int w=binary1(t.id);
		if(w)
		{
			for(i=w;i<=N-1;i++)
			{
				if(t.id==stu1[i].a)
				{
					if(!mark[stu1[i].b].flag)
					{
						mark[stu1[i].b].flag=1;
						temp.id=stu1[i].b;
						temp.sum=t.sum+stu1[i].l;
						Q.push(temp);
					}
				}
				else
					break;
			}
		}
		w=binary2(t.id);
		if(w)
		{
			for(i=w;i<=N-1;i++)
			{
				if(t.id==stu2[i].a)
				{
					if(!mark[stu2[i].b].flag)
					{
						mark[stu2[i].b].flag=1;
						temp.id=stu2[i].b;
						temp.sum=t.sum+stu2[i].l;
						Q.push(temp);
					}
				}
				else
					break;
			}
		}
	}
}
int main()
{
	int T,a,b,l,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(i=1;i<=N-1;i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			stu1[i].a=a;stu1[i].b=b;stu1[i].l=l;
			stu2[i].a=b;stu2[i].b=a;stu2[i].l=l;
			mark[i].id=i;
		}
		mark[i].id=i;
		qsort(stu1+1,N-1,sizeof(stu1[0]),cmp);
		qsort(stu2+1,N-1,sizeof(stu2[0]),cmp);
		for(i=1;i<=M;i++)
		{
			scanf("%d%d",&s,&e);
			bfs();
		}
	}
	return 0;
}