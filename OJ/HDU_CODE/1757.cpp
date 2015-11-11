////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-03 17:42:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1757
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAXN=11;
const int N=10;
int MOD,K,a[11],x[11];
int yuan[11][11];
int temp[11][11];
int ans[11];
void matrix_mul(int c[MAXN][MAXN],int n)//计算原始方阵a[i][j]的n次幂，保存在c[i][j]中
{
	int i,j,k;
	if(n==1)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				c[i][j]=yuan[i][j];
			return;
	}
	int t[MAXN][MAXN];
	matrix_mul(t,n>>1);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			c[i][j]=0;
			for(k=0;k<N;k++)
				c[i][j]=(c[i][j]+t[i][k]*t[k][j])%MOD;
		}
		if(n%2==1)
		{
			for(i=0;i<N;i++)//临时储存
				for(j=0;j<N;j++)
					t[i][j]=c[i][j];
				for(i=0;i<N;i++)
					for(j=0;j<N;j++)
					{
						c[i][j]=0;
						for(k=0;k<N;k++)
							c[i][j]=(c[i][j]+t[i][k]*yuan[k][j])%MOD;
					}
		}
}
void mul1(int a[MAXN],int b[MAXN][MAXN],int c[MAXN],int n)
{
	int i,k;
	for(i=0;i<n;i++)
	{
		c[i]=0;
		for(k=0;k<n;k++)
			c[i]=(c[i]+a[k]*b[k][i])%MOD;
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&K,&MOD)!=EOF)
	{
		for(i=0;i<10;i++)
			scanf("%d",&a[i]);
		for(i=0;i<10;i++)
			x[i]=i;
		memset(yuan,0,sizeof(yuan));
		for(i=0;i<10;i++)
			yuan[i][9]=a[9-i];//注意
		for(i=1;i<10;i++)
			yuan[i][i-1]=1;
		/*
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
				printf("%d ",yuan[i][j]);
			printf("\n");
		
		}
		*/
		matrix_mul(temp,K-9);
		mul1(x,temp,ans,10);//注意
		printf("%d\n",ans[9]);
	}
return 0;
}
/*转换矩阵
0 0 0 0 0 0 0 0 0 a(9)                               
1 0 0 0 0 0 0 0 0 a(8)                                
0 1 0 0 0 0 0 0 0 a(7)                                
0 0 1 0 0 0 0 0 0 a(6)                                
0 0 0 1 0 0 0 0 0 a(5)                                
0 0 0 0 1 0 0 0 0 a(4)                               
0 0 0 0 0 1 0 0 0 a(3)                               
0 0 0 0 0 0 1 0 0 a(2)                               
0 0 0 0 0 0 0 1 0 a(1)                                
0 0 0 0 0 0 0 0 1 a(0)  
*/