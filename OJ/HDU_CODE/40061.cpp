////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-04 00:03:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4006
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:592KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    multiset<int> M;
    int a,b,d,i;
    char c[2];
    while(scanf("%d%d",&a,&b)!=EOF)
    {
		M.clear();
        for(i=0;i<a;i++)
        {
            scanf("%s",c);
            if(c[0]=='I')
            {
                scanf("%d",&d);
                M.insert(d);
                if(i>b-1) M.erase(M.begin());
            }
            else printf("%d\n",*M.begin());
        }
    }
    return 0;
}