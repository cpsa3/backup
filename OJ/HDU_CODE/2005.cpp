////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:23:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int f(int a)
{
    if((a%4==0&&a%100!=0)||(a%400==0))
        return 1;
    else 
        return 0;
    
    
    }

int main ()
{
    int t,a[10000][4],i,m;
    i=1;
    while(scanf("%d/%d/%d",&a[i][0],&a[i][1],&a[i][2])!=EOF)
    { 
        switch(a[i][1])
            {    
            case 1:m=0;break;
            case 2:m=31;break; 
            case 3:m=59;break;
            case 4:m=90;break;
            case 5:m=120;break;
            case 6:m=151;break;
            case 7:m=181;break;
            case 8:m=212;break;
            case 9:m=243;break;
            case 10:m=273;break;
            case 11:m=304;break;
            case 12:m=334;break;
            }
        if(f(a[i][0])&&(a[i][1]>2))
            m++;
        m=m+a[i][2];
        a[i][3]=m;
  printf("%d\n",a[i][3]);
    }
return 0;
}