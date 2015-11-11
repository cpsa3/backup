////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 12:41:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
    double c,s;
    int i;
    while(scanf("%lf",&c)!=EOF)
    {
        if(c==0.00)
            break;
        for(i=1,s=0;;i++)
        {
            s+=1.0/(i+1);
            if(s>=c)
                break;
        }
        printf("%d card(s)\n",i);
 
    }
return 0;
}
