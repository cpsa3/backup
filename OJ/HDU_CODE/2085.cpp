////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 22:15:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 f[34][3];
main ()
{
	int i,n;
	f[0][1]=1;f[0][2]=0;
	f[1][1]=3;f[1][2]=1;
	for(i=2;i<=33;i++)
	{
		f[i][1]=f[i-1][1]*3+f[i-1][2]*2;
		f[i][2]=f[i-1][1]+f[i-1][2];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		printf("%I64d, %I64d\n",f[n][1],f[n][2]);
	}
return 0;
}