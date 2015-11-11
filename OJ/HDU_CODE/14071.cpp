////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-27 19:09:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int num,i,j,k;
	while(scanf("%d",&num)!=EOF)
	{
		int x=sqrt((double)(num*1.0)/3);//最大值的最小可能值
		int flag=0,se;
		for(i=1;i<=x+1;i++)
		{
			for(j=i;j<=sqrt((double)num);j++)//不能写成j<=x
			{
				if((i+j)&1)
				{
					if(num&1)
						se=0;
					else
						se=1;	
				}
				else
				{
					if(num&1)
						se=1;
					else
						se=0;
				}
				if(se==0)
				{
					if(x&1)
						k=x+1;
					else
						k=x;
				}
				else
				{
					if(x&1)
						k=x;
					else
						k=x+1;
				}
				int q=i*i+j*j;
				for(;k<=sqrt((double)num);k=k+2)
				{
					if(k*k+q==num)
					{printf("%d %d %d\n",i,j,k);flag=1;break;}
					if(k*k+q>num)
						break;
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
	}
	return 0;
}