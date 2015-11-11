////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-21 11:43:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*Ì°ÐÄ*/
#include <iostream>
int a[405];
int get_index(int x)
{
	if(x%2)
		return x/2+1;
	return x/2;
}
void swap(int &a,int &b)
{
	if(a>b)
	{int t=a;a=b;b=t;} 
}
int main()
{
	int T,i,j,N,s,e;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(a,0,sizeof(a));
		int ans=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&s,&e);
			swap(s,e);
			s=get_index(s);e=get_index(e);
			for(j=s;j<=e;j++)
			{
				a[j]++;
				if(a[j]>ans)
					ans=a[j];
			}
		}
		printf("%d\n",ans*10);
	}
return 0;
}