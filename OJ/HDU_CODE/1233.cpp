////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-12 15:26:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
using namespace std;
int map[100][100];
int mark[100];
main ()
{
	int n,i,x,y,z,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(mark,0,sizeof(mark));
		for(i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			map[x][y]=map[y][x]=z;
		}
		vector<int>v;
		v.push_back(1);
		mark[1]=1;
		int r=0;
		while(v.size()<n)
		{
			int d,min=99999999;
			for(i=0;i<v.size();i++)
			{
				for(j=1;j<=n;j++)
				{
					if(mark[j]==0&&min>map[j][v[i]])
					{min=map[j][v[i]];d=j;}
				}
			}
			v.push_back(d);
			mark[d]=1;
			r+=min;
		}
		printf("%d\n",r);
	}
return 0;
}