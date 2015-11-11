////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-18 19:41:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int a[27]={0};
int count=0;
void dfs(int k,int s,int n)
{
	int i,j;
	s+=n*k;
	count++;
	for(i=k+1;i<=26;i++)
	{ 
		if(i+s>50) break;
		if(a[i]>0)
		{
			for(j=1;j<=a[i];j++)
			{
				if(s+j*i<=50)
					dfs(i,s,j);
				else break;
				
			}
		}
	}
}
main ()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		count=-1;
		a[0]=0;
		for(i=1;i<=26;i++)
			scanf("%d",&a[i]);
		dfs(0,0,0);
		printf("%d\n",count);
		
	}
	return 0;
	
}





