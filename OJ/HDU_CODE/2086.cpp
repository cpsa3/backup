////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 21:26:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:718MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
    int n,i,j;
    double c[3001],x,y;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lf%lf",&x,&y);
        for(i=1;i<=n;i++)
            scanf("%lf",&c[i]);
        double s=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                s+=c[j];
        }
        double ans;
        ans=(n*x*1.0+y-2*1.0*s)*1.0/(n+1);
        printf("%.2lf\n",ans);
    }
return 0;
}