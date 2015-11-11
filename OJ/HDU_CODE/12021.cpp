////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-03 20:30:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
 main ()
{
	int n,sum1,N;
	double s,p,t,w,i,j;
	while(cin>>n)
	{
		t=0;
		i=0;
		j=0;
		sum1=0;
		N=n;
		while(n--)
		{
			scanf("%lf%lf",&s,&p);
			if(p==(-1))
			{sum1++;continue;}
			if(p>=90)
				w=4;
			else if(p>=80)
				w=3;
			else if(p>=70)
				w=2;
			else if(p>=60)
				w=1;
			else if(p>=0)
				w=0;
			t=t+s*w;
			i=i+s;
		j++;
		}
		if(t==0||sum1==N)//t=0表示全挂了，sum1=0表示全部缺考
			printf("-1\n");
		else
		printf("%.2lf\n",t/i);
	}
return 0;
}