////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-04 00:08:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1588
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct mat
{
	__int64 map[2][2];
};
int MOD,K,B,N;
mat matrix_mul(mat p1,mat p2)//矩阵乘积
{
	mat t;
	int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			t.map[i][j]=0;
			for(k=0;k<2;k++)
				t.map[i][j]=(t.map[i][j]+p1.map[i][k]*p2.map[k][j])%MOD;
		}
		return t;
}
mat matrix_sum(mat p1,mat p2)//矩阵和
{
	mat t;
	int i,j;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			t.map[i][j]=0;
			t.map[i][j]=(p1.map[i][j]+p2.map[i][j])%MOD;//注意
		}
		return t;
} 
mat matrix_mi(mat p1,int k)//矩阵幂
{
	if(k==1)
		return p1;
	if(k&1)
		return matrix_mul(matrix_mi(p1,k-1),p1);
	else
	{
		mat t=matrix_mi(p1,k>>1);//注意
		return matrix_mul(t,t);
	}
}
mat matrix_dsum(mat p1,int k)//矩阵等比求和(二分)
{
	if(k==1)
		return p1;
	if(k&1)
		return matrix_sum(matrix_dsum(p1,k-1),matrix_mi(p1,k));
	else
	{
		mat e1,e2;
		e1=matrix_dsum(p1,k>>1);
		e2=matrix_mul(matrix_mi(p1,k>>1),e1);
		return matrix_sum(e1,e2);
	}
}
mat e;
int main()
{
	int i,j;
	e.map[0][0]=0;
	e.map[0][1]=1;
	e.map[1][0]=1;
	e.map[1][1]=1;
	while(scanf("%d%d%d%d",&K,&B,&N,&MOD)!=EOF)
	{
		mat s1,s2,s3;
		s1=matrix_mi(e,K);//求e^K
		/*
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				printf("%d ",s1.map[i][j]);
			printf("\n");
		
		}
		*/
		s2=matrix_dsum(s1,N-1);//求s1等比序列的前N-1项和(s1^1+s1^2+```+s1^(N-1))
		if(B)
		{
			s3=matrix_mi(e,B);//求e^B
			s2=matrix_mul(s2,s3);
			s2=matrix_sum(s2,s3);
		}
		printf("%I64d\n",s2.map[1][0]);
	}
	return 0;
}
