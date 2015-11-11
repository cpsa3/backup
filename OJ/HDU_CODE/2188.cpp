////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-20 22:54:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n,m,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0)
			printf("Rabbit\n");
		else
			printf("Grass\n");		
	}
return 0;
}