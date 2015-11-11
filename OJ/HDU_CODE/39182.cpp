////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-19 23:51:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3918
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*几何模拟题+二分*/
/*最后的答案不用减去ll[0].y*/
/*从下往上枚举*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define MAXN 300
#define eps 1e-5
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct point {double x,y;};  
struct point pnt[MAXN],ll[MAXN],rr[MAXN],center;   
int N,M,l_pos,r_pos;  
double ans,H;
bool next;
//----------------------------------------------------------//   
// 求多边形重心   
// INIT: pnt[]已按顺时针(或逆时针)排好序;   
// CALL: res = bcenter(pnt, n);   
//----------------------------------------------------------//   
point bcenter(point pnt[], int n)
{   
    point p, s;   
    if(n==1) 
        return pnt[0];
    if(n==2)
    {
        s.x=(pnt[0].x+pnt[1].x)/2;
        s.y=(pnt[0].y+pnt[1].y)/2;
        return s;
    }
    double tp, area = 0, tpx = 0, tpy = 0;   
    p.x = pnt[0].x; p.y = pnt[0].y;   
    for (int i = 1; i <= n; ++i) 
    {   // point: 0 ~ n-1   
        s.x = pnt[(i == n) ? 0 : i].x;   
        s.y = pnt[(i == n) ? 0 : i].y;   
        tp = (p.x * s.y - s.x * p.y); area += tp / 2;   
        tpx += (p.x + s.x) * tp; tpy += (p.y + s.y) * tp;   
        p.x = s.x; p.y = s.y;   
    }   
    s.x = tpx / (6 * area); s.y = tpy / (6 * area);   
    return s;   
}  
void Print()
{
    int i;
    printf("-------------------------------------\n");
    for(i=0;i<M;i++)
        printf("%.2lf %.2lf\n",ll[i].x,ll[i].y);
    for(i=0;i<N;i++)
        printf("%.2lf %.2lf\n",rr[i].x,rr[i].y);
    printf("-------------------------------------\n");
}
point get_point(point c,point a,point b)
{
    point res;
    double dx,dy;
    dx=fabs(a.x-b.x);
    dy=b.y-a.y;
    
    res.y=c.y;
    if(fabs(a.x-b.x)<=eps)
        res.x=a.x;
    else
    {
        if(a.x<b.x)
            res.x=dx*(c.y-a.y)*1.0/dy+a.x;
        else
            res.x=a.x-dx*(c.y-a.y)*1.0/dy;
    }
    return res;
}
void ini()
{
    M=N=0;
    l_pos=r_pos=0;
    ans=H=0;
    memset(pnt,0,sizeof(pnt));
    memset(ll,0,sizeof(ll));
    memset(rr,0,sizeof(rr));
}
void Init()
{
    int i;
    ini();
    scanf("%d%d",&M,&N);
    for(i=0;i<M;i++)
        scanf("%lf%lf",&ll[i].x,&ll[i].y);
    for(i=0;i<N;i++)
        scanf("%lf%lf",&rr[i].x,&rr[i].y);
    //Print();
    //Go();
}
bool Judge(point o)
{
	if((o.x-ll[0].x>=eps)&&(rr[0].x-o.x>=eps))
		return true;
	return false;
}
bool fuck(double mid,int l_pos,int r_pos)
{
    int i;
    point temp,now1,now2;
    temp.x=1;temp.y=mid;
    int cnt=0;
    
    if(fabs(ll[l_pos].y-rr[r_pos].y)<=eps)
    {
        for(i=l_pos;i>=0;i--)
            pnt[cnt++]=ll[i];
        for(i=0;i<=r_pos;i++)
            pnt[cnt++]=rr[i];
        //pnt[cnt++]=now2;
    }
    
    else if(ll[l_pos].y<rr[r_pos].y)
    {
        now1=get_point(temp,ll[l_pos],ll[l_pos+1]);
        now2=get_point(temp,rr[r_pos-1],rr[r_pos]);
        pnt[cnt++]=now1;
        for(i=l_pos;i>=0;i--)
            pnt[cnt++]=ll[i];
        for(i=0;i<r_pos;i++)
            pnt[cnt++]=rr[i];
        pnt[cnt++]=now2;
    }
    else
    {
        now1=get_point(temp,ll[l_pos-1],ll[l_pos]);
        now2=get_point(temp,rr[r_pos],rr[r_pos+1]);
        pnt[cnt++]=now1;
        for(i=l_pos-1;i>=0;i--)
            pnt[cnt++]=ll[i];
        for(i=0;i<=r_pos;i++)
            pnt[cnt++]=rr[i];
        pnt[cnt++]=now2;
        
    }
    /*
    for(i=0;i<cnt;i++)
    printf("%.2lf %.2lf\n",pnt[i].x,pnt[i].y);
    printf("**\n");
    //sort(pnt,pnt+cnt);
    */
    center=bcenter(pnt,cnt);
    return Judge(center);
}

void Solve()
{
    ans=ll[0].y;;
    double l,r,mid;
    int i,cnt;
    point now;
	l_pos=r_pos=1;
	//printf("*****%.2lf %.2lf\n",ll[l_pos].y,rr[r_pos].y);
	//Print();
    while(true)
    {
        cnt=0;
        if(l_pos==M||r_pos==N) break;
        if(ll[l_pos].y<=rr[r_pos].y)
        {
            for(i=l_pos;i>=0;i--)
                pnt[cnt++]=ll[i];
            for(i=0;i<r_pos;i++)
                pnt[cnt++]=rr[i];
            now=get_point(ll[l_pos],rr[r_pos-1],rr[r_pos]);
            pnt[cnt++]=now;
            center=bcenter(pnt,cnt);//求当前重心
            
            next=Judge(center);
            if(!next)//枚举到一个不合理
            {
                
                l=max(rr[r_pos-1].y,ll[l_pos-1].y);r=ll[l_pos].y;//小心下限
                //printf("^^^^%d %d %.2lf %.2lf \n",l_pos,r_pos,l,r);
                while(fabs(l-r)>eps)
                {
                    mid=(l+r)/2.0;
                    if(fuck(mid,l_pos,r_pos-1))
                        l=mid;
                    else
                        r=mid;
                }
                ans=max(ans,l);
                break;
            }
            else
			{
				ans=max(ans,ll[l_pos].y);
				//printf("%.3lf %.3lf\n",ans,ll[l_pos].y);
				l_pos++;
			}
        }
        else
        {
            now=get_point(rr[r_pos],ll[l_pos-1],ll[l_pos]);
            pnt[cnt++]=now;

            for(i=l_pos-1;i>=0;i--)
                pnt[cnt++]=ll[i];
            for(i=0;i<=r_pos;i++)
                pnt[cnt++]=rr[i];
            center=bcenter(pnt,cnt);//求当前重心
            next=Judge(center);
            if(!next)
            {
                l=max(ll[l_pos-1].y,rr[r_pos-1].y);r=rr[r_pos].y;
                while(fabs(l-r)>eps)
                {
                    mid=(l+r)/2.0;
                    if(fuck(mid,l_pos-1,r_pos))
                        l=mid;
                    else
                        r=mid;
                }
                ans=max(ans,l);
                break;
            }
            else
			{
                
				ans=max(ans,rr[r_pos].y);
				r_pos++;
			}
        }
    }
    
    printf("%.3lf\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
    return 0;
}
/*
1
3 3
1 1 3 2 -2 5
3 1 6 2 -2 6
1.760

*/