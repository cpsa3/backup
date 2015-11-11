////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 13:30:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *x,const void *y)
{
    return *((int *)y)-*((int *)x);
}
main ()
{
    int n[1000],a[100],i;
    int k;
    k=1;
    while(scanf("%d",&n[k])!=EOF)
    {
        if(n[k]==0) break;
        int s=0;
        for(i=1;i<=n[k];i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        int m;
        m=s/n[k];
        qsort(a+1,n[k],sizeof(int),cmp);
            int w=0;
        for(i=1;i<=n[k];i++)
        {
            if(a[i]>m)
                w+=(a[i]-m);
            else break;
        }
        if(k==1)
        printf("%d\n",w);    
        else printf("\n%d\n",w);
        k++;
    }
return 0;    
}