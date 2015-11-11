////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-03 20:12:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
	int n,i,sum1,point;
	double s,p,sum,sumscore;
	while(scanf("%d",&n)!=EOF)
	{   
		sumscore=0.0;
		for(i=0,sum1=0,sum=0;i<n;i++)
		{  
			scanf("%lf%lf",&s,&p);
			if(p>=90)
				point=4;
			else if(p>=80)
				point=3;
			else if(p>=70)
				point=2;
			else if(p>=60)
				point=1;
			else if(p>=0)
				point=0;
			else{//p==-1
				sum1++;
				continue;
			}
			sumscore+=s;
			sum+=s*point;
		}
		if(sum1==n||sum==0)//现在是AC的，把里面的“||sum==0”去了就WA了
			printf("-1\n");
		else
			printf("%.2lf\n",sum/sumscore);
	}
}