////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 12:37:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
char p[20][20];
int map[20][20],x,y,w,count=0,flag=0,v;
void dfs(int k,int a,int b)
{
    
    if(a<0||b<0||a>=x||b>=y)
    {
        count=k;
        return;
    }
    if(k!=0&&a==0&&b==w-1)
    {
        v=1;
        flag=0;
        count=k;
        return;
    }
    if(map[a][b]!=0)
    {
        v=1;
        flag=map[a][b];
        count=k;
        return;
    }
        map[a][b]=k;
    if(p[a][b]=='W')
        dfs(k+1,a,b-1);
    else if(p[a][b]=='S')
        dfs(k+1,a+1,b);
    else if(p[a][b]=='E')
        dfs(k+1,a,b+1);
    else 
        dfs(k+1,a-1,b);
}
 
 
 
main ()
{
    int i;
    while(scanf("%d%d%d",&x,&y,&w)!=EOF)
    {
        if(x==0&&y==0&&w==0)
            break;
        for(i=0;i<x;i++)
            scanf("%s",p[i]);
        memset(map,0,sizeof(map));
        count=0;
        flag=0;
        v=0;
        dfs(0,0,w-1);
        if(v)
        {
            if(flag<=1&&count-flag<=1)
                printf("%d step(s) before a loop of %d step(s)\n",flag,count-flag);
            else if(flag<=1&&count-flag>1)
                printf("%d step(s) before a loop of %d step(s)\n",flag,count-flag);
            else if(flag>1&&count-flag>1)
                printf("%d step(s) before a loop of %d step(s)\n",flag,count-flag);
            else 
                printf("%d step(s) before a loop of %d step(s)\n",flag,count-flag);
        }
        else
        {
            if(count<=1)
                printf("%d step(s) to exit\n",count);
            else
                printf("%d step(s) to exit\n",count);
        }
    }
    return 0;
}
