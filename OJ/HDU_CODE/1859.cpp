////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-20 23:36:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
    int i,j;
    int  m[10000],n[10000];
    while(scanf("%d%d",&m[0],&n[0])!=EOF)
    {   i=1;
        int max1,max2,min1,min2;
        if(m[0]==0&&n[0]==0) 
            break;
    
 
            do{
                scanf("%d%d\n",&m[i],&n[i]);
                    i++;
            }while((m[i-1]!=0||n[i-1]!=0));
            max1=m[0];
            min1=m[0];
             max2=n[0];
            min2=n[0];
            for(j=1;j<i-1;j++)
            {
                 if(m[j]>max1)   max1=m[j];
                 if(m[j]<min1)   min1=m[j];
                 if(n[j]>max2)   max2=n[j];
                 if(n[j]<min2)   min2=n[j];
            }
            printf("%d %d %d %d\n",min1,min2,max1,max2);
        
    }
}
