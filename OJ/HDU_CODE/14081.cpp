////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 22:51:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
    double v,d;
    int i,s;
    while(scanf("%lf%lf",&v,&d)!=EOF)
    {
        s=v/d;
        if(s<v/d) s++;
        for(i=1;v>0;i++)
            v-=i*d;
        printf("%d\n",s+i-2);
    }
return 0;
}