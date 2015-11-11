////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-28 20:31:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2502
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
int C(int n,int m)
{
    int i,j;
    double ans=1;
    for(i=1,j=n;i<=m;i++,j--)
        ans=ans*j*1.0/i;
    return (int)ans;
}
int f[25]={0};
int main ()
{
    int i,j,n;
    f[1]=1;f[2]=3;f[3]=8;
    for(i=4;i<=20;i++)
    {
        f[i]+=pow(2,i-1);
        for(j=1;j<=i-1;j++)
            f[i]+=C(i-1,j)*j;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
return 0;
}