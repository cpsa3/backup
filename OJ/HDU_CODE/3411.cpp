////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-11 11:52:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3411
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 P,x1,y1,z1,y2,z2; 
struct mat
{
    __int64 v[2][2];
};
mat e,ans;
__int64 mod_exp(__int64 a,__int64 b,__int64 c)
{
    if (a>c)
        a=(a+c)%c;
    __int64 i,d=1,b2[64];
    for(i=0;i<64;i++)
    {
        b2[i]=(b+2)%2;
        b>>=1;
        if(b==0)
            break;
    }
    for(;i>=0;i--)
    {
        d=((d*d)+c)%c;
        if(b2[i]==1)
            d=((d*a)+c)%c;
    }
    return d;
}
mat matrix_mul(mat p1,mat p2)//矩阵相乘
{
    int i,j,k;
    mat t;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            t.v[i][j]=0;
            for(k=0;k<2;k++)
                t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%P;
        }
        return t;
}
mat matrix_mi1(mat p1,__int64 k)//矩阵求幂
{
    mat w;
    w.v[0][0]=1;
    w.v[0][1]=0;
    w.v[1][0]=0;
    w.v[1][1]=1;
    if(k==0)
        return w;
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

mat matrix_mi2(mat p1,__int64 b2,__int64 c2)//矩阵求幂
{
    mat ans=matrix_mi1(p1,c2);
    while(b2)
    {
        b2--;
        p1=matrix_mul(p1,p1);
    }
    return matrix_mul(p1,ans);
}
int main()
{
    __int64 q;
    while(scanf("%I64d%I64d%I64d",&x1,&y1,&z1)!=EOF)
    {
        if(x1==-1&&y1==-1&&z1==-1)
            break;
        scanf("%I64d%I64d%I64d",&y2,&z2,&P);
        q =((mod_exp(x1,y1,P)+z1)%P+P)%P;
        //printf("%I64d\n",q);
        if(q==1)//对公比为1的情况特殊考虑
        {
            int ans1;
            if(y2&&(z2&1))
                ans1=1;
            else if(y2&&(z2%2==0))
                ans1=0;
            else if(!y2&&(z2&1))
                ans1=0;
            else 
                ans1=1;
            printf("%d\n",ans1);
            continue;
        }
        e.v[0][0]=1;
        e.v[0][1]=0;
        e.v[1][0]=1;
        e.v[1][1]=-q;
        ans=matrix_mi2(e,y2,z2);
        if(ans.v[1][0]<0)
            ans.v[1][0]=-ans.v[1][0];
        printf("%I64d\n",ans.v[1][0]%P);
    }
    return 0;
}
/*
0 0 0
0 1
1

0 0 0
0 0
1

0 0 0
1 0
1

0 0 0
1 1
1

*/