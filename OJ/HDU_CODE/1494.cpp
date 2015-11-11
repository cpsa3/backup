////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-11-25 23:18:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1494
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
const int N=105;
const int IF=99999999;
int e[2][16];
main ()
{
    int a[N],b[N],l,n,i,j,k;
    while(scanf("%d%d",&l,&n)!=EOF)
    {
        for(i=1;i<=l;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=l;i++)
            scanf("%d",&b[i]);
        e[0][1]=0;//初始化
        for(i=2;i<=15;i++)
            e[0][i]=IF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=l;j++)//每个点都有15个状态
            {
                e[1][1]=IF;
                for(k=1;k<16;k++)
                {
                    e[1][k+1]=e[0][k]+a[j];
                    if(k>5&&e[0][k]+b[j]<e[1][k-5])
                        e[1][k-5]=e[0][k]+b[j];
                }
                if(e[0][15]+b[j]<e[1][10])
                    e[1][10]=e[0][15]+b[j];
                if(e[0][15]+a[j]<e[1][11])
                    e[1][11]=e[0][15]+a[j];
                for(k=1;k<16;k++)
                    e[0][k]=e[1][k];
            }
        }
        int ans=IF;
        for(i=1;i<=15;i++)
            if(ans>e[0][i])
                ans=e[0][i];
            printf("%d\n",ans);
    }
return 0;
}
