////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 17:55:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[21];
double C(int n,int m)
{
	int i,j;
	double s=1;
	for(i=1,j=n;i<=m;i++,j--)
		s=s*j*1.0/i;
	return s;
}
main ()
{
	int t,n,m,i;
	f[1]=0;f[2]=1;
	for(i=3;i<=20;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		__int64 w;
		w=(__int64)C(n,m);
		printf("%I64d\n",w*f[m]);
	}
return 0;
}