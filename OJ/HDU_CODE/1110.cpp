////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 12:37:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1110
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*几何*/
#include <iostream>
#include <cmath>
#define PI 3.14159265358979
int h1,w1,h2,w2;
void swap(int &a,int &b)
{
	int t;
	if(a>b)
	{t=a;a=b;b=t;}
}
int main()
{
	int T;
	double t,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
		swap(h1,w1);swap(h2,w2);
		if(h1>h2&&w1>w2)
		{printf("Escape is possible.\n");continue;}
		if(h1<=h2)
		{printf("Box cannot be dropped.\n");continue;}
		bool ok=false;
		for(c=0;c<=90;c+=0.1)
		{
			t=c*PI/180;//化成弧度
			double x1=(h1-h2*cos(t))*1.0/sin(t);
			double x2=(w1-h2*sin(t))*1.0/cos(t);
			if(x1>w2&&x2>w2)
			{ok=true;break;}
		}
		if(ok) printf("Escape is possible.\n");
		else printf("Box cannot be dropped.\n");
	}
return 0;
}