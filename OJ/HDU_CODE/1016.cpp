////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:03:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
#define max 22
int path[max];
bool sign[2*max]={true};
bool used[max]={false};
int t,n;
void DSF(int v,int num)
{
	int i;
	if(n==num&&sign[v+1])
	{
		printf("1 ");
		for(i=2;i<n;i++)
			printf("%d ",path[i]);
		printf("%d\n",path[i]);
		
	}
	else
		
		for(i=2;i<=n;i++)
		{
			if(!used[i]&&sign[v+i])
			{
				used[i]=true;
				path[t++]=i;
				DSF(i,num+1);
				used[i]=false;
				t--;
				
			}
		}	
}
main ()
{
	int z=1,i,j,num;
	for(i=1;i<=40;i++)
		sign[i]=true;
	for(i=2;i<=40;i++)
	{
		if(sign[i])
			for(j=2;i*j<=40;j++)
				sign[i*j]=false;
	}
	while(scanf("%d",&n)!=EOF)
	{
		num=1;t=2;
		used[1]=true;
		path[1]=1;
		printf("Case %d:\n",z);
		z++;
		if(n%2==0)
		{	DSF(1,1);
		printf("\n");
		}
		else
			printf("\n");	
	}	
	return 0;
}