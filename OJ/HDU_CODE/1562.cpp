////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:16:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1562
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;

int a,b,c;
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=-1;
        for(i=1000;i<=9999;i++)
        {
            if(i%a==0&&(i+1)%b==0&&(i+2)%c==0)
            {ans=i;break;}
        }
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
return 0;
}
