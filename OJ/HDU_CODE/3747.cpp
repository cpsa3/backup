////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-25 19:56:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3747
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
char a[100],b[100],c[100];
int main()
{
    int N,ans,t,i;
    while(scanf("%d",&N)!=EOF)
    {
        scanf("%s%s",a,b);
        strcpy(c,a);
        int ans=0;
        for(i=0;i<N;i++)//直接点
        {
            if(a[i]!=b[i])
                ans++;
        }
        t=1;//先反
        for(i=0;i<N;i++)
        {
            if(c[i]=='0')
                c[i]='1';
            else
                c[i]='0';
        
        }
        for(i=0;i<N;i++)
        {
            if(c[i]!=b[i])
                t++;
        }
        if(t<ans)
            ans=t;
        t=1;//先全
        for(i=0;i<N;i++)
            c[i]='1';
        for(i=0;i<N;i++)
        {
            if(c[i]!=b[i])
                t++;
        }
        if(t<ans)
            ans=t;
        for(i=0;i<N;i++)//线圈再犯
            c[i]='0';
        t=2;
        for(i=0;i<N;i++)
        {
            if(c[i]!=b[i])
                t++;
        }
        if(t<ans)
            ans=t;
        printf("%d\n",ans);
    }
return 0;
}