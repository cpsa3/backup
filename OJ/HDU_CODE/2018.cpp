////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 15:31:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f[55];
main ()
{
	int i,w;
	f[1]=1;f[2]=2;f[3]=3;
	for(i=4;i<55;i++)
		f[i]=f[i-3]+f[i-1];
	while(scanf("%d",&w)!=EOF)
	{
		if(w==0)
			break;
		printf("%d\n",f[w]);
	}
return 0;
}