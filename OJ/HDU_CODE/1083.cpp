////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-22 12:35:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <iostream>
bool map[105][305];//邻接矩阵 true代表有边相连
bool flag[305];//记录V2中的每个点是否被搜索过
int result[305];//记录V2中的点匹配的点的编号
int T,P,N,ans;
void init()
{
	int i,j,x,n;
	ans=0;
	memset(map,false,sizeof(map));
	memset(result,0,sizeof(result));
	scanf("%d%d",&P,&N);
	for(i=1;i<=P;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			map[i][x]=true;
		}
	}
}
bool Find(int a)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(map[a][i]&&!flag[i])//如果节点i与a相邻并且未被查找过
		{
			flag[i]=true;//标记i为已查找过
			if(result[i]==0||Find(result[i]))//如果i未在前一个匹配M中||//i在匹配M中,但是从与i相邻的节点出发可以有增广路
			{
				result[i]=a;//记录查找成功记录
				return true;//返回查找成功 
			}
		}
	}
	return false;
}
int main()
{
	int i;
	scanf("%d",&T);
	while(T--)
	{
		init();
		for(i=1;i<=P;i++)
		{
			memset(flag,false,sizeof(flag));//清空上次搜索时的标记 
			if(Find(i)) ans++;//从节点i尝试扩展
		}
		if(ans==P)
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;
}