////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-15 13:48:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:812MS
////Run memory:992KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[100005],b[100005];
main ()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(n<0)
		{printf("-");n=-n;}
		if(n==1)
		{printf("1\n");continue;}
		int temp=1,c=0;
		b[temp]=1;
		while(temp)
		{
			temp*=10;
			a[c++]=temp/n;
			temp%=n;
			if(b[temp])
				break;
			b[temp]=1;
		}
		printf("0.");
		for(i=0;i<c;i++)
			printf("%d",a[i]);
		printf("\n");
	}
return 0;
}