////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-29 20:18:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:3218MS
////Run memory:55212KB
//////////////////System Comment End//////////////////
#include<iostream>
#define ll __int64
#define INF 2100000000
#define PN 502000
#define EN 3002000
#define inf 2000000000
#define MAXN 500
#define typec int // type of cost
const int N = 600000 , E = 3000000;
struct edge {
    int x, y, nxt;
    typec c;
} bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
int scr1,sink1,vn1,nn1;
void Insert(int x, int y, typec c) { // add an arc(x -> y, c); vertex: 0 ~ n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = c;
    bf[ne].nxt = head[y];
    head[y] = ne++;
}
int mi,mj,Mi,Mj,S,T,myN;
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

inline f_min(int x,int y){
    return x<y?x:y;
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
void get_graph(int N,int M){
    ne = 2;
    memset(head, 0, sizeof(head));
	int i,j,u,v,w,px,py;
     nn1=(N+1)*(M+1);
    scr1=1;sink1=nn1;vn1=nn1+(N*M);
    //Ω®Õº
    for(i=1;i<=N+1;i++)
    {
        for(j=1;j<=M;j++)
        {
            w=Scan();
            u=(i-1)*(M+1)+j;
            v=u+1;
            Insert(u,v,w);
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
            Insert(u,v,w);
            //Insert(v,u,w);
        }
    }
    for(i=1;i<=2*N;i++)
    {
        for(j=1;j<=2*M;j++)
        {
            //scanf("%d",&w);
            w=Scan();
            px=(i+1)>>1;
            py=(j+1)>>1;
            v=(px-1)*M+py+nn1;
            u=(px-1)*(M+1)+py;
            if((i%2)&&(j%2==0)) u++;
            else if((i%2==0)&&(j%2)) u+=(M+1);
            else if((i%2==0)&&(j%2==0)) u+=(M+2);
            Insert(u,v,w);
            //Insert(v,u,w);
        }
    }
}
void run(){
    printf("%d\n",max_flow(vn1+1,scr1,sink1));
}
int main(){
	int N,M;
    while(scanf("%d%d",&N,&M)!=EOF){
        get_graph(N,M);
        run();
    }
    return 0;
}
