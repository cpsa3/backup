////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:10:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1894
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:2196KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MOD 11519
#define MAXN 50005
using namespace std;

int N;
struct Node
{
    char s[40];
}node[MAXN];
int cmp(const void *p1,const void *p2)
{
    return strcmp(((struct Node *)p1)->s,((struct Node *)p2)->s);
}
void Print()
{
    int i;
    for(i=0;i<N;i++)
        printf("%s\n",node[i].s);
}
void Init()
{
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%s",node[i].s);
    qsort(node,N,sizeof(node[0]),cmp);
    //Print();
}
void Solve()
{
    int i,j,k;
    __int64 ans=0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            bool ok=true;
            k=0;
            while(node[i].s[k]!='\0'&&node[j].s[k]!='\0'&&node[i].s[k]==node[j].s[k])
                k++;
            if(node[i].s[k]=='\0')
                ans++;
            else
                break;
        }
    }
    if(ans>MOD) ans%=MOD;
    printf("%I64d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}