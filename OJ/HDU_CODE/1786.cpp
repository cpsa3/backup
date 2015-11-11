////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-30 13:48:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1786
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*递归*/
#include <iostream>
#include <stdlib.h>
int w[12];
int N,M;
int cmp(const void *p1,const void *p2)
{return *(int *)p2-*(int *)p1;}
int min(int a,int b)
{return a<b?a:b;}
void get_w()//输入w[i]
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&w[i]);
	qsort(w+1,N,sizeof(int),cmp);
}
int get_ans(int s,int k)//返回s的容量从第k件物品开始放最少需要几件
{
	int i,ans=99999999,t;
	if(s%w[k]==0)//若能整除直接返回
		return s/w[k];
	if(k==N)//没有放满且后面没有物品就返回-1
		return -1;
	int l=min(s/w[k],w[k+1]-1);//遍历的上限
	//比如说接下来的数是w[k+1]，我只要考虑w[k]最多少放(w[k+1]-1)次即可
	for(i=0;i<=l;i++)//遍历少放w[k]的次数0至w[k+1]-1
	{
		t=get_ans(s%w[k]+i*w[k],k+1);
		if(t==-1)//不能放满
			continue;
		ans=min(t+s/w[k]-i,ans);
	}
return ans;
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)
			break;
		get_w();
		printf("%d\n",3*get_ans(M,1));
	}
	return 0;
}