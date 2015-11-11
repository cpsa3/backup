////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-03 20:51:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4009
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:4164KB
//////////////////System Comment End//////////////////
/*最小树形图O(VE)*/
/*费用大于直接挖井的边不用加*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <cmath>
#define MAXN 1005
#define type int
#define inf (((type)(1))<<30)
using namespace std;
struct Node
{
    int u , v;
    type cost;
}E[2000000];
int pre[MAXN],ID[MAXN],vis[MAXN];
type In[MAXN];
int xx[MAXN],yy[MAXN],zz[MAXN],X,Y,Z,N;
int ne;


inline void Insert(int u,int v,type c)
{
    E[ne].u=u;
    E[ne].v=v;
    E[ne++].cost=c;
}
inline int Directed_MST(int root,int NV,int NE)//最小树形图模板
{
    int ret=0;
    int i,u,v;
    while(true)
    {
        //1.找最小入边
        for(i=0;i<NV;i++) In[i] = inf;
        for(i=0;i<NE;i++)
        {
            u = E[i].u;
            v = E[i].v;
            if(E[i].cost < In[v] && u != v)
            {
                pre[v] = u;
                In[v] = E[i].cost;
            }
        }
        for(i=0;i<NV;i++)
        {
            if(i == root) continue;
            if(In[i] == inf) return -1;//除了跟以外有点没有入边,则根无法到达它
        }
        //2.找环
        int cntnode = 0;
        memset(ID,-1,sizeof(ID));
        memset(vis,-1,sizeof(vis));
        In[root] =0;
        for(i=0;i<NV;i++)//标记每个环
        {
            ret += In[i];
            v = i;
            while(vis[v]!=i&&ID[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&ID[v]==-1)
            {
                for(u = pre[v] ; u != v ; u = pre[u])
                {
                    ID[u] = cntnode;
                }
                ID[v] = cntnode ++;
            }
        }
        if(cntnode == 0) break;//无环
        for(i=0;i<NV;i++) if(ID[i] == -1)
        {
            ID[i] = cntnode ++;
        }
        //3.缩点,重新标记
        for(i=0;i<NE;i++)
        {
            v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if(E[i].u != E[i].v)
            {
                E[i].cost -= In[v];
            }
        }
        NV = cntnode;
        root = ID[root];
    }
    return ret;
}
inline int fuck(int u,int v)
{
    int dis=abs(xx[u]-xx[v])+abs(yy[u]-yy[v])+abs(zz[u]-zz[v]);
    dis*=Y;
    if(zz[u]<zz[v]) dis+=Z;
    return dis;
}
inline int Scan()
{
    int res=0,ch;
    while(!((ch=getchar())>='0'&&ch<='9'))
    {
        if(ch==EOF) return 1<<30;
    }
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+(ch-'0');
    return res;
}
void Init()
{
    int i,j,m,v,c;
    ne=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%d",&xx[i],&yy[i],&zz[i]);
    }
    for(i=1;i<=N;i++)
        Insert(0,i,zz[i]*X);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&v);
            if(i==v) continue;
            c=fuck(i,v);
            if(c<zz[v]*X)//费用大于直接挖井的边不用 加
                Insert(i,v,c);
        }
    }
}
void Solve()
{
    int ans=Directed_MST(0,N+1,ne);
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d%d%d",&N,&X,&Y,&Z)!=EOF)
    {
        if(N==0&&X==0&&Y==0&&Z==0) break;
        Init();
        Solve();
    }
return 0;
}