////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-17 18:00:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4039
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:508KB
//////////////////System Comment End//////////////////
/*HDU_4039 The Social Network*/
/*O(N^2)Ã¶¾Ù*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string>
#include <algorithm>
#include <map>
#define MAXN 2005
using namespace std;
struct edge
{
    int u,v,next;
}E[200000];
int head[MAXN],ecnt;

map<string,int>hash;
string ans[MAXN];
string S[MAXN];
int N,Q,cas,cnt;
bool vis[MAXN];
int now[MAXN];
void Insert(int u,int v)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,u,v;
    memset(head,-1,sizeof(head));ecnt=0;
    string s1,s2;
    hash.clear();
    cnt=0;
    scanf("%d%d",&N,&Q);
    for(i=1;i<=N;i++)
    {
        cin>>s1>>s2;
        if(!hash[s1])
        {
            hash[s1]=++cnt;
            S[cnt]=s1;
        }
        if(!hash[s2])
        {
            hash[s2]=++cnt;
            S[cnt]=s2;
        }
        u=hash[s1];v=hash[s2];
        Insert(u,v);
        Insert(v,u);
    }
}
void fuck(int pos)
{
    int i,j,u,v;
    memset(now,0,sizeof(now));
    memset(vis,false,sizeof(vis));
    vis[pos]=true;
    for(i=head[pos];i!=-1;i=E[i].next)
    {
        v=E[i].v;
        vis[v]=true;
        //cout<<"*"<<S[v]<<endl;
    }
    int Max=0;
    for(i=head[pos];i!=-1;i=E[i].next)
    {
        u=E[i].v;
        if(u==pos) continue;
        for(j=head[u];j!=-1;j=E[j].next)
        {
            v=E[j].v;
            if(vis[v]) continue;
            now[v]++;
            if(Max<now[v]) Max=now[v];
        }
    }
    
    //printf("**%d\n",Max);
    int nn=0;
    
    for(i=1;i<=cnt;i++)
    {
        if(now[i]==Max)
        {
            ans[nn++]=S[i];
            //cout<<"*"<<S[i]<<endl;
            
        }
    }
    if(Max==0)
        cout<<'-'<<endl;
    else
    {
        sort(ans,ans+nn);
        for(i=0;i<nn-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans[i]<<endl;
    }
}
void Solve()
{
    int i,u,v;
    string s1;
    printf("Case %d:\n",cas++);
    while(Q--)
    {
        cin>>s1;
        u=hash[s1];
        fuck(u);
    }
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}