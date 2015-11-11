////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:07:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MOD 10007
using namespace std;

struct mat
{
    int v[4][4];
};
mat e,ans;
int X,Y,N;
mat matrix_mul(mat p1,mat p2)
{
    mat t;
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            t.v[i][j]=0;
            for(k=0;k<4;k++)
                t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
        }
    }
    return t;
}
mat matrix_mi(mat p,int k)
{
    int i,j;
    mat t;
    memset(t.v,0,sizeof(t.v));
    for(i=0;i<4;i++)
        t.v[i][i]=1;
    while(k)
    {
        if(k&1) t=matrix_mul(t,p);
        k>>=1;
        p=matrix_mul(p,p);
    }
    return t;
}
void Print(mat p)
{
    int i,j;
    printf("----------------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",p.v[i][j]);
        printf("\n");
    }
}
void Build(int x,int y)
{
    memset(e.v,0,sizeof(e.v));
    e.v[0][0]=((x%MOD)*(x%MOD))%MOD;
    e.v[1][0]=((y%MOD)*(y%MOD))%MOD;
    e.v[2][0]=((x%MOD)*(y%MOD)*2)%MOD;
    e.v[0][1]=1;
    e.v[0][2]=x%MOD;
    e.v[0][3]=1;
    e.v[2][2]=y%MOD;
    e.v[3][3]=1;
}
int main()
{
    int i;
    while(scanf("%d%d%d",&N,&X,&Y)!=EOF)
    {
        Build(X,Y);
        //Print(e);
        ans=matrix_mi(e,N);
        //Print(ans);
        int res=0;
        for(i=0;i<4;i++)
            res=(res+ans.v[i][3])%MOD;
        printf("%d\n",res);
    }
return 0;
}