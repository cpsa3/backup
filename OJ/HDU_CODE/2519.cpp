////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 17:19:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
double C(int n,int m)
{
	double s=1;
	int i,j;
	if(m==0||n==m)
		return 1;
	for(i=1,j=n;i<=m;i++,j--)
		s=s*j*1.0/i;
	return s;
}

main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n<m)
			printf("0\n");
		else 
			printf("%.0lf\n",C(n,m));
	}
return 0;
}