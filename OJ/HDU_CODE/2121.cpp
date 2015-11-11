////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-03 20:09:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2121
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:472KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1010
#define MAXE 10000
#define min(a,b) (a<b?a:b)
typedef __int64 typec;
const typec INF =(((__int64)(1))<<50);

struct Arcs {
    int _a, _b;
} arcs[MAXE + MAXN];

struct AdjNode {
    int _v;
    Arcs *_rf;
    typec _c;
    AdjNode *_next;
} *adj[MAXN], adjmem[MAXE + MAXN];

int adjcnt;

inline void init(int n) {
    memset(adj, 0, n * sizeof(AdjNode*));
    adjcnt = 0;
}

inline void add_edge(int a, int b, typec c) {   // arcs form a to b
    arcs[adjcnt]._a = a; arcs[adjcnt]._b = b;
    AdjNode *ptr = adjmem + adjcnt++;
    ptr->_c = c; ptr->_v = a;
    ptr->_rf = arcs + adjcnt - 1;
    ptr->_next = adj[b]; adj[b] = ptr;
}

int pre[MAXN], real_pre[MAXN];
bool is_out[MAXN];
int vis[MAXN], vcnt;

typec solve(int n, int root) {
    static typec ch[MAXN];
    memset(is_out, false, n);
    typec ans = 0;
    while (true) {
        int i, j, k;
        for (i = 0; i < n; ++i)
            if (i != root && !is_out[i]) {
                pre[i] = i;
                ch[i] = INF;
                AdjNode *chp;
                for (AdjNode *ptr = adj[i]; ptr; ptr = ptr->_next) {
                    j = ptr->_v;
                    if (!is_out[j]) {
                        if (ch[i] > ptr->_c) {
                            pre[i] = j;
                            ch[i] = ptr->_c;
                            chp = ptr;
                        } else if (           // choose the min number node as root
                            ch[i] == ptr->_c && ptr->_rf->_a == root
                            && ptr->_rf->_b < chp->_rf->_b
							) {
                            pre[i] = j;
                            chp = ptr;
                        }
                    }
                }
                if (pre[i] == i) throw false;
                real_pre[chp->_rf->_b] = chp->_rf->_a;
            }
			memset(vis, 0, n * sizeof(int));
			vcnt = 0;
			for (i = 0; i < n; ++i)
				if (i != root && !is_out[i]) {
					j = i;
					vis[i] = ++vcnt;
					while (vis[pre[j]] == 0 && pre[j] != root) {
						j = pre[j];
						vis[j] = vcnt;
					}
					if (vis[pre[j]] == vcnt) {
						i = pre[j];
						break;
					}
				}
				if (i == n) {
					for (j = 0; j < n; ++j)
						if (j != root && !is_out[j])
							ans += ch[j];
						break;
				}
				j = i; ++vcnt;
				int ti = i;
				do {
					ti = min(ti, j);
					vis[j] = vcnt;
					is_out[j] = true;
					ans += ch[j];
					j = pre[j];
				} while (j != i);
				i = ti;
				for (j = 0; j < n; ++j)
					if (vis[j] == vcnt)
						for (AdjNode **ptr = adj + j; *ptr; ) {
							k = (*ptr)->_v;
							if (!is_out[k]) {
								AdjNode *p2 = *ptr;
								p2->_c -= ch[j];
								if (i != j) {
									*ptr = p2->_next;       // del from adj[j]
									p2->_next = adj[i];       // add to adj[i]
									adj[i] = p2;
								} else
									ptr = &(p2->_next);
							} else
								ptr = &((*ptr)->_next);
						}
						for (k = 0; k < n; ++k)
							if (!is_out[k])
								for (AdjNode *ptr = adj[k]; ptr; ptr = ptr->_next) {
									j = ptr->_v;
									if (vis[j] == vcnt)
										ptr->_v = i;
								}
								is_out[i] = false;
    }
    return ans;
}

int main() {
    int n, m,i;
    while (scanf("%d%d", &n, &m) != EOF) {
        init(n + 1);
        typec s = 1;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (a != b) {
                add_edge(a, b, c);
                s += c;
            }
        }
        for (i = 0; i < n; ++i)
            add_edge(n, i, s);
		
        typec ans = solve(n + 1, n);
        int r, p;
        for (r = 0; real_pre[r] != n; ++r)
            ;
        for (p = r + 1; p < n; ++p)
			if (real_pre[p] == n)
				break;
			if (p == n)
				printf("%I64d %d\n\n", ans - s, r);
			else
				puts("impossible\n");
    }
    return 0;
}
