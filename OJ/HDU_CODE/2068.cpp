////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-07 23:02:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2068
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[14];
double C(int n,int m)
{
    int i,j;
	if(m==0)
		return 1;
    double s=1;
    for(i=1,j=n;i<=m;i++,j--)
        s=s*j*1.0/i;
    return s;
}
main ()
{
    int n,i;
    f[0]=0;f[1]=0;f[2]=1;
    for(i=3;i<14;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		__int64 w,sum=1;
		for(i=0;i<=n/2;i++)
		{
			w=C(n,i);
			sum+=w*f[i];
		}
		printf("%I64d\n",sum);
	}
return 0;
}

