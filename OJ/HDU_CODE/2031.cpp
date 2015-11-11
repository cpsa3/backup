////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 13:16:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int a[100]={0};
int f(int n,int m)
{
	int i=1;
	while(n)
	{
		a[i]=n%m;
		n/=m;
		i++;
	}
return i-1;
}
main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(a,0,sizeof(a));
		if(n<0) {printf("-");n=-n;}
		int s=f(n,m);
		for(i=s;i>=1;i--)
		{
			if(a[i]==10)
				printf("A");
			else if(a[i]==11)
				printf("B");
			else if(a[i]==12)
				printf("C");
			else if(a[i]==13)
				printf("D");
			else if(a[i]==14)
				printf("E");
			else if(a[i]==15)
				printf("F");
			else printf("%d",a[i]);
		}
		printf("\n");
	}
return 0;
}