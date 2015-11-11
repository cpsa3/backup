////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-28 15:01:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[101],b[101];
int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,m,k,s,i,j,w,K;
	while(scanf("%d%d%d%d",&n,&m,&K,&s)!=EOF)
	{
		for(i=1;i<=K;i++)
			scanf("%d%d",&a[i],&b[i]);
		int f[101][101]={0};
		//f[0][0]=1;
		for(i=1;i<=m;i++)
		{
			for(k=1;k<=s;k++)
				for(j=1;j<=K;j++)
					if(i>=b[j])f[i][k]=max(f[i][k],f[i-b[j]][k-1]+a[j]);
					if(f[i][s]>=n)
						break;
		}
		printf("%d\n",m-i);
	}
	return 0;
}
