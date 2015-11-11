////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-25 15:29:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1980KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define M 50001
int N;
struct px
{
    int st;
    int ed;
    int value;
};
struct px Tnode[5*M];
int S[M];
void Build(int p,int st,int ed)//建树
{
    int mid=(st+ed)>>1;
    Tnode[p].st=st;
    Tnode[p].ed=ed;
    if(st==ed) 
    {
        Tnode[p].value=S[st];
        return;
    }
    Build(lch(p),st,mid);
    Build(rch(p),mid+1,ed);//注意要加一
    Tnode[p].value=Tnode[lch(p)].value+Tnode[rch(p)].value;//递归查找
}
void Insert(int p,int id,int num)
{
    if(Tnode[p].st==Tnode[p].ed)//找到该点
    {
        Tnode[p].value+=num;
        return;
    }
    else
    {
        Tnode[p].value+=num;
        int mid=(Tnode[p].st+Tnode[p].ed)>>1;
        if(id<=mid) Insert(lch(p),id,num);
        else Insert(rch(p),id,num);
    }
}
int Find(int p,int a,int b)//查找
{
    if(Tnode[p].st==a&&Tnode[p].ed==b)//找到该点
        return Tnode[p].value;
    int mid=(Tnode[p].st+Tnode[p].ed)>>1;
    if(b<=mid) return Find(lch(p),a,b);
    else if(a>mid) return Find(rch(p),a,b);
    else return Find(lch(p),a,mid)+Find(rch(p),mid+1,b);
}
int main ()
{
    int i,T,cas,v,a,b;
    char temp[20];
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        printf("Case %d:\n",cas);
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%d",&S[i]);
        Build(1,1,N);//建树
        while(scanf("%s",temp)!=EOF)
        {
            if(!strcmp(temp,"End")) break;
            if(!strcmp(temp,"Query"))
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",Find(1,a,b));
            }
            else if(!strcmp(temp,"Add"))
            {
                scanf("%d%d",&a,&b);
                Insert(1,a,b);
            }
            else
            {
                scanf("%d%d",&a,&b);
                Insert(1,a,-b);
            }
        }
    }
    return 0;
}