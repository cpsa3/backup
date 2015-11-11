////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-05 19:27:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <math.h>
using namespace std;
main ()
{
    int t,x1,y1,x2,y2,i;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int n,m;
            n=x1+y1;
            m=x2+y2;
            double s=0;
            if(n<m)
            {
                for(i=n;i<m;i++)
                    s+=sqrt((i*i+(i+1)*(i+1))*1.0);
                for(i=n+1;i<=m-1;i++)
                s+=sqrt(2.0)*i;
                s+=sqrt((y1*y1+(x1-n)*(x1-n))*1.0);
                s+=sqrt((x2*x2+(m-y2)*(m-y2))*1.0);
            }
            else if(n>m)
            {
                for(i=m;i<n;i++)
                    s+=sqrt((i*i+(i+1)*(i+1))*1.0);
                for(i=m+1;i<=n-1;i++)
                s+=sqrt(2.0)*i;
                s+=sqrt((y2*y2+(x2-m)*(x2-m))*1.0);
                s+=sqrt((x1*x1+(n-y1)*(n-y1))*1.0);

            }
            else 
            {
                s+=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*1.0);
            }

            printf("%.3lf\n",s);
        }
    }
return 0;
}