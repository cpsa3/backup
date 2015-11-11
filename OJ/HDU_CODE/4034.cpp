////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-12 20:15:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4034
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 102;
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;

int solve(){
    memset(vis,false,sizeof(vis));
    int i,j,k,cnt=0;
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    if(i==k||j==k||i==j)
                        continue;
                    if(mat[i][j] > mat[i][k] + mat[k][j])
                        return -1;
                    else if(mat[i][j] == mat[i][k] + mat[k][j])
                        vis[i][j]=true;
                }
                
            cnt=0;
            for(i=1;i<=n;i++)
            {
                 for(j=1;j<=n;j++)
                 {
                    if(i==j) continue;
                    if(vis[i][j]) cnt++;
                 }
            }
    return n*(n-1) - cnt;
}
int main(){
    int T,cas=1;
    int i,j;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&mat[i][j]);
        int ans = solve();
        printf("Case %d: ",cas ++);
        if(ans == -1)
            printf("impossible\n");
        else
            printf("%d\n",ans);    
    }
    return 0;
}
