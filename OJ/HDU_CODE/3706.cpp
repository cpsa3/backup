////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-30 20:05:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3706
////Problem Title: 
////Run result: Accept
////Run time:1203MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int n,A,B;
__int64 S(int A,int k)
{
	if(k==0)
		return 1;
	if(k==1)
		return A%B;
	else
	{
		if(k%2==0)
			return ((S(A,k/2)%B)*(S(A,k/2)%B))%B;
		else
			return ((A%B)*(S(A,k/2)%B)*(S(A,k/2)%B))%B;
	}
}
main ()
{
	int i,j;
	__int64 ans;
	while(scanf("%d%d%d",&n,&A,&B)!=EOF)
	{
		ans=1;
		__int64 min1=99999999;
		__int64 w=1;
		__int64 temp=1;
		for(i=1;i<=n;i++)
		{
			temp=temp*A%B;
			if(i<=A+1)
			{
				if(temp<=min1)
				{min1=temp;w=i;}
			}
			else
			{
				if(temp<=min1)
				{min1=temp;w=i;}
				else
				{
					if(w==i-A)
					{
						int temp1=S(A,w+1);
						int temp2=temp1;
						w=i-A+1;
						for(j=1;j<=A-1;j++)
						{
							temp1=temp1*A%B;
							if(temp2>temp1)
							{temp2=temp1;w=i-A+1+j;}
						}
						min1=temp2;
					}
				}
			}
			ans=ans*min1%B;	
		}
		printf("%I64d\n",ans);
	}
	return 0;
}