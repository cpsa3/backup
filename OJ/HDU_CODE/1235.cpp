////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:56:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()
{
	int N,i,a[10000],b[10000],k,t;
	t=0;
	for(i=0;i<10000;i++)
		b[i]=0;
	while(scanf("%d",&N)!=EOF)

	{
		
		if(N==0)
			break;
	
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		for(i=0;i<N;i++)
		{
			if(a[i]==k)
				b[t]++;
		
		
		
		}
		t++;
		

	
	}

	for(i=0;i<t;i++)
		printf("%d\n",b[i]);
 
return 0;
}

