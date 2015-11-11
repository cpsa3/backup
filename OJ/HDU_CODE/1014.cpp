////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 11:19:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
int MIN(int a,int b)
{
	return a<b?a:b;
}

int f(int n,int m)
{
	int i,s=MIN(n,m);
	for(i=s;i>=1;i--)
		if(n%i==0&&m%i==0)
			break;
		return i;
}

main ()
{
	int step,mod;
	while(scanf("%d%d",&step,&mod)!=EOF)
	{
		printf("%10d%10d    ",step,mod);
		if(f(step,mod)==1)
			printf("Good Choice\n\n");
		else
			printf("Bad Choice\n\n");
	}
return 0;
}