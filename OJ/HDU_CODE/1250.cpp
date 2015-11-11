////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-25 22:43:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*´óÊý*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int F1[2005],F2[2005],F3[2005],F4[2005];
int ans[2005];
int N;
void Copy(int a[],int b[])
{
    int i;
    for(i=0;i<=2002;i++)
        a[i]=b[i];
}
void Print(int ans[])
{
    int i,pos;
    for(i=2002;i>=0;i--)
    {
        if(ans[i]) {pos=i;break;}
    }
    for(i=pos;i>=0;i--)
        printf("%d",ans[i]);
    printf("\n");
}
int main()
{
    int i,j;
    while(scanf("%d",&N)!=EOF)
    {
        if(N<=4)
        {printf("1\n");continue;}
        memset(F1,0,sizeof(F1));
        memset(F2,0,sizeof(F2));
        memset(F3,0,sizeof(F3));
        memset(F4,0,sizeof(F4));
        memset(ans,0,sizeof(ans));
        F1[0]=F2[0]=F3[0]=F4[0]=1;
        
        int temp[2005];

        for(i=5;i<=N;i++)
        {
            for(j=0;j<2002;j++)
            {
                ans[j]+=F1[j]+F2[j]+F3[j]+F4[j];
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
            //Copy(temp,F1);
            Copy(F1,F2);
            Copy(F2,F3);
            Copy(F3,F4);
            Copy(F4,ans);
            memset(ans,0,sizeof(ans));
        }
        Print(F4);
    }
return 0;
}