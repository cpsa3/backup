////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-07-08 22:39:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3594
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1920KB
//////////////////System Comment End//////////////////
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=20010;
vector<int>v[maxn];
int n,belong[maxn],low[maxn],bcnt,cnt,dfn[maxn];
bool vis[maxn],ans;
int sta[maxn],top;
int min(int x,int y){
    if(x<y)return x;
    else return y;
}
void ini(){
    top=bcnt=cnt=0;
    ans=false;
    for(int i=0;i<=n;i++){
        v[i].clear(); 
        vis[i]=0;
        low[i]=-1;
        dfn[i]=-1;
    }
}
void tarjan(int x){
    int i,t1=0,t2=0;
    low[x]=dfn[x]=cnt++;
    sta[top++]=x;
    vis[x]=true;
    for(i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(low[y]==-1){
            tarjan(y);
            if(low[y]<=low[x]){//have a circle
                low[x]=low[y];
                t1=1;
            }
        }
        else if(vis[y]){
            low[x]=min(low[x],dfn[y]);//the edge add a circle
            t2++;
        }
    }
    if(dfn[x]==low[x]){
        int y;
        do{
            y=sta[--top];
            belong[y]=bcnt;
            low[y]=2*n;
            vis[y]=false;
        }while(y!=x);
        bcnt++;
    }
    if(t1+t2>1)ans=true;
}
void getscc(){

    for(int i=0;i<n;i++)
        if(low[i]==-1)
            tarjan(i);
    if(ans||bcnt>1)
        printf("NO\n");
    else
        printf("YES\n");
}
int main(){
    int T;
   //freopen("a.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ini();
        int x,y;
        while(scanf("%d%d",&x,&y)){
            if(x==0&&y==0) break;
            v[x].push_back(y);
        }
        getscc();
    }
    return 0;
}
