////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 22:25:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:10016KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define M 10000000
bool ispri[M];
void getpri()
{
	int i , j ;
	for (i = 2 ;i < M ; i ++)
	{
		ispri[i] = 1 ;
	}
	for( i = 2 ; i <=M/2 ; i++ )
	{
		if ( ispri[i] == 0 )
			continue;
		int mul = i ;
		int temp = (M+1)/i ;
		while ( temp >= mul )
		{	
			int temp2 = M / mul ;
			for ( j = i+1 ; j <= temp2 ; j++ )
			{
				if ( ispri[j] )
				{
					ispri[mul*j] = 0;
				}
			}
			mul *= i;
			ispri[mul] = 0;
		}
		int temp2 = (M+1) / mul ;
		for ( j = i+1 ; j <= temp2 ; j++ )
		{
			if ( ispri[j] )
			{
				ispri[mul*j] = 0;
			}
		}
	}
}

bool isPrime(int x)
{
	if(x==1) return false;
	if(x==2||x==3) return true;
	if(x%2==0) return false;
	int i;
	for(i=3;i<=sqrt((double)x);i+=2)
		if(x%i==0) return false;
		return true;
} 
int main()
{
	int i,N,x;
	getpri();
	while(scanf("%d",&N)!=EOF)
	{
		int ans=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			if(x<M-1) ans+=ispri[x];
			else
			if(isPrime(x)) ans++; 
		} 
		printf("%d\n",ans);
	}
return 0;
}