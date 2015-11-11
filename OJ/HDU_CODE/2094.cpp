////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 21:23:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <string.h>
struct px
{
    char w[20];
};
struct px a[2001],b[1001];
int cmp(const void *x,const void *y)
{
    return strcmp(((struct px *)x)->w,((struct px *)y)->w);    
}
main ()
{
    int t,i;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0) break;
        for(i=1;i<=2*t;i++)
        {
            scanf("%s",a[i].w);
            if(i%2==0)
                strcpy(b[i/2].w,a[i].w);
        }
        qsort(a+1,2*t,sizeof(a[0]),cmp);
        qsort(b+1,t,sizeof(b[0]),cmp);
        char v[20];

        strcpy(v,a[1].w);
        int c=1;
        for(i=2;i<=2*t;i++)
        {
            if(!strcmp(v,a[i].w))
                continue;
            else 
            {
                c++;
                strcpy(v,a[i].w);
            }
            if(i==2*t) break;
        }

        strcpy(v,b[1].w);
        int d=1;
        for(i=2;i<=t;i++)
        {
            if(!strcmp(v,b[i].w))
                continue;
            else 
            {
                d++;
                strcpy(v,b[i].w);
            }
            if(i==t) break;
        }
        if(c-d==1)
            printf("Yes\n");
        else 
            printf("No\n");    
    }
return 0;    
}