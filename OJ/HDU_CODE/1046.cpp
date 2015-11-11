////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-21 11:41:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1046
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*’“πÊ¬…*/
#include <iostream>
int main()
{
	int T,n,m,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",cas++);
		int w=m*n;
		if(w&1)
			printf("%d.41\n\n",w);
		else 
			printf("%d.00\n\n",w);
	}
return 0;
}