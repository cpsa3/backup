////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-15 10:10:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:3359MS
////Run memory:55192KB
//////////////////System Comment End//////////////////

#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#define N 600000
#define E 3000000
using namespace std;
const int INF = 2e9;
int scr1,sink1,vn1,nn1;

/*==================================================*\
| Dinic最大流 O(V^2 * E)
| INIT: ne=2; head[]置为0; addedge()加入所有弧;
| CALL: flow(n, s, t);
\*==================================================*/
#define typec int // type of cost
const typec inf =2e9; // max of cost
struct edge { int x, y, nxt; typec c; } bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void Insert(int x, int y, typec c)
{ // add an arc(x -> y, c); vertex: 0 ~ n-1;
	bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
	bf[ne].nxt = head[x]; head[x] = ne++;
	bf[ne].x = y; bf[ne].y = x; bf[ne].c = c;
	bf[ne].nxt = head[y]; head[y] = ne++;
}
typec flow(int n, int s, int t)
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
void ini()
{
    ne=2;
    memset(head,0,sizeof(head));
}
int Scan(){
    char c;
    int res;
    while(c=getchar(),!(c>='0'&&c<='9'));
    res=c-'0';
    while(c=getchar(),c>='0'&&c<='9'){
        res=res*10+c-'0';
    }
    return res;
}
void Init(int n,int m)
{
    ini();
    int i,j,u,v,w,px,py;
    nn1=(n+1)*(m+1);
    scr1=1;sink1=nn1;vn1=nn1+(n*m);
    //建图
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=m;j++)
        {
            w=Scan();
            u=(i-1)*(m+1)+j;
            v=u+1;
            Insert(u,v,w);
            //Insert(v,u,w);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m+1;j++)
        {
            //scanf("%d",&w);
            w=Scan();
            u=(i-1)*(m+1)+j;
            v=u+m+1;
            Insert(u,v,w);
            //Insert(v,u,w);
        }
    }
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=2*m;j++)
        {
            //scanf("%d",&w);
            w=Scan();
            px=(i+1)>>1;
            py=(j+1)>>1;
            v=(px-1)*m+py+nn1;
            u=(px-1)*(m+1)+py;
            if((i%2)&&(j%2==0)) u++;
            else if((i%2==0)&&(j%2)) u+=(m+1);
            else if((i%2==0)&&(j%2==0)) u+=(m+2);
            Insert(u,v,w);
            //Insert(v,u,w);
        }
    }
    
    printf("%d\n",flow(vn1+1,scr1,sink1));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Init(n,m);
        //Solve();
    }
return 0;
}