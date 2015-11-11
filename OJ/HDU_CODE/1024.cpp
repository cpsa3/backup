////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-01 18:12:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:718MS
////Run memory:8444KB
//////////////////System Comment End//////////////////
#include <iostream>
const int N=1000050;
int now[N],a[N],pre[N];//now[N]用来记录当前的，pre[N]用来记录前一个最大的
//DP方程：now[i][j]=max(now[i-1][j]+a[i],max(now[0][j-1]```now[i-1][j-1])+a[i]);
int Max(int a,int b)
{
    return a>b?a:b;
}
main()
{
    int n,m,max,i,j;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(now,0,sizeof(now));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=m;i++)
        {
            max=-99999999;
            for(j=i;j<=n;j++)
            {
                now[j]=Max(now[j-1]+a[j],pre[j-1]+a[j]);
                pre[j-1]=max;
                if(now[j]>max)
                    max=now[j];
            }
        }
        printf("%d\n",max);
    }
return 0;
}