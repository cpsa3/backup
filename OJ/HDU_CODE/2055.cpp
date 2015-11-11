////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-27 22:15:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(char x)
{
	if(x>='A'&&x<='Z')
		return x-64;
	if(x>='a'&&x<='z')
		return -(x-96);		
}

main ()
{
	int n,y;
	char x;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		scanf("%c",&x);
		getchar();
		scanf("%d",&y);
		getchar();
		printf("%d\n",f(x)+y);
	}
	
return 0;
}