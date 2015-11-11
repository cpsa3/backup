////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-04 22:03:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n,k,a,b,c[9],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int w[9]={0},count=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&a,&b);
			w[a]=b;
		}
		for(c[8]=0;c[8]<=w[8]&&c[8]*8<=n;c[8]++)
		for(c[7]=0;c[7]<=w[7]&&c[7]*7+c[8]*8<=n;c[7]++)
		for(c[6]=0;c[6]<=w[6]&&c[6]*6+c[7]*7+c[8]*8<=n;c[6]++)
		for(c[5]=0;c[5]<=w[5]&&c[5]*5+c[6]*6+c[7]*7+c[8]*8<=n;c[5]++)
		for(c[4]=0;c[4]<=w[4]&&c[4]*4+c[5]*5+c[6]*6+c[7]*7+c[8]*8<=n;c[4]++)
		for(c[3]=0;c[3]<=w[3]&&c[3]*3+c[4]*4+c[5]*5+c[6]*6+c[7]*7+c[8]*8<=n;c[3]++)
		for(c[2]=0;c[2]<=w[2]&&c[2]*2+c[3]*3+c[4]*4+c[5]*5+c[6]*6+c[7]*7+c[8]*8<=n;c[2]++)
		{
			c[1]=n-(c[2]*2+c[3]*3+c[4]*4+c[5]*5+c[6]*6+c[7]*7+c[8]*8);
			if(c[1]<=w[1])
			count++;
		}
		printf("%d\n",count);
	}
return 0;
}