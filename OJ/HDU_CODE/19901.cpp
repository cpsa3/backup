////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 20:49:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1990
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<iostream>
char str[160];
int level;
int mypow(int a,int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
    {
        __int64
            t=mypow(a,n/2);
        return t*t;
    }
    else
    {
        __int64 t;
        t=mypow(a,n/2);
        return (t*t)*a;
    }
}

void dfs(int s,int t,int le)
{
    if(le>level)
        level=le;
    int i;
    int a=1,b;
    for(i=s+2;i<t;i++)
    {
        if(str[i]=='[')
            a++;
        else if(str[i]==']')
            a--;
        if(a==0)
        {
            dfs(s+1,i,le+1);
            break;
        }
    }
    if(i<t-1)
    {
        dfs(i+1,t-1,le+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int ca=0;
    while(n--)
    {
        gets(str);
        level=0;
		printf("%d ",++ca);
        if(strlen(str)==0)
        {
            printf("1\n");
            continue;
        }
        dfs(0,strlen(str)-1,1);
        printf("%d\n",mypow(2,level));
    }
    return 0;
}
