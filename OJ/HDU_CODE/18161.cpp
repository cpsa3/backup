////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-14 01:18:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1816
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:532KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define size 8000 // 点的个数
#define esize 300010 // 边的个数
int v[size], cnt;
struct edge{int from, to, next;}e[esize];
void insert(int from, int to)
{
    e[cnt].from = from, e[cnt].to = to; e[cnt].next = v[from]; v[from] = cnt++;
}
int index, dfn[size], low[size], instack[size], sta[size], top;
int belong[size], cntnum, num[size];
bool ans[size];//1表示选择
void tarjan(int id)
{
    dfn[id] = low[id] = ++index;
    instack[id] = 1; sta[top++] = id;
    int tmp = v[id];
    while(tmp != -1)
    {
        if (!dfn[e[tmp].to])
        { tarjan(e[tmp].to); if (low[e[tmp].to] < low[id]) low[id] = low[e[tmp].to];
        }
        else if (instack[e[tmp].to] && dfn[e[tmp].to] < low[id])
            low[id] = dfn[e[tmp].to];
        tmp = e[tmp].next;
    }
    if (dfn[id] == low[id])
    {
        do
        { tmp = sta[--top]; instack[tmp] = 0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }while(tmp != id);
        cntnum++;
    }
}
int solve(int n) // n是一半的点数(实际的人数) 执行tarjan和topsort,完成标记
{
	int i;
    index = cntnum = top = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(num, 0, sizeof(num));
    for(i = 0; i < 2 * n; i++)
        if (!dfn[i]) tarjan(i);
    for(i = 0; i < n; i++)                  //在缩点的图中标记互斥的缩点。（原来互斥，现在也互斥）
    {
        if (belong[i] == belong[i + n])
        {
            return false;
        }
    }
}
int main()
{
    int n,m,i,j,a,b;
    int c[size][2],d[size][2];
    while(1)
    {
            scanf("%d%d",&n,&m);
            if(n==0&&m==0)
            break;
            for(i=1;i<=n;i++)
            {
                    scanf("%d%d",&a,&b);
                    c[i][0]=a;
                    c[i][1]=b;
                    //insert(a,b+2*n);
                    //insert(b,a+2*n);         
            }
            for(i=1;i<=m;i++)
            {
                    scanf("%d%d",&a,&b);
                    d[i][0]=a;
                    d[i][1]=b;         
            }
            int left=0,right=m,mid,flag=0;
            while(left+1<right)
            {
                mid=(left+right)/2;
                memset(v,-1,sizeof(v));
                cnt=0;
                for(i=1;i<=n;i++)
                {
                        insert(c[i][0],c[i][1]+2*n);
                        insert(c[i][1],c[i][0]+2*n);         
                }
                for(i=1;i<=mid;i++)
                {
                       a=d[i][0];
                       b=d[i][1];          
                       insert(a+2*n,b);
                       insert(b+2*n,a);                     
                }
                if(solve(2*n))
                       left=mid; 
                else
                       right=mid; 
            }
            memset(v,-1,sizeof(v));
            cnt=0;
            for(i=1;i<=n;i++)
            {
                    insert(c[i][0],c[i][1]+2*n);
                    insert(c[i][1],c[i][0]+2*n);
            }
            for(i=1;i<=left+1;i++)
            {
                    a=d[i][0];
                    b=d[i][1];          
                    insert(a+2*n,b);
                    insert(b+2*n,a);                     
            }
            if(solve(2*n))
            printf("%d\n",left+1);
            else
            printf("%d\n",left);
    }
}
