////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-12 20:14:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4039
////Problem Title: 
////Run result: Accept
////Run time:687MS
////Run memory:25108KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

const int MAXN = 2002;
map<string,int> M;

struct Friend{
    string na,nb;
}node[MAXN];

bool mat[MAXN][MAXN];
int adj[MAXN][MAXN];
int ans[MAXN][MAXN],cunt[MAXN];
string sa[MAXN];

void init(int num){
    int i,j;
    for(i=0;i<num;i++){
        adj[i][0] = 0;
        for(j=0;j<num;j++)
            if(mat[i][j])
                adj[ i ][ ++ adj[i][0] ] = j;
    }
}

void dfs(int p,int r,int dep){
    if(dep == 2){
        if(!mat[p][r] && p!=r)
            cunt[r] ++;
        return ;
    }
    for(int i=1;i<=adj[r][0];i++)
        dfs(p,adj[r][i],dep+1);
}

void cal(int p,int num){
    int ma = 0;
    for(int i=0;i<num;i++)
        if(cunt[i] > ma){
            ma = cunt[i];
            ans[p][0] = 0;
            ans[p][++ans[p][0]] = i;
        }else if(cunt[i] == ma && ma!=0){
            ans[p][++ans[p][0]] = i;
        }
}

bool cmp(int a,int b){
    return sa[a] < sa[b];
   }
int n,q;
int main(){
    int T,cas = 1;
    int i,j;
    cin>>T;
    while(T --){
        cin>>n>>q;
        int idx = 0;
        M.clear();
        for(i = 0; i < n; i++){
            cin>>node[i].na >> node[i].nb;
            if(M.find(node[i].na) == M.end()){
                sa[idx] = node[i].na;
                M[ node[i].na ] = idx ++;
            }
            if( M.find(node[i].nb) == M.end() ){
                sa[idx] = node[i].nb;
                M[ node[i].nb ] = idx ++;
            }
        }
        memset(mat,false,sizeof(mat));
        for(i = 0; i < n; i++){
            int a = M[node[i].na];
            int b = M[node[i].nb];
            mat[a][b] = true;
            mat[b][a] = true;
        }
        init(idx);
        string str;
        memset(ans,-1,sizeof(ans));
        printf("Case %d:\n",cas++);
        while(q --){
            cin>>str;
            int p = M[str];
            if(ans[p][0] == -1){
                ans[p][0] = 0;
                memset(cunt,0,sizeof(cunt));
                dfs(p,p,0);
                cal(p,idx);
            }
            if(ans[p][0] ==0 )
                cout<<"-"<<endl;
            else{
                sort(ans[p]+1,ans[p]+1+ans[p][0],cmp);
                cout<<sa[ans[p][1]];
                for(i=2;i<=ans[p][0];i++)
                    cout<<" "<<sa[ans[p][i]];
                cout<<endl;
            }
        }
    }return 0;
}