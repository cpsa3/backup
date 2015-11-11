////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 12:35:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
struct px
{
    int j;
    int f;
    double b;
};
 
struct px stu[1000],t;
main ()
{
    
    int m,n,i,j;
    double sum;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==-1&&n==-1)
            break;
        
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&stu[i].j,&stu[i].f);
            stu[i].b=stu[i].j*1.0/stu[i].f;
 
        }
        if(m==0||n==0)
        {printf("0.000\n");continue;}
 
        for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
                if(stu[j].b<stu[j+1].b)
                {t=stu[j];stu[j]=stu[j+1];stu[j+1]=t;}
        for(i=0,sum=0;i<n;i++)
        {
            if(m>stu[i].f)
            {    sum+=stu[i].j;
            m-=stu[i].f;
            }
            else
            {
                sum+=stu[i].j*1.0*m/stu[i].f;
                m=0;
            
            
            }
            if(m==0)
                break;
        }
 
        printf("%.3lf\n",sum);
    }
 
return 0;
}
