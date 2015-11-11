////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 11:42:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1059
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*多重背包*/
#include <iostream>
int v[7];
bool f[60010];
int main()
{
	int i,cas=1,sum,j,k;
	while(scanf("%d%d%d%d%d%d",&v[1],&v[2],&v[3],&v[4],&v[5],&v[6])!=EOF)
	{
		if(v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0&&v[5]==0&&v[6]==0) break;
		printf("Collection #%d:\n",cas++);
		sum=0;
		for(i=1;i<=6;i++)
			sum+=i*v[i];
		if(sum&1)
		{printf("Can't be divided.\n\n");continue;}
		for(i=1;i<=sum/2;i++)
			f[i]=false;
		f[0]=true;
		for(i=1;i<=6&&!f[sum/2];i++)
		{
			for(j=sum/2-i;j>=0&&!f[sum/2];j--)
			{
				if(!f[j]) continue;
				for(k=1;k<=v[i]&&j+k*i<=sum/2&&!f[sum/2]&&!f[j+k*i];k++)//注意这个剪枝!f[j+k*i]
					f[j+k*i]=true;
			}
		}
		if(f[sum/2])
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
return 0;
}