////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-10 16:34:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3889
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:468KB
//////////////////System Comment End//////////////////
/*Ä£ÄâÌâ*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 20005
using namespace std;
int P,N;
double SD,Mx,My,Mp;
double num[MAXN],X[MAXN],Y[MAXN];
double get_val(double num[],int n)
{
	int i;
	double val,sum=0;
	for(i=1;i<=n;i++)
		sum+=num[i];
	return sum*1.0/n;
}
double get_SD(double num[],int n,double val,int flag)
{
	int i;
	double w=0;
	for(i=1;i<=n;i++)
		w=w+(num[i]-val)*(num[i]-val);
	double res=sqrt(w*1.0/(n-flag));
	return res;
}
void Solve()
{
	int i;
	if(P==1)
	{
		for(i=1;i<=N;i++)
			scanf("%lf",&num[i]);
		Mx=get_val(num,N);
		SD=get_SD(num,N,Mx,0);

		for(i=1;i<N;i++)
			printf("%.2lf ",(num[i]-Mx)*1.0/SD);
		printf("%.2lf\n",(num[i]-Mx)*1.0/SD);
	}
	else if(P==2)
	{
		scanf("%lf",&Mp);
		for(i=1;i<=N;i++)
			scanf("%lf",&num[i]);
		Mx=get_val(num,N);
		SD=get_SD(num,N,Mx,1);
		double SE=SD/(sqrt(1.0*N));

		printf("%.2lf\n",(Mx-Mp)*1.0/SE);
	}
	else 
	{
		for(i=1;i<=N;i++)
			scanf("%lf",&X[i]);
		for(i=1;i<=N;i++)
			scanf("%lf",&Y[i]);

		Mx=get_val(X,N);
		My=get_val(Y,N);
		double SDx=get_SD(X,N,Mx,0);
		double SDy=get_SD(Y,N,My,0);

		double r=0;
		for(i=1;i<=N;i++)
		{
			r=r+(X[i]-Mx)*(Y[i]-My);
		}
		r=r/(N*SDx*SDy);
		if(P==3)
			printf("%.2lf\n",r);
		else
		{
			double b=r*SDy/SDx;
			double a=My-b*Mx;
			printf("%.2lf %.2lf\n",a,b);
		}
	}
}
int main()
{
	while(scanf("%d%d",&P,&N)!=EOF)
	{
		//if(N==0) break;
		Solve();
	}
return 0;
}