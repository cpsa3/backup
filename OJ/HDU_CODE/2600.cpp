////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:15:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2600
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int N,p,q,cnt;
int s[105],e[105];
int num[300];
char str[100];

void Init()
{
    int i;
    cnt=0;
    scanf("%d%d",&p,&q);
    num[cnt++]=p;num[cnt++]=q;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&s[i],&e[i]);
        gets(str);
        num[cnt++]=s[i]-1;
        num[cnt++]=e[i]+1;
    }
}
void Solve()
{
    int ans=-1,i,j;
    sort(num,num+cnt);
    for(i=cnt-1;i>=0;i--)
    {
        if(num[i]>q||num[i]<p) continue;
        for(j=1;j<=N;j++)
        {
            if(num[i]>=s[j]&&num[i]<=e[j]) break;
        }
        if(j==N+1) {ans=num[i];break;}
    }
    if(ans==-1) printf("Badly!\n");
    else printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}