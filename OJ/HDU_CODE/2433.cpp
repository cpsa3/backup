////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-03 14:12:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2433
////Problem Title: 
////Run result: Accept
////Run time:1203MS
////Run memory:868KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <queue>
using namespace std; 
#define N 105
#define M 6001 
struct EDGE 
{ 
    short b;//当前点
    short next;//下一点
    short id;//边的编号
};
int G[N];
int sum[N];//s[i]用来记录i点到其余各点的最短路径之和
int tot;//记录边的条数
EDGE ET[M];
bool vv[N][M];
void addedge(int a,int b,int id)//添加边
{ 
    EDGE x={b,G[a],id};//初始化,直接赋值
    ET[tot]=x;//构造向前星
    G[a]=tot++;//核心
} 
void init()//初始化
{ 
    tot=0; 
    memset(G,-1,sizeof(G));
} 
int n, m;
void bfs(int s) 
{ 
    queue<int>Q; 
    bool v[N]; 
    int  x,rp,np,d=0,i,j; 
    memset(v,0,sizeof(v)); 
    memset(vv[s],0,sizeof(vv[s])); 
    Q.push(s);//起始点
    v[s]=1;
    rp=1;
    sum[s]=0; 
    while(!Q.empty()) 
    {  
        np=0;  
        while(rp--) 
        {   
            x=Q.front();   
            Q.pop();  
            sum[s]+=d;
            for(j=G[x];j!=-1;j=ET[j].next) 
            {    
                i=ET[j].b;    
                if(!v[i])//如果之前还没搜过该点就放入队列
                {     
                    Q.push(i);     
                    v[i]=1;//标记掉
                    vv[s][ET[j].id]=1;//表示在搜以s为源点是用到了边id
                    np++;
                }
            }
        }
        rp=np;
        d++; 
    }
}
int bfs2(int s,int del) 
{ 
    queue<int>Q; 
    bool v[N]; 
    int x,rp,np,d=0,i,j,ans=0,cnt=1; 
    memset(v,0,sizeof(v)); 
    Q.push(s);
    v[s]=1; 
    rp=1; 
    while(!Q.empty()) 
    {  
        np=0;  
        while(rp--) 
        {   
            x=Q.front();   
            Q.pop();   
            ans+=d;   
            for(j=G[x];j!=-1;j=ET[j].next) 
            {    
                if(ET[j].id==del) continue;//删了两条边:正反向的  
                i=ET[j].b;    
                if(!v[i]) 
                {     
                    Q.push(i);     
                    v[i]=1;
                    np++;
                    cnt++;    
                }   
            }   
        }  
        rp=np;
        d++; 
    }
    if(cnt!=n) 
        return -1; 
    return ans;
} 
void solve() 
{ 
    int i,j,a,b; 
    init(); 
    for (i=0;i<m;i++) 
    {  
        scanf("%d%d",&a,&b);  
        addedge(a,b,i);//不明白什么用的?????
        addedge(b,a,i); 
    } 
    for(i=1;i<=n;i++)//对每个顶点u求一次单源最短路 
        bfs(i); 
    for(i=0;i<2*m;i+=2)//这么多的路径
    {  
        int del=i/2,ans=0,t;//删除路径
        for(j=1;j<=n;j++) 
        {   
            if(vv[j][del]==0)//如果删除的那条边不在最短路径上 
                ans+=sum[j];  
            else 
            {    
                t=bfs2(j,del);//否则删除那条边重新求一次单源最短路
                if(t==-1)//如果到达不了直接返回
                {     
                    ans=-1;     
                    break;    
                }    
                ans+=t;//否则加上最短路径  
            }  
        }  
        if(ans==-1) 
            printf("INF\n");  
        else 
            printf("%d\n",ans);
    }
}
int main() 
{ 
    while(scanf("%d%d",&n,&m)!=EOF)  
        solve();
    return 0;
}
