////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-12 23:07:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:3000KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int p[100001];//数组的值就是它的上一级；
//当它的上一级是它自己时，表示它就是这个树的根。
int mark[100001],flag;//用来记录该标号是否出现过,flag用来记录形成的图是否成环
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x];
}

void bin(int x,int y)
{
	int a=find_set(x);
	int b=find_set(y);
	if(a!=b)
		p[a]=b;//注意不是x，y
	else//如果有两个相同的根节点说明已经成环
		flag=0;
}

main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==-1&&m==-1)
			break;
		if(n==0)
		{printf("Yes\n");continue;}//重点，注意空地图也为真、、
		//本题为真的条件为只有一个独立集合(无零散小集合)，而唯一的集合可以为空
		for(i=1;i<=100000;i++)
		{
			mark[i]=0;
			p[i]=i;//最初本身就是自己的根
		}
		mark[n]=mark[m]=1;//表示该点已经出现过
		bin(n,m);
		flag=1;//初始化为不成环
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			if(n==0&&m==0)
				break;
			mark[n]=mark[m]=1;
			bin(n,m);
		}
		int w=0;//记录根结点数
		for(i=1;i<=100000;i++)
		{
			if(mark[i]&&p[i]==i)
				w++;
			if(w>1)
			{flag=0;break;}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
return 0;
}