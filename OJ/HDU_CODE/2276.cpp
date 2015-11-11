////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-12-03 16:13:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2276
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 102
int yuan[MAXN][MAXN];
int temp[MAXN][MAXN];
int w[MAXN];
int ans[MAXN];
int K,N;
char s[MAXN];
struct px
{
	int matrix[MAXN][MAXN];
}M[33];
int B[33];
int binary(int n)
{
	int i;
		for(i=1;n;i++)
		{
			B[i]=n&1;
			n>>=1;
		}
		return i-1;
}
void mulx(int a[MAXN][MAXN],int b[MAXN][MAXN])//Ëã¾ØÕóµÄ¶þ´ÎÃÝ
{
	int i,j,k;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			b[i][j]=0;
			for(k=1;k<=N;k++)
				b[i][j]^=a[i][k]&a[k][j];
		}
}
/*void mul(int a[MAXN][MAXN],int b[MAXN][MAXN],int c[MAXN][MAXN],int x1,int x2,int x3)
{
	int i,j,k;
	for(i=1;i<=x1;i++)
		for(j=1;j<=x3;j++)
		{
			c[i][j]=0;
			for(k=1;k<=x2;k++)
				c[i][j]^=a[i][k]&b[k][j];
		}
}*/
void mul(int a[MAXN][MAXN],int b[MAXN][MAXN],int c[MAXN][MAXN],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			c[i][j]=0;
			for(k=1;k<=n;k++)
				c[i][j]^=a[i][k]&b[k][j];
		}
}
void mul1(int a[MAXN],int b[MAXN][MAXN],int c[MAXN],int n)
{
	int i,k;
	for(i=1;i<=n;i++)
	{
		c[i]=0;
		for(k=1;k<=n;k++)
			c[i]^=a[k]&b[k][i];
	}
}
int main()
{
	int i,j;
	while(scanf("%d",&K)!=EOF)
	{
		scanf("%s",s);
		N=strlen(s);
		for(i=1;i<=N;i++)
			w[i]=s[i-1]-'0';
		memset(yuan,0,sizeof(yuan));
		for(i=1;i<=N;i++)
			yuan[i][i]=1;
		memset(M[1].matrix,0,sizeof(M[1].matrix));
		for(i=1;i<=N-1;i++)
			M[1].matrix[i][i]=M[1].matrix[i][i+1]=1;
		M[1].matrix[N][1]=M[1].matrix[N][N]=1;
		for(i=1;i<=30;i++)
			mulx(M[i].matrix,M[i+1].matrix);
		int dd=binary(K);
		int r=1;
		for(i=1;i<=dd;i++)
		{
			if(B[i])
			{
				if(r&1)
					mul(yuan,M[i].matrix,temp,N);
				else
					mul(temp,M[i].matrix,yuan,N);
				r++;
			}
		}
		if(r&1)
			mul1(w,yuan,ans,N);
		else
			mul1(w,temp,ans,N);
		for(i=1;i<=N;i++)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}