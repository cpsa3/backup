////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-05 15:40:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3509
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long f1,f2,a,b,K,N,MOD;

long long C[60][60],A[60][60];

long long apow(long long a,long long n)
{
    long long ans = 1;
    while(n)
    {
        if(n&1)ans=(ans*a)%MOD;
        n>>=1;
        a=a*a%MOD;
    }
    return ans;
}
void init()
{
    for(int i=0;i<=K;i++)
        C[i][i]=C[i][0]=1;
    for(int i=2;i<=K;i++)
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    memset(A,0,sizeof(A));
    //A[][]
    for(int i=0;i<=K;i++)
        A[i][K+1]=C[K][i]*apow(a,K-i)%MOD*apow(b,i)%MOD;//乘法时也要%MOD，不然会wa！！！！
    A[K+1][K+1]=1;
    for(int j=0;j<=K;j++)
        for(int i=0;i<=K-j;i++)
            A[i][j]=C[K-j][i]*apow(a,K-j-i)%MOD*apow(b,i)%MOD;//A[i,j] = C(K-j,i)*a^(K-j-i)*b^i
}
void mul(long long A[][60],long long B[][60])//A=A*B
{
    long long R[60][60]={0};
    for(int k=0;k<=K+1;k++)
        for(int i=0;i<=K+1;i++)
            if(A[i][k])
                for(int j=0;j<=K+1;j++)
                    R[i][j]=(R[i][j]+A[i][k]*B[k][j])%MOD;
    for(int i=0;i<=K+1;i++)
        for(int j=0;j<=K+1;j++)
            A[i][j]=R[i][j];
}
void mpow(long long R[][60],long long n)
{
    if(n==1)
    {
        for(int i=0;i<=K+1;i++)
            for(int j=0;j<=K+1;j++)
                R[i][j]=A[i][j];
        return;
    }
    mpow(R,n/2);
    mul(R,R);
    if(n&1)mul(R,A);
}
int main()
{
    //freopen("in","r",stdin);
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&f1,&f2,&a,&b,&K,&N,&MOD);
        if(N==1){printf("%I64d\n",apow(f1,K));continue;}
        long long s2=(apow(f1,K)+apow(f2,K))%MOD;
        if(N==2){printf("%I64d\n",s2);continue;}
        init();
        long long R[60][60];
        mpow(R,N-2);
        long long ans = 0;
        for(int i=0;i<=K;i++)
        {
            ans=(ans+apow(f2,K-i)*apow(f1,i)%MOD*R[i][K+1])%MOD;
        }
        ans=(ans+s2*R[K+1][K+1])%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}