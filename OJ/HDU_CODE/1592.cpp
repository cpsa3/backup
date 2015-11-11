////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:16:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1592
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1812KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f[1005][400];
int N;
void Run()
{
    int i,j;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        for(j=0;j<400;j++)
            f[i][j]=f[i-1][j]*2;
        f[i][0]+=1;
        for(j=0;j<399;j++)
        {
            f[i][j+1]+=f[i][j]/10;
            f[i][j]=f[i][j]%10;
        }
    }
}
void Print(int n)
{
    int i,j;
    i=399;
    while(f[n][i]==0) i--;
    while(i>=0) 
    {
        printf("%d",f[n][i]);
        i--;
    }
    printf("\n");
}
int main()
{
    int i;
    Run();
    while(scanf("%d",&N)!=EOF)
        Print(N);
return 0;
}