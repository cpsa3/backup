////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-25 23:32:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3743
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:4124KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAX 1000005
struct px
{
    int s,e,v;
};
struct px Tnode[4*MAX];
int S[MAX],N,T[MAX];
int max(int a,int b){return a>b?a:b;}
void Build(int p,int s,int e)
{
    int mid=(s+e)>>1;
    Tnode[p].s=s;
    Tnode[p].e=e;
    Tnode[p].v=0;
    if(s==e) return;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
    //Tnode[p].v=max(Tnode[lch(p)].v,Tnode[rch(p)].v);
}
int Insert(int p,int k)
{
    Tnode[p].v++;
    if(Tnode[p].s==Tnode[p].e)//找到
        return 0;
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k<=T[mid]) return Insert(lch(p),k)+Tnode[rch(p)].v;
    return Insert(rch(p),k);
}
/*
int Find(int p,int s,int e)
{
    if(Tnode[p].s==s&&Tnode[p].e==e)
        return Tnode[p].v;
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(e<=T[mid]) return Find(lch(p),s,e);//离散化
    else if(s>T[mid]) return Find(rch(p),s,e);
    else return Find(lch(p),s,mid)+Find(rch(p),mid+1,e);
}
*/
int main()
{
    int i;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
		{
            scanf("%d",&S[i]);
			T[i]=S[i];
		}
		sort(T,T+N);
        Build(1,0,N-1);
        __int64 temp=0;
        for(i=0;i<N;i++)//求出原始的逆序数
            temp+=Insert(1,S[i]);//注意
        printf("%I64d\n",temp);
    }
return 0;
} 
/*
15
12 34 556  6677 666 4444 2232 22 221 123445
67676 54545 9988 9 11
  
47
*/
