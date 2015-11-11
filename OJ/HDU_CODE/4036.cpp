////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-12 20:15:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4036
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
struct line{
    double len;
    double x1,x2,y1,y2;
}l[1005];
double f(int j,double v,double x)
{
    double h=(l[j].y1-l[j].y2)*(x-l[j].x2)/(l[j].x1-l[j].x2)+l[j].y2;
    if((v*v+2*20*(h-l[0].y1)<0))
        return 0;
    else
    return sqrt(v*v+2*20*(h-l[0].y1));
}
double _max(double a,double b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    int n,m,w;
    int i,j,k;
    double x1,x2,y1,y2;
    double h;
    double  v,w1;
    double _minv;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>m>>w;
        cin>>x1>>y1;
        h=y1;
        for(j=0;j<n-1;j++)
        {
            cin>>x2>>y2;
            l[j].x1=x1;
            l[j].x2=x2;
            l[j].y1=y1;
            l[j].y2=y2;            
            l[j].len=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            x1=x2;
            y1=y2;
            h=_max(h,y2);        
        }
        _minv=sqrt((h-l[0].y1)*2*20);
        for(k=0;k<m;k++)
        {
            cin>>x1>>v>>w1;            
            for(j=0;j<n-1;j++)
            {
                if(x1>=l[j].x1&&x1<l[j].x2)
                {
                    _minv=_max(_minv,f(j,v,x1));
                }
            }
        }
        printf("Case %d: %.2lf\n",i,_minv);

    }
    return 0;
}