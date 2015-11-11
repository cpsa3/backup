////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-15 10:26:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:3390MS
////Run memory:55196KB
//////////////////System Comment End//////////////////
/*HDU_3035 War*/
/*平面图的网络流*/
/*AC代码：*/
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
#define N 600000                            //点数
#define E 3000000                           //边数
#define typec int                           //type of cost
int scr,sink,vn;                            //源点、汇点、总结点数
const typec inf=(((typec)(1))<<30);         //max of cost
struct edge { int x, y, nxt; typec c; } bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void Insert(int x, int y, typec c)
{   //add an arc(x -> y, c); vertex: 0 ~ n-1;
	bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
	bf[ne].nxt = head[x]; head[x] = ne++;
	bf[ne].x = y; bf[ne].y = x; bf[ne].c = c;//有向图是0，无向图是c;
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
void ini()   //初始化
{
    ne=2;
    memset(head,0,sizeof(head));
}

inline int Scan()//输入外挂
{
    int res=0,ch,k=1;
    while(!((ch=getchar())>='0'&&ch<='9'||ch=='-'))
    {
        if(ch==EOF) return 1<<30;
    }
    if(ch=='-')
        k=-1;
    else
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+(ch-'0');
    return res*k;
}	

void Init(int n,int m)
{
    ini();
    int i,j,u,v,w,px,py;
    int nn=(n+1)*(m+1);
    scr=1;sink=nn;vn=nn+(n*m);
    //建图
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=m;j++)
        {
            w=Scan();
            u=(i-1)*(m+1)+j;
            v=u+1;
            Insert(u,v,w);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m+1;j++)
        {
            w=Scan();
            u=(i-1)*(m+1)+j;
            v=u+m+1;
            Insert(u,v,w);
        }
    }
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=2*m;j++)
        {
            w=Scan();
            px=(i+1)>>1;
            py=(j+1)>>1;
            v=(px-1)*m+py+nn;
            u=(px-1)*(m+1)+py;
            if((i%2)&&(j%2==0)) u++;
            else if((i%2==0)&&(j%2)) u+=(m+1);
            else if((i%2==0)&&(j%2==0)) u+=(m+2);
            Insert(u,v,w);
        }
    }
}

void Solve()
{
    printf("%d\n",Dinic(vn+1,scr,sink));
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