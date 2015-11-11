////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-14 13:13:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64  f[121][121];
main ()
{
	int i,j,n;
	for(i=1;i<=120;i++)
	{
		f[0][i]=1;//就是7只分成7的情况
		//f[i][0]=0;
	}
	for(i=1;i<=120;i++)
		for(j=1;j<=120;j++)
		{
			f[i][j]=f[i][j-1];
			if(i>=j) f[i][j]+=f[i-j][j];
		}
		while(scanf("%d",&n)!=EOF)
			printf("%I64d\n",f[n][n]);
return 0;
}