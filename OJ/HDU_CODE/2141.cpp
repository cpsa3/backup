////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-04 14:54:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:2208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int L,N,M,S,X,k;
__int64 A[505],B[505],C[505],sum[260000];
int binary(__int64 x)
{
	int l=0,r=L*N-1,mid;
	if(sum[l]==x||sum[r]==x)
		return 1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(sum[mid]>x)
			r=mid-1;
		else if(sum[mid]<x)
			l=mid+1;
		else
		return 1;
	}	
	return 0;
}
int main()
{
	int cas=1,i,j,k;
	__int64 temp;
	while(scanf("%d%d%d",&L,&N,&M)!=EOF)
	{
		for(i=0;i<L;i++)
			scanf("%I64d",&A[i]);
		for(i=0;i<N;i++)
			scanf("%I64d",&B[i]);
		for(i=0;i<M;i++)
			scanf("%I64d",&C[i]);
		k=0;
		for(i=0;i<L;i++)
			for(j=0;j<N;j++)
			{
				sum[k++]=A[i]+B[j];
			}
			sort(sum,sum+k);
			sort(C,C+M);
			//__int64 min=sum[1]+C[1];
			//__int64 max=sum[L*N]+C[M];
			scanf("%d",&S);
			printf("Case %d:\n",cas++);
			while(S--)
			{
				scanf("%d",&X);
				//if(X>max||X<min)
				//{printf("NO\n");continue;}
				int flag=0;
				for(i=0;i<M;i++)
				{
					temp=X-C[i];
					//if(temp<0)
					//	break;
					flag=binary(temp);
					if(flag)
						break;
				}
				if(flag)
					printf("YES\n");
				else
					printf("NO\n");
			}
	}
	return 0;
}