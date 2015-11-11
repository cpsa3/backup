////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 13:30:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
#define N 10000000
int ff[10010];
int min(int x,int y)
{
    return x<=y?x:y;
}
main ()
{
    int t,e,f,n,p,v[501],w[501],i,j;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d",&e,&f);
            p=f-e;
            scanf("%d",&n);
            for(i=0;i<n;i++)
                scanf("%d%d",&v[i],&w[i]);
            for(i=0;i<=p;i++)
                ff[i]=N;
            ff[0]=0;
            for(i=0;i<n;i++)
                for(j=w[i];j<=p;j++)
                    ff[j]=min(ff[j],ff[j-w[i]]+v[i]);
                if(ff[p]==N)
                    printf("This is impossible.\n");
                else
                    printf("The minimum amount of money in the piggy-bank is %d.\n",ff[p]);
        }
    }
return 0;
}
