////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-24 00:15:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1757
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

struct mat
{
	int v[10][10];
};
mat e,ans;
int N;
int MOD;

mat matrix_mul(mat p1,mat p2)//æÿ’Ûœ‡≥À
{
	int i,j,k;
	mat t;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			t.v[i][j]=0;
			for(k=0;k<10;k++)
				t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
		}
		return t;
}

mat matrix_mi(mat p,int k)//æÿ’ÛøÏÀŸ√›
{
	mat t;
	memset(t.v,0,sizeof(t.v));
	for(int i=0;i<10;i++) t.v[i][i]=1;
	//if(k==1) return p;
	while(k)
	{
		if(k&1)
			t=matrix_mul(t,p);
		k>>=1;
		p=matrix_mul(p,p);
	}
	return t;
}

int main()
{
	int i,j;
	while(scanf("%d%d",&N,&MOD)!=EOF)
	{
		memset(e.v,0,sizeof(e.v));
		for(i=0;i<10;i++)
			scanf("%d",&e.v[i][0]);
		for(i=0;i<9;i++)
			e.v[i][i+1]=1;
		if(N<10) 
		{
			printf("%d\n",N);
			continue;
		}
		N-=9;
		ans=matrix_mi(e,N);
		int res=0;
		for(i=0;i<9;i++)
		{
			res=res+ans.v[i][0]*(9-i);
			res=res%MOD;
		}	
		printf("%d\n",res);
	}
	return 0;
}

