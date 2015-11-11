////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 18:04:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
int f(int n)
{
	if((n%4==0&&n%100!=0)||n%400==0)
		return 1;
	return 0;
}

main ()
{
	int t,y,m,d,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		if(f(y)&&!f(y+18)&&m==2&&d==29)
		{printf("-1\n");continue;}
		int s=0;
		if(m>=3)
		{
		for(i=1;i<=18;i++)
		{
			if(f(y+i))
				s+=366;
			else
				s+=365;
		}
		}
		else
			for(i=0;i<18;i++)
		{
			if(f(y+i))
				s+=366;
			else
				s+=365;
		}	
		printf("%d\n",s);
	}
	return 0;
}
