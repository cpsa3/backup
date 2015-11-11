////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:01:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s[10000];
    int i,j,cnt=1;
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"STOP")==0) break;
        int len = strlen(s);
        bool ok=true;
        for(i=0,j=len-1;i<len;i++,j--)
        {
            if(s[i]!=s[j])
            {
                ok=false;
                break;
            }
        }
        printf("#%d: ",cnt++);
        if(ok)
            printf("YES\n");
        else 
            printf("NO\n");
    }
return 0;
}