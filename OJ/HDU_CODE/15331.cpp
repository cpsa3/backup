////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-29 01:06:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1533
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
#define maxn 105
#define Max  1000000000
using namespace std;
char str[maxn][maxn];
int map[maxn][maxn];
int cost[2 * maxn][2 * maxn];
int flow[2 * maxn][2 * maxn];
int pre[2 * maxn];
int dis[2*maxn];
int minflow[2 * maxn];
int q[100000];
int mark[2 * maxn];

struct ss {
    int x, y;
} house[maxn], man[maxn];

int SPFA(int start ,int end) {
    int l, h, i, k;
    for (i = 0; i <= end; i++) {
        mark[i] = 0, dis[i] = Max;
        pre[i] = -1, minflow[i] = Max;
    }
    l = h = 0;
    q[l++] = start;
    mark[start]= 1;
    dis[start]=0;
    while (h < l) {
        k = q[h++];
        mark[k]=0;
        for (i = 0; i <= end; i++) {
            if (flow[k][i] > 0 && dis[i] > dis[k] + cost[k][i]) {
                pre[i] = k;
                dis[i] = dis[k] + cost[k][i];
                minflow[i] = min(minflow[k], flow[k][i]);
                if (!mark[i]) {
                    q[l++] = i;
                    mark[i] = 1;
                }
            }
        }
    }
    return dis[end] != Max;
}

int maxflow_mincost(int start, int end) {
    int i, x, ans = 0;
    while (SPFA(start,end)) {
        x = end;
        while (pre[x] != -1) {
            flow[pre[x]][x] -= minflow[end];
            flow[x][pre[x]] += minflow[end];
            x=pre[x];
        }
        ans += dis[end];
    }
    return ans;
}

int main() {
    int N, M, i, j, k1,k2 ,n;
    while (scanf("%d %d", &N, &M), N) {
        k1 = k2 = 1;
        memset(flow, 0, sizeof (flow));
        for (i = 0; i < N; i++) {
            scanf("%s", str[i]);
            for (j = 0; j < M; j++) {
                if (str[i][j] == 'H') {
                    house[k1].x = i;
                    house[k1++].y = j;
                } else if (str[i][j] == 'm') {
                    man[k2].x = i;
                    man[k2++].y = j;
                }
            }
        }
        n = k1-1;
        for(i=0;i<=2*n+1;i++)
        for(j=0;j<=2*n+1;j++)cost[i][j]=Max;
        for (i = 1; i <= n; i++) {
            for (j = n + 1; j <= 2 * n; j++) {
                cost[i][j] = abs(house[j - n].x - man[i].x) + abs(house[j - n].y - man[i].y);
                cost[j][i] = -cost[i][j];
                flow[i][j] = 1;
            }
            cost[0][i] = 0;
            cost[i][0] = 0;
            flow[0][i] = 1;
            cost[i + n][2 * n + 1] = 0;
            cost[2 * n + 1][i + n] = 0;
            flow[i + n][2*n + 1] = 1;
        }
        printf("%d\n", maxflow_mincost(0, 2*n + 1));
    }
    return 0;
}
