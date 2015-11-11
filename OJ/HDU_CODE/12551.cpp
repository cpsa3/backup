////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-18 11:36:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1255
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:680KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define maxn 2200


double tmp[maxn], bin[maxn];
int tmpsize, size;


struct Tree {
    int p;
    int l, r;
    int nCover;
    double ylenOnce, ylenMore;

    void Update() {
        if(nCover > 1) {
            ylenOnce = 0;
            ylenMore = bin[r] - bin[l];
        }else if(nCover == 1) {
            ylenMore = T[p<<1].ylenMore   +   T[p<<1].ylenOnce
                       + T[p<<1|1].ylenMore + T[p<<1|1].ylenOnce;            
            
            ylenOnce = (bin[r] - bin[l]) - ylenMore;
        }else {
            if(l + 1 == r) {
                ylenOnce = ylenMore = 0;
            }else {
                ylenOnce = T[p<<1].ylenOnce + T[p<<1|1].ylenOnce;
                ylenMore = T[p<<1].ylenMore + T[p<<1|1].ylenMore;
            }
        }
    }
}T[maxn*4];

struct VLine {
    double x;
    double y1, y2;
    int val;
    VLine() {}
    VLine(double _x, double _y1, double _y2, int _v) {
        x = _x;
        y1 = _y1;
        y2 = _y2;
        val = _v;
    }
};
vector < VLine > Vl;

bool cmp(VLine a, VLine b) {
    return a.x < b.x;
}

void Process() {
    sort(tmp, tmp + tmpsize);
    bin[ size = 1 ] = tmp[0];
    for(int i = 1; i < tmpsize; i++) {
        if(fabs(tmp[i] - tmp[i-1]) > 1e-6)
            bin[ ++size ] = tmp[i];
    }
}

int Binary(double v) {
    int l = 1;
    int r = size;

    while(l <= r) {
        int m = (l + r) >> 1;
        if(fabs(v - bin[m]) < 1e-6)
            return m;
        if(v > bin[m])
            l = m + 1;
        else
            r = m - 1;
    }
}

void Build(int p, int l, int r) {
    T[p].l = l;      T[p].r = r;
    T[p].p = p;
    T[p].nCover = 0; T[p].ylenOnce = T[p].ylenMore = 0;

    if(l + 1 == r || l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    Build(p<<1, l, mid);
    Build(p<<1|1, mid, r);
}

void Insert(int p, int l, int r, int val) {

    if(r <= T[p].l || l >= T[p].r)
        return ;

    if(l <= T[p].l && T[p].r <= r) {
        T[p].nCover += val;
        T[p].Update();
        return ;
    }

    Insert(p<<1, l, r, val);
    Insert(p<<1|1, l, r, val);
    
    T[p].Update();
}
int n;
int main() {
    int t;
    int i;
    scanf("%d", &t);
    while(t--) {
        tmpsize = 0;
        Vl.clear();
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            double x0, x1, y0, y1;
            scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);
            Vl.push_back(VLine(x0, y0, y1, 1));
            Vl.push_back(VLine(x1, y0, y1, -1));
            tmp[ tmpsize++ ] = y0;
            tmp[ tmpsize++ ] = y1;
        }

        sort(Vl.begin(), Vl.end(), cmp);
        Process();
        Build(1, 1, size);
        double ans = 0;
        for(i = 0; i < Vl.size(); i++) {
            if(i) {
                ans += (Vl[i].x - Vl[i-1].x) * T[1].ylenMore;
            }
            int y1 = Binary(Vl[i].y1);
            int y2 = Binary(Vl[i].y2);
            if(y1 < y2)
                Insert(1, y1, y2, Vl[i].val);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}