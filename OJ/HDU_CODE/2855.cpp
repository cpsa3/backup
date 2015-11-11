////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-12-04 13:10:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2855
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
//f(n)=3*f(n-1)-f(n-2);
//f(0)=0;f(1)=1;
//×ª»»¾ØÕó:[0,-1,1,3];
#include <iostream>
struct mat
{
	__int64 v[2][2];
};
int N,MOD;
mat e;//×ª»»¾ØÕó
mat matrix_mul(mat p1,mat p2)//¾ØÕóÏà³Ë
{
	int i,j,k;
	mat t;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			t.v[i][j]=0;
			for(k=0;k<2;k++)
				t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
		}
		return t;
}
mat matrix_mi(mat p1,int k)//¾ØÕóÇóÃÝ
{
	if(k==1)
		return p1;
	if(k&1)
		return matrix_mul(matrix_mi(p1,k-1),p1);
	else
	{
		mat t=matrix_mi(p1,k>>1);
		return matrix_mul(t,t);
	}
}
int main()
{
	int T;
	e.v[0][0]=0;
	e.v[0][1]=-1;
	e.v[1][0]=1;
	e.v[1][1]=3;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%d",&N,&MOD);
		if(!N) {printf("0\n");continue;}
		if(N==1) {printf("%d\n",1%MOD);continue;}
		mat ans=matrix_mi(e,N);
		if(ans.v[1][0]<0)
			ans.v[1][0]+=MOD;
		printf("%d\n",ans.v[1][0]%MOD);
	}
return 0;
}