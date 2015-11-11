////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-19 21:36:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3918
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define min(a,b) (a<b?a:b)
using namespace std;
//多边形切割
//可用于半平面交

#define eps 1e-7
#define zero(x) (((x)>0?(x):-(x))<eps)
struct pint
{
    double x,y;
    pint(double x, double y) : x(x), y(y){}
    pint(){}
}jeo[1000], le[1000], ri[1000];

double xmult(pint p1,pint p2,pint p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int same_side(pint p1,pint p2,pint l1,pint l2){
    return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

pint intersection(pint u1,pint u2,pint v1,pint v2){
    pint ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
            /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}

//将多边形沿l1,l2确定的直线切割在side侧切割,保证l1,l2,side不共线
void polygon_cut(int& n,pint* p,pint l1,pint l2,pint side){
    pint pp[310];
    int m=0,i;
    for (i=0;i<n;i++){
        if (same_side(p[i],side,l1,l2))
            pp[m++]=p[i];
        if (!same_side(p[i],p[(i+1)%n],l1,l2)&&!(zero(xmult(p[i],l1,l2))&&zero(xmult(p[(i+1)%n],l1,l2))))
            pp[m++]=intersection(p[i],p[(i+1)%n],l1,l2);
    }
    for (n=i=0;i<m;i++)
        if (!i||!zero(pp[i].x-pp[i-1].x)||!zero(pp[i].y-pp[i-1].y))
            p[n++]=pp[i];
    if (zero(p[n-1].x-p[0].x)&&zero(p[n-1].y-p[0].y))
        n--;
    if (n<3)
        n=0;
}



struct line{pint a,b;};



pint intersection(line u,line v){
    pint ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
            /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}


pint barycenter(pint a,pint b,pint c){
    line u,v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b=c;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b=b;
    return intersection(u,v);
}


//多边形重心
pint barycenter(int n,pint* p){
    pint ret,t;
    double t1=0,t2;
    int i;
    ret.x=ret.y=0;
    for (i=1;i<n-1;i++)
        if (fabs(t2=xmult(p[0],p[i],p[i+1]))>eps){
            t=barycenter(p[0],p[i],p[i+1]);
            ret.x+=t.x*t2;
            ret.y+=t.y*t2;
            t1+=t2;
        }
    if (fabs(t1)>eps)
        ret.x/=t1,ret.y/=t1;
    return ret;
}
int t, n, m, cnt, Y[1000];
int main()
{
	int i,j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        int mmin = -1;
        pint A, B;
        for(i = 0; i < n; i++)
        {
            int aa, bb; scanf("%d%d", &aa, &bb);
            le[i] = pint(aa, bb);
            Y[i] = bb;
        }
        A = le[0];
        mmin = Y[n - 1];
        for(int i = 0; i < m; i++)
        {
            int aa, bb; scanf("%d%d", &aa, &bb);
            ri[i] = pint(aa, bb);
            Y[n + i] = bb;
        }
        B = ri[0];
        mmin = min(mmin, Y[n + m - 1]);
        cnt = 0;
        for(i = 0; i < n; i++) jeo[cnt++] = le[i];
        for(i = m - 1; i >= 0; i--) jeo[cnt++] = ri[i];
        sort(Y, Y + n + m);
        double pre = Y[0] * 1.0;
        double myans = 0;
        for(i = 2; i < n + m && Y[i] <= mmin; i++)
        {
            double now = Y[i] * 1.0;
            for(j = 0; j < cnt; j++) le[j] = jeo[j];
            int tmpcnt = cnt;
            polygon_cut(tmpcnt,le,pint(-10000, now),pint(10000, now),pint(0, -10000));
            pint tar = barycenter(tmpcnt, le);
            if (tar.x - A.x >= -eps && B.x - tar.x >= -eps)
            {
                pre = now;
                if (now * 1.0 - myans > eps) myans = now * 1.0;
            }
            else
            {
                double l = pre, r = now;
                while(r - l >= eps)
                {
                    double mid = (l + r) * 0.5;
                    for(j = 0; j < cnt; j++) le[j] = jeo[j];
                    int tmpcnt = cnt;
                    polygon_cut(tmpcnt,le,pint(-10000, mid),pint(10000, mid),pint(0, -10000));
                    pint tar = barycenter(tmpcnt, le);
                    if (tar.x - A.x >= -eps && B.x - tar.x >= -eps)
                        l = mid;
                    else r = mid;
                }
                if (r - myans > eps) myans = r;
                break;
            }
        }
        printf("%.3f\n", myans);
    }
    return 0;
}