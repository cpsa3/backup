////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-08 17:47:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3835
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*Ã¶¾Ù*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;
int N;
int main()
{
	int i,ans;
	while(scanf("%d",&N)!=EOF)
	{
		int len=sqrt((double)N)+1;
		ans=0;
		if(N==1) {printf("4\n");continue;}
		//printf("*%d\n",len);
		for(i=0;i<=len;i++)
		{
			int t=N-i*i;
			int w=sqrt(1.0*t);
			if(w*w+i*i==N)
			{
				if(i==0||w==0) ans+=2;
				else ans+=4;
			}
		}
		printf("%d\n",ans);
	}
return 0;
}	