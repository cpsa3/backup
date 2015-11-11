////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-07 19:22:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[36][36];
main ()
{
	int i,n,k=1,j;
	f[0][0]=0;
	//for(i=1;i<=35;i++)
		//f[i][0]=1;
	for(i=1;i<=35;i++)
	{
		f[i][0]=1;
		for(j=1;j<i;j++)
			f[i][j]=f[i][j-1]+f[i-1][j];
		f[i][i]=f[i][j-1];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		printf("%d %d %I64d\n",k++,n,2*f[n][n]);
	}
return 0;
}