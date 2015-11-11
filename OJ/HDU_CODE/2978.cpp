////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-23 23:41:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2978
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:284KB
//////////////////System Comment End//////////////////
/*±©¡¶*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N,M,K,cas;
struct Node
{
    string s;
    string kind;
}node[105];
string ans;
int P,Q;
void Init()
{
    int i;
    scanf("%d%d",&M,&K);
    for(i=1;i<=N;i++)
        cin>>node[i].s>>node[i].kind;
}
void Go(string now)
{
    //cout<<now<<"*"<<endl;
    int i,p=0,q=0;
    for(i=1;i<=N;i++)
    {
        if(node[i].s.find(now)!=-1)
        {
            p++;
            if(node[i].kind=="Yes")
                q++;
        }
    }
    if(p<M) return;
    if(ans=="")
    {
        //printf("*\n");
        P=p;Q=q;
        ans=now;
        return;
    }
    int w=q*P-p*Q;
    if(w<0)
    {
        P=p;Q=q;
        ans=now;
    }
    else if(w==0)
    {
        if(p>P||(p==P&&ans.compare(now)>0))
        {
            P=p;Q=q;
            ans=now;
        }
    }
}
void Run(int ith)
{
    int i,len=node[ith].s.size();
    string now;
    for(i=0;i<len;i++)
    {
        if(i+K>len) break;
        now=node[ith].s.substr(i,K);
        Go(now);
    }
}
void Solve()
{
    int i;
    ans="";
    for(i=1;i<=N;i++)
        Run(i);
    printf("Case %d: ",cas++);
    if(ans=="") ans="No solution";
    cout<<ans<<endl;
}
int main()
{
    cas=1;
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
    return 0;
}