////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-06 13:30:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 10
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int flag,di,dj,T,m,n;
char str[N][N];
void dfs(int si,int sj,int t)
{
    int i,temp;
    if(si==di&&sj==dj&&t==T)
    {
        flag=1;
        return ;
    }
    if(si<0||si>=m||sj<0||sj>=n)
        return ;
    temp=T-t-abs(si-di)-abs(sj-dj);
    if(temp<0||temp%2!=0)        //奇偶剪枝,剪枝3
        return ;
    for(i=0;i<4;i++)
    {
  //千万要注意的是节点越界的情况, dfs(int si,int sj,int t)的时候一定要把 si, sj 控制在给你的矩阵内
        if(si+dir[i][0]>=0&&si+dir[i][0]<m&&sj+dir[i][1]>=0&&sj+dir[i][1]<n)
        if(str[si+dir[i][0]][sj+dir[i][1]]!='X')
        {
            str[si+dir[i][0]][sj+dir[i][1]]='X';
            dfs(si+dir[i][0],sj+dir[i][1],t+1);
            if(flag)  return ;
            str[si+dir[i][0]][sj+dir[i][1]]='.';    //搜索失败，恢复原数据
        }
    }
    return ;
}
int main()
{
    int i,j,si,sj,t,num;
    while(scanf("%d%d%d",&m,&n,&T)!=EOF)
    {
        getchar();
        if(m==0&&n==0&&T==0)
            break;
        num=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&str[i][j]);
                if(str[i][j]=='S')
                {
                    si=i;sj=j;
                }
                else if(str[i][j]=='D')
                {
                    di=i;dj=j;
                }
                else if(str[i][j]=='X')
                    num++;
            }
            getchar();
        }
        if(m*n-num<=T)      //路径剪枝
        {
            printf("NO\n");
            continue;
        }
        flag=0;
        str[si][sj]='X';
        dfs(si,sj,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

