////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-08 22:54:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*Ä£Äâ*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
int num[100000],cnt;
bool Run(int &n)
{
	int i,nn,w=0,len=0,a[20];
	nn=n;
	while(nn)
	{
		a[len++]=nn%10;
		w=w*10+a[len-1];
		nn/=10;
	}
	bool ok=true;
	for(i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-1-i]) 
		{ok=false;break;}
	}
	num[cnt++]=n;
	if(ok) 
		return true;
	else
	{
		n+=w;
		return false;
	}
}
int main()
{
	int i,N;
	while(scanf("%d",&N)!=EOF)
	{
		cnt=0;
		while(!Run(N));
		printf("%d\n",cnt-1);
		for(i=0;i<cnt-1;i++)
			printf("%d--->",num[i]);
		printf("%d\n",num[i]); 
	}
return 0;
}