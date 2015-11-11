////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-12 14:44:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1287
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
int mark[26];
int main()
{
	int i,a[10000],n,flag,j,w;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mark,0,sizeof(mark));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=25;j++)
			{
				flag=(65+j)^a[i];
				if(flag<65||flag>90)
					mark[j]=1;
			}
			int sum=0;
			for(j=0;j<=25;j++)
			{
				if(mark[j]==0)
				{sum++;w=j;}
				if(sum>1)
					break;
			}
			if(sum==1)
				break;
		}
		for(i=1;i<=n;i++)
			printf("%c",(w+65)^a[i]);
		printf("\n");
	}
return 0;
}