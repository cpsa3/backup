////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:06:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1588
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

struct mat
{
    __int64 v[2][2];
};
mat e,ans,kk,bb,E;
__int64 MOD;
int K,B,N;
mat matrix_mul(mat p1,mat p2)
{
    mat t;
    int i,j,k;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    {
        t.v[i][j]=0;
        for(k=0;k<2;k++)
        t.v[i][j]=(t.v[i][j]+(p1.v[i][k]*p2.v[k][j]))%MOD;
    }
    return t;
}
mat matrix_mi(mat p,int k)
{
    mat t;
    memset(t.v,0,sizeof(t.v));
    t.v[0][0]=t.v[1][1]=1;
    while(k)
    {
        if(k%2) t=matrix_mul(t,p);
        k>>=1;
        p=matrix_mul(p,p); 
    }
    return t;
}
mat he(mat p1,mat p2)
{
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    p1.v[i][j]=(p1.v[i][j]+p2.v[i][j])%MOD;
    return p1;
}
mat matrix_dsum(mat p,int n)
{
    if(n==1) return E;
    if(n%2)
        return he(matrix_dsum(p,n-1),matrix_mi(p,n-1));
    else
        return matrix_mul(matrix_dsum(p,n/2),he(E,matrix_mi(p,n/2)));
}
void Print(mat p)
{
    int i,j;
    printf("------------\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%I64d ",p.v[i][j]);
        printf("\n");
    }
}
int main()
{
    int i,j;
    memset(E.v,0,sizeof(E.v));
    E.v[0][0]=E.v[1][1]=1;
    e.v[1][1]=0;e.v[0][0]=e.v[0][1]=e.v[1][0]=1;
    while(scanf("%d%d%d%I64d",&K,&B,&N,&MOD)!=EOF)
    {   
        bb=matrix_mi(e,B);
        kk=matrix_mi(e,K);
        
        //Print(kk);
        //Print(bb);
        ans=matrix_mul(bb,matrix_dsum(kk,N));
        printf("%I64d\n",ans.v[0][1]);
    }
return 0;
}