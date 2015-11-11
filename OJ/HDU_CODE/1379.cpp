////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 20:16:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1379
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
struct px
{
	char s[105];
	int ni;
	int id;
};
struct px stu[105];
int cmp(const void *p1,const void *p2)
{
	if(((struct px *)p1)->ni!=((struct px *)p2)->ni)
		return ((struct px *)p1)->ni-((struct px *)p2)->ni;
	return ((struct px *)p1)->id-((struct px *)p2)->id;
}
int main() 
{
	int N,i,j,n,m,k;
	scanf("%d",&N);
	int cas=0;
	while(N--)
	{
		scanf("%d%d",&n,&m);
		if(cas)
			printf("\n");
		for(i=0;i<m;i++)
		{
			scanf("%s",stu[i].s);
			stu[i].id=i;
		}
		for(i=0;i<m;i++)
		{
			int ans=0;
			for(j=0;j<n;j++)
			{
				for(k=j+1;k<n;k++)
					if(stu[i].s[j]>stu[i].s[k])
						ans++;
			}
			stu[i].ni=ans;
			//printf("%d ",ans);
		}
		qsort(stu,m,sizeof(stu[0]),cmp);
		for(i=0;i<m;i++)
			puts(stu[i].s);
		//puts("");
		cas=1;
	}
	return 0;
}