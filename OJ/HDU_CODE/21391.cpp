////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-29 16:48:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*n*(n+1)*(n+2)/6*/
#include <iostream>
int main()
{
    __int64 ans,n;
    int i;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n&1)
            ans=n*(n+1)*(n+2)/6;//Ҫ�����__int64��Ȼ�������� 
        printf("%I64d\n",ans);
    }
return 0;
}