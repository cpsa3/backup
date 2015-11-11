////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-09 20:58:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3868
////Problem Title: 
////Run result: Accept
////Run time:781MS
////Run memory:544KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define EPS 0.00000001
#define INF 999999999

using namespace std;

struct Point
{
    double x,y;
}a[20005];

int n;

int cmp(const struct Point &s,const struct Point &t) //sorto°•®∫y
{
    if((t.x - s.x) >= EPS)
        return 1;
    else if(fabs(s.x - t.x) < EPS)
    {
        if((t.y - s.y) >= EPS)
            return 1;
        else return 0;
    }else return 0;
}

double dis(int i,int j)
{
    return sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y));
}
double cross(Point p0,Point p1,Point p2)
{
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double cal(int l,int r)
{
    if(l == r)
        return INF;
    if(l + 1 == r)
        return INF;
    if(l + 2 == r)
    {
        return (dis(l,r) + dis(l,l + 1) + dis(l + 1,r));
    }
    int mid = (l + r)/2;
    double ans = INF;
    ans = min(ans,min(cal(l,mid),cal(mid + 1,r)));
    for(int i = mid; i >= l; --i)
    {
        if((fabs(a[i].x - a[mid].x) - ans) > INF)
                break;
        for (int j = i - 1; j >= l && j >= i - 5; --j)
        {
            double d = dis(i,j);
            if((fabs(d - ans) > INF))
                break;
            for(int k = mid + 1; k <= r && k <= mid + 5; ++k)
            {
                ans = min(ans,d + dis(j,k) + dis(i,k));
            }
        }
        for (int j = mid + 1; j <= r && j <= mid + 5; ++j)
        {
            double d = dis(i,j);
            if((fabs(d - ans) > INF))
                break;
            for(int k = j + 1; k <= r && k <= j + 5; ++k)
            {
                ans = min(ans,d + dis(j,k) + dis(i,k));
            }
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while( T-- )
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a + 1, a + n + 1,cmp);
        printf("%.3f\n",cal(1,n));
    }
    return 0;
}

