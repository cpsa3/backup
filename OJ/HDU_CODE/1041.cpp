////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 14:41:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1041
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2168KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int ds[1001][501];
int main()
{
    int n,i,j,jw,f;

    ds[0][0] = ds[1][0] = 0; ds[2][0] = ds[3][0] = 1;
    for(i=4;i<=1000;i++)
        for(jw=j=0;j<=500;j++)
        {
            ds[i][j] = ds[i-1][j] + ds[i-2][j]*2 + jw;
            jw = ds[i][j] / 10;
            ds[i][j] %= 10;
        }

    while(scanf("%d",&n)!=EOF)
    {
        if(n==1) printf("0");
        else
            for(f=j=500;j>=0;j--)
                if(ds[n][j] || !f)
                {
                    printf("%d",ds[n][j]);
                    f = 0;
                }
        puts("");
    }
}
