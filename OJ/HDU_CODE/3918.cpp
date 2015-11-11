////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-19 21:23:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3918
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

double zo(double x)
{
    return fabs(x)<1e-12?0:x;
}
const int N=222;

struct pt
{
    double x,y;
    pt(double a=0,double b=0){x=a,y=b;}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    double operator*(pt p){return x*p.y-y*p.x;}
}p[N],q[N];
int l,r;
double sumx,sum;

void add(pt a,pt b,pt c,double &x,double &s)
{
    double dx=a.x+b.x+c.x,ds=(b-a)*(c-a);
    x+=dx*ds;
    s+=ds;
}

double g(pt m,pt n)
{
    double x=sumx,s=sum;

    pt a=p[1],b=q[r],c=n;
    add(a,b,c,x,s);

    b=m,c=p[l];
    if(l>1)
        add(a,b,c,x,s);

    b=n,c=m;
    add(a,b,c,x,s);
    return x/s;
}

double x1,x2;
bool yes(double x)
{
    x/=3;
    return zo(x-x1)>=0&&zo(x-x2)<=0;
}

void get(pt a,pt b,pt c,pt d,pt &ans)
{
    double a1=b.y-a.y,b1=b.x-a.x,c1=b.x*a.y-a.x*b.y;
    double a2=d.y-c.y,b2=d.x-c.x,c2=d.x*c.y-c.x*d.y;
    ans.x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
    ans.y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
}

int main()
{
    int tt;
    for(scanf("%d",&tt);tt--;)
    {
        int n,m,i;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(i=1;i<=m;i++)
            scanf("%lf%lf",&q[i].x,&q[i].y);
        x1=p[1].x,x2=q[1].x;


        l=r=1;
        sumx=sum=0;
        double ans=0;
        while(l<n&&r<m)
        {
            int tl,tr;
            double x,s,now;
            if(p[l+1].y<q[r+1].y)
            {
                tl=l+1,tr=r;
                pt p0;
                get(p[tl],pt(p[tl].x+1,p[tl].y),q[r],q[r+1],p0);
                now=g(p[tl],p0);
            }
            else if(p[l+1].y>q[r+1].y)
            {
                tl=l,tr=r+1;
                pt p0;
                get(p[l],p[l+1],q[tr],pt(q[tr].x+1,q[tr].y),p0);
                now=g(p0,q[tr]);
            }
            else
            {
                tl=l+1,tr=r+1;
                now=g(p[tl],q[tr]);
            }
            if(yes(now))
            {
                if(tl>l)
                {
                    add(p[1],p[tl],p[l],sumx,sum);
                    l=tl;
                }
                if(tr>r)
                {
                    add(p[1],q[r],q[tr],sumx,sum);
                    r=tr;
                }
                ans=max(p[l].y,q[r].y);
                continue;
            }

            double lt=max(p[l].y,q[r].y),rt=min(p[l+1].y,q[r+1].y);
            while(zo(lt-rt)<0)
            {
                double mid=(lt+rt)/2;
                pt p1,p2;
                get(p[l],p[l+1],pt(0,mid),pt(1,mid),p1);
                get(q[r],q[r+1],pt(0,mid),pt(1,mid),p2);
                now=g(p1,p2);
                if(yes(now))
                    lt=mid;
                else
                    rt=mid;
            }
            ans=lt;
            break;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
