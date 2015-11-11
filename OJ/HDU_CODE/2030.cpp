////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-09-26 14:26:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	char a[200];
	int t,i;
	scanf("%d\n",&t);
	while(t--)
	{
		gets(a);
		int s=0;
		for(i=0;i<strlen(a)-1;i++)
		{
			if(a[i]<0&&a[i+1]<0)
			{s++;i++;}
		}
		printf("%d\n",s);
	}
return 0;
}
//连续两个字符的ASICC小于0则是一个汉字