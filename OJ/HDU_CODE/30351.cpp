////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-29 20:17:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:3140MS
////Run memory:54828KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define inf 2e9
#define MAXN 501005
#define MAXE 3102000
#define typec int // type of cost
struct edge 
{
    int x,y,nxt;
    typec c;
}bf[MAXE];
int ne, head[MAXN], cur[MAXN], ps[MAXN], dep[MAXN];
int scr1,sink1,vn1,nn1;

inline f_min(int x,int y){
    return x<y?x:y;
}

int Scan(){
    int res = 0 , ch ;
    while( !( ( ch = getchar() ) >= '0' && ch <= '9' ) );
    res = ch - '0' ;
    while( ( ch = getchar() ) >= '0' && ch <= '9' )
        res = res * 10 + ( ch - '0' ) ;
    return res ;
}

void add_edge(int x, int y, typec c)
{ // add an arc(x -> y, c); vertex: 0 ~ n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = c;//有向为0，无向为c
    bf[ne].nxt = head[y];
    head[y] = ne++;
}
typec max_flow(int n, int s, int t) {  
    typec tr, res = 0;  
    int i, j, k, f, r, top;  
    while (1) {  
        memset(dep, -1, n * sizeof (int));  
        for (f = dep[ps[0] = s] = 0, r = 1; f != r;)  
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt) {  
                if (bf[j].c && -1 == dep[k = bf[j].y]) {  
                    dep[k] = dep[i] + 1;  
                    ps[r++] = k;  
                    if (k == t) {  
                        f = r;  
                        break;  
                    }  
                }  
            }  
        if (-1 == dep[t]) break;  
        memcpy(cur, head, n * sizeof (int));  
        for (i = s, top = 0;;) {  
            if (i == t) {  
                for (k = 0, tr = inf; k < top; ++k)  
                    if (bf[ps[k]].c < tr)  
                        tr = bf[ps[f = k]].c;  
                for (k = 0; k < top; ++k)  
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;  
                res += tr;  
                i = bf[ps[top = f]].x;  
            }  
            for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)  
                if (bf[j].c && dep[i] + 1 == dep[bf[j].y]) break;  
            if (cur[i]) {  
                ps[top++] = cur[i];  
                i = bf[cur[i]].y;  
            } else {  
                if (0 == top) break;  
                dep[i] = -1;  
                i = bf[ps[--top]].x;  
            }  
        }  
    }  
    return res;  
}  
void get_graph()
{
	ne = 2;
    memset(head, 0, sizeof(head));
}


void Init(int N,int M)
{
    int i,j,u,v,w,px,py;
    get_graph();
    nn1=(N+1)*(M+1);
    scr1=1;sink1=nn1;vn1=nn1+(N*M);
    //建图
    for(i=1;i<=N+1;i++)
    {
        for(j=1;j<=M;j++)
        {
            w=Scan();
            u=(i-1)*(M+1)+j;
            v=u+1;
            add_edge(u,v,w);
            //Insert(v,u,w);
        }
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M+1;j++)
        {
            //scanf("%d",&w);
            w=Scan();
            u=(i-1)*(M+1)+j;
            v=u+M+1;
            add_edge(u,v,w);
            //Insert(v,u,w);
        }
    }
	 for(i=0;i<N;i++){  
		
        for(j=0;j<M;j++){
            w=Scan();
            add_edge(i*M+j+1+nn1,i*(M+1)+j+1,w);
            w=Scan();
            add_edge(i*M+j+1+nn1,i*(M+1)+j+2,w);
        }
        for(j=0;j<M;j++){
            w=Scan();
            add_edge(i*M+j+1+nn1,(i+1)*(M+1)+j+1,w);
            w=Scan();
            add_edge(i*M+j+1+nn1,(i+1)*(M+1)+j+2,w);
        }
    }
}
void Solve()
{
    int ans=max_flow(vn1+1,scr1,sink1);
    printf("%d\n",ans);
}
int main()
{
	int N,M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init(N,M);
        Solve();
    }
	return 0;
}