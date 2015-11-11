////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 17:22:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f1(int n)
{
	int a[5];
	a[1]=n%10;
	a[2]=(n/10)%10;
	a[3]=(n/100)%10;
	a[4]=n/1000;
	return a[1]+a[2]+a[3]+a[4];
}

int f2(int n,int m)
{
	int s=0;
	while(n)
	{
		s+=n%16;
		n/=16;
	}
	if(s==m) return 1;
	else return 0;
}

int f3(int n,int m)
{
	int s=0;
	while(n)
	{
		s+=n%12;
		n/=12;
	}
	if(s==m) return 1;
	else return 0;
}

main ()
{
	int w;
	while(scanf("%d",&w)!=EOF)
	{
		if(w==0) break;
		int m;
		m=f1(w);
		if(f2(w,m)&&f3(w,m))
			printf("%d is a Sky Number.\n",w);
		else 
			printf("%d is not a Sky Number.\n",w);
	}
return 0;
}