////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-05 19:14:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2121
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:324KB
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
int N,M,Sum,Root;
int ne;


inline void Insert(int u,int v,type c)
{
    E[ne].u=u;
    E[ne].v=v;
    E[ne++].cost=c;
}
inline int Directed_MST(int root,int NV,int NE)//最小树形图模板,NV从0开始存
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
                if(u==root) Root=i;
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
    int i,j,u,v,c;
    ne=0;
    Sum=0;
    for(i=1;i<=M;i++)
    {
        //scanf("%d%d%d",&u,&v,&c);
        u=Scan();v=Scan();c=Scan();
        u++;v++;
        Insert(u,v,c);
        Sum+=c;
    }
    Sum++;
    for(i=1;i<=N;i++)
        Insert(0,i,Sum);
}
void Solve()
{
    int ans=Directed_MST(0,N+1,ne);
    //printf("*%d\n",ans);
    if(ans==-1||ans>=2*Sum)//最小树形图的边权和值大于sum的两倍，说明不可能构成最小树形图，因为必定存在两条从虚拟点出发的边
        printf("impossible\n");
    else//利用i>=m时，第i条边的终点为i-m;这里不能替换为E[Root].v-1;因为E[i]在朱刘算法过程中节点信息会变化。
        printf("%d %d\n",ans-Sum,Root-M);
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}