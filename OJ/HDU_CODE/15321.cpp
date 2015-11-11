////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-15 10:47:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*HDU_3035 War*/
/*平面图的网络流(Dinic模板)*/
/*PS.Sap模板超时*/
/*AC代码：3390ms*/
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 2e9;

/*==================================================*\
| Dinic最大流 O(V^2 * E)
| INIT: ne=2; head[]置为0; addedge()加入所有弧;
| CALL: flow(n, s, t);
\*==================================================*/
#define N 300                               //点数
#define E 6000                              //边数
#define typec int                           //type of cost
int scr,sink,vn;                            //源点、汇点、总结点数
const typec inf=(((typec)(1))<<30);         //max of cost
struct edge { int x, y, nxt; typec c; } bf[E];
int ne, head[N], cur[N], ps[N], dep[N];

void ini()                                  //初始化
{
    ne=2;
    memset(head,0,sizeof(head));
}

void Insert(int x, int y, typec c)
{   //add an arc(x -> y, c); vertex: 0 ~ n-1;
	bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
	bf[ne].nxt = head[x]; head[x] = ne++;
	bf[ne].x = y; bf[ne].y = x; bf[ne].c = 0;//有向图是0，无向图是c;
	bf[ne].nxt = head[y]; head[y] = ne++;
}
typec Dinic(int n, int s, int t)
{
	typec tr, res = 0;
	int i, j, k, f, r, top;
	while (1)
	{
		memset(dep, -1, n * sizeof(int));
		for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
		{
			for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
			{
				if (bf[j].c && -1 == dep[k = bf[j].y])
				{
					dep[k] = dep[i] + 1; ps[r++] = k;
					if (k == t) { f = r; break; }
				}
			}
		}
		if (-1 == dep[t]) break;
		memcpy(cur, head, n * sizeof(int));
		for (i = s, top = 0; ; )
		{
			if (i == t)
			{
				for (k = 0, tr = inf; k < top; ++k)
				{
					if (bf[ps[k]].c < tr)
						tr = bf[ps[f = k]].c;
				}
				for (k = 0; k < top; ++k)
					bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
				res += tr; i = bf[ps[top = f]].x;
			}
			for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
			{
				if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
			}
			if (cur[i])
			{
				ps[top++] = cur[i];
				i = bf[cur[i]].y;
			}
			else
			{
				if (0 == top) break;
				dep[i] = -1; i = bf[ps[--top]].x;
			}
		}
	}
	return res;
}


void Init(int n,int m)
{
    ini();
    scr=1;sink=m;vn=m+1;
    int i,u,v,w;
    //建图
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
    }
}

void Solve()
{
    printf("%d\n",Dinic(vn,scr,sink));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Init(n,m);
        Solve();
    }
return 0;
}