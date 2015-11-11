////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 19:19:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int w[51][6]={0};
		double a[51]={0},b[6]={0};
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&w[i][j]);
				a[i]+=w[i][j];
			}
			a[i]/=m;
		}
		for(j=1;j<=m;j++)
		{
			for(i=1;i<=n;i++)
			{
				b[j]+=w[i][j];
			}
			b[j]/=n;
		}

		int s=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				if(w[i][j]<b[j])
					break;
				if(j==m+1)
					s++;
		}

		for(i=1;i<n;i++)
			printf("%.2lf ",a[i]);
		printf("%.2lf\n",a[i]);
		for(i=1;i<m;i++)
			printf("%.2lf ",b[i]);
		printf("%.2lf\n",b[i]);
		printf("%d\n\n",s);
	}
return 0;
}