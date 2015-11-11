////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 16:21:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,w,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int a[101]={0};
		int s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&w);
			while(w>=100) {w-=100;a[i]++;}
			while(w>=50) {w-=50;a[i]++;}
			while(w>=10) {w-=10;a[i]++;}
			while(w>=5) {w-=5;a[i]++;}
			while(w>=2) {w-=2;a[i]++;}
			while(w>=1) {w-=1;a[i]++;}
			s+=a[i];
		}
		printf("%d\n",s);
	}
return 0;
}