////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-07 17:24:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2779
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
struct px
{
int s,e,d;
};
struct px stu[105];
int cmp(const void *p1,const void *p2)
{
	if(((px *)p1)->d!=((px *)p2)->d)
		return ((px *)p1)->d-((px *)p2)->d;
	else if(((px *)p1)->s!=((px *)p2)->s)
		return ((px *)p1)->s-((px *)p2)->s;
	else
		return ((px *)p1)->e-((px *)p2)->e;
}
int map[50];
main ()
{
	int k=1,min,w,n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&stu[i].s,&stu[i].e);
			stu[i].s<<=1;stu[i].e<<=1;
			stu[i].d=stu[i].e-stu[i].s;
		}
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
			for(j=stu[i].s;j<stu[i].e;j++)
				map[j]++;
			int c=0;
		for(i=1;i<=n;i++)
		{
			min=99999999;
			w=0;
			for(j=stu[i].s;j<stu[i].e;j++)
			{
				if(map[j]!=-1&&map[j]<min) 
				{
					min=map[j];
					w=j;
				}
			}
			if(w!=0) c++;
			map[w]=-1;
			for(j=stu[i].s;j<stu[i].e;j++)
			{
				if(map[j]!=-1) 
					map[j]--;
			}
		}
		printf("On day %d Emma can attend as many as %d parties.\n",k++,c);
	}
return 0;
}