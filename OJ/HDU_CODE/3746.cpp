////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 19:56:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3746
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:716KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
char s[100005];
int next[100005];
int len;
void get_next()
{
    int i=1,t;
    next[0]=-1;
    while(i<=len)
    {
        t=next[i-1];
        while((t+1)&&s[t+1]!=s[i])
            t=next[t];
        next[i]=t+1;
        //printf("%d ",next[i]);
        i++;
    }
}
int main()
{
    int N,w,c;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",s+1);
        len=strlen(s+1);
        get_next();
        int ans=next[len];
        c=len-ans;
        if(c==len)
        {printf("%d\n",c);continue;}
        if(len%c==0)
            printf("0\n");
        else
            printf("%d\n",c-len%c);
    }
    return 0;
}