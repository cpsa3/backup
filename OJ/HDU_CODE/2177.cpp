////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:09:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2177
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define t 1.618033989
using namespace std;
int main()
{
    int i,a,b,c;
    while(scanf("%d%d",&a,&b))
    {
        if(a==0&&b==0)
            break;
        int k=b-a;
        c=(int)(k*t);
        if(a==c) printf("0\n");
        else
        {
            printf("1\n");
            if(!a) printf("0 0\n");
            if(a>=c&&b>=c) printf("%d %d\n",c,c+k);
            for(i=1;i<=b;i++)
            {
                if(a==(int)(i*t)&&b>=a+i&&i!=k)
                    printf("%d %d\n",a,a+i);
                if(b==(int)(i*t)+i&&a>=b-i&&i!=k)
                    printf("%d %d\n",b-i,b);
                else if(a==(int)(i*t)+i&&b>=a&&i!=k)
                    printf("%d %d\n",a-i,a);
            }
        }
    }
    return 0;
}