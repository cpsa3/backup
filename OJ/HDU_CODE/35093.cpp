////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-05 15:56:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3509
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:564KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct mat
{
	__int64 v[55][55];
};
int f1,f2,a,b,K,N,MOD;
__int64 s1;
mat E,C,A;//E存转换矩阵，C存二项式
__int64 mypow(__int64 a,__int64 n)
{
	if(!n)
		return 1;
	__int64 ans=1;
	while(n)
	{
		if(n&1)
			ans=(ans*a)%MOD;
		n>>=1;
		a=a*a%MOD;
	}
	return ans;
}
mat matrix_mul(mat p1,mat p2)//矩阵相乘
{
    int i,j,k;
    mat t;
    for(i=0;i<=K+1;i++)
        for(j=0;j<=K+1;j++)
        {
            t.v[i][j]=0;
            for(k=0;k<=K+1;k++)
                t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
        }
        return t;
}
/*mat matrix_mi(mat p1,int k)//矩阵求幂(用递归做会Runtime Error(STACK_OVERFLOW))
{
    if(k==1)
        return p1;
    if(k&1)
        return matrix_mul(matrix_mi(p1,k-1),p1);
    else
    {
        //mat t=matrix_mi(p1,k>>1);
        return matrix_mul(matrix_mi(p1,k>>1),matrix_mi(p1,k>>1));
    }
}*/
mat matrix_mi(mat p1,int k)//矩阵求幂
{
	mat ans=p1;
	k--;
	while(k)
	{
		if(k&1)
			ans=matrix_mul(ans,p1);
		k>>=1;
		p1=matrix_mul(p1,p1);
	}
	return ans;
}
void init()
{
	int i,j;
	for(i=0;i<=K;i++)
		C.v[i][i]=C.v[i][0]=1;
	for(i=2;i<=K;i++)//运用二项式定理
		for(j=1;j<i;j++)
			C.v[i][j]=(C.v[i-1][j]+C.v[i-1][j-1])%MOD;
		memset(E.v,0,sizeof(E.v));
		E.v[0][0]=E.v[1][0]=1;
		for(i=1;i<=K+1;i++)
		{
			for(j=1;j<=K+2-i;j++)
				E.v[i][j]=C.v[K-j+1][i-1]*mypow(a,K-i-j+2)%MOD*mypow(b,i-1)%MOD;//相乘时也要%MOD，不然会wa！！！！
		}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d",&f1,&f2,&a,&b,&K,&N,&MOD);
		s1=mypow(f1,K)%MOD;
		if(N==1) 
		{printf("%I64d\n",s1);continue;}
		init();
		A=matrix_mi(E,N-1);
		__int64 ans[55];
		ans[0]=s1;
		for(i=1;i<=K+1;i++)
			ans[i]=mypow(f2,K-i+1)%MOD*mypow(f1,i-1)%MOD;//相乘时也要%MOD，不然会wa！！！！

		__int64 ANS=0;
		for(i=0;i<=K+1;i++)
			ANS=(ANS+ans[i]*A.v[i][0])%MOD;
		printf("%I64d\n",ANS%MOD);
	}
return 0;
}
