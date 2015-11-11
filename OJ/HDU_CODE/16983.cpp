////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-25 20:01:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:4348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAX 100000
int N,M;
struct px
{
    int st;
    int ed;
    int value;//该子树每个点的价值
    int sum;//该树的总价值
};
struct px Tnode[3*MAX];
void Build(int p,int s,int e)//建树
{
    int mid=(s+e)>>1;
    Tnode[p].st=s;
    Tnode[p].ed=e;
    Tnode[p].sum=(e-s+1);
    if(s==e)
        return;
    else
    {
        Tnode[p].value=0;
        Build(lch(p),s,mid);
        Build(rch(p),mid+1,e);
    }
}
void Insert(int p,int s,int e,int k)
{
    int mid=(Tnode[p].st+Tnode[p].ed)>>1;
    if(Tnode[p].st==s&&Tnode[p].ed==e)//找到该子树，不用继续往下改
    {
        Tnode[p].value=k;
        Tnode[p].sum=(e-s+1)*k;
        return;
    }
    else
    {
        if(Tnode[p].value)//说明要往下更新
        {
            Tnode[lch(p)].value=Tnode[p].value;
            Tnode[lch(p)].sum=(Tnode[lch(p)].ed-Tnode[lch(p)].st+1)*Tnode[lch(p)].value;
            Tnode[rch(p)].value=Tnode[p].value;
            Tnode[rch(p)].sum=(Tnode[rch(p)].ed-Tnode[rch(p)].st+1)*Tnode[rch(p)].value;
            Tnode[p].value=0;
        }
        if(e<=mid) Insert(lch(p),s,e,k);
        else if(s>mid) Insert(rch(p),s,e,k);
        else
        {
            Insert(lch(p),s,mid,k);
            Insert(rch(p),mid+1,e,k);
        }
        Tnode[p].sum=Tnode[lch(p)].sum+Tnode[rch(p)].sum;//更新该数总和
    }
}
int main ()
{
    int T,i,cas,a,b,k;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&N,&M);
        Build(1,1,N);
        for(i=1;i<=M;i++)
        {
            scanf("%d%d%d",&a,&b,&k);
            Insert(1,a,b,k);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas,Tnode[1].sum);
    }
    return 0;
}