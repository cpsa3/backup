////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-28 11:26:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2871
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:6272KB
//////////////////System Comment End//////////////////
/*HDU_2871 Memory Control*/
/*线段树*/
/*AC代码*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#define MAXN 60005
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
    int s,e,len;
    int ll,rr,maxs;
    int mark;     //修改标记
    int Reset;    //清空标记
    int v,id;
    void go()
    {
        if(mark==0) {ll=rr=maxs=len;}
        else if(mark==1) {ll=rr=maxs=0;}
        //if(Reset) v=0;
    }
}Tnode[4*MAXN];
int N,M;
int S[MAXN*10],E[MAXN*10],cnt;
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].ll=Tnode[p].rr=Tnode[p].maxs=Tnode[p].len=(e-s+1);
    Tnode[p].v=0;Tnode[p].id=-1;Tnode[p].Reset=0;
    Tnode[p].mark=-1;
    if(s==e) return;
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
}
void Push_Up(int p)    //向上更新
{
    Tnode[p].ll=Tnode[lch(p)].ll;
    if(Tnode[lch(p)].ll==Tnode[lch(p)].len)
        Tnode[p].ll+=Tnode[rch(p)].ll;

    Tnode[p].rr=Tnode[rch(p)].rr;
    if(Tnode[rch(p)].rr==Tnode[rch(p)].len)
        Tnode[p].rr+=Tnode[lch(p)].rr;

    Tnode[p].maxs=max(Tnode[lch(p)].rr+Tnode[rch(p)].ll,max(Tnode[lch(p)].maxs,Tnode[rch(p)].maxs));

    //Tnode[p].v=Tnode[lch(p)].v+Tnode[rch(p)].v;
}
void Push_Down(int p)   //向下传递标记
{
    if(Tnode[p].mark!=-1)
    {
        Tnode[lch(p)].mark=Tnode[rch(p)].mark=Tnode[p].mark;
        Tnode[lch(p)].id=Tnode[rch(p)].id=Tnode[p].id;
        Tnode[lch(p)].go();
        Tnode[rch(p)].go();
        Tnode[p].mark=-1;
    }
    if(Tnode[p].Reset)
    {
        Tnode[lch(p)].Reset=Tnode[rch(p)].Reset=1;
        Tnode[lch(p)].v=Tnode[rch(p)].v=0;
        Tnode[p].Reset=0;
    }
}
int Query(int p,int len)
{
    int res;
    //printf("*\n");
    if(Tnode[p].maxs<len) return -1;
    if(Tnode[p].s==Tnode[p].e) return Tnode[p].s;
    Push_Down(p);
    if(Tnode[lch(p)].maxs>=len) res=Query(lch(p),len);
    else if(Tnode[lch(p)].rr+Tnode[rch(p)].ll>=len)
        res=Tnode[lch(p)].e+1-Tnode[lch(p)].rr;
    else res=Query(rch(p),len);
    Push_Up(p);
    return res;
}
void Update(int p,int s,int e,int flag,int id,int R)
{
    if(Tnode[p].s==s&&Tnode[p].e==e)
    {
        Tnode[p].mark=flag;
        Tnode[p].go();
        Tnode[p].id=id;
        if(R)
        {
            Tnode[p].Reset=1;
            Tnode[p].v=0;
        }
        return;
    }
    Push_Down(p);
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(e<=mid) Update(lch(p),s,e,flag,id,R);
    else if(s>mid) Update(rch(p),s,e,flag,id,R);
    else
    {
        Update(lch(p),s,mid,flag,id,R);
        Update(rch(p),mid+1,e,flag,id,R);
    }
    Push_Up(p);
}
void Insert(int p,int k,int dv)
{
    Tnode[p].v+=dv;
    if(Tnode[p].s==Tnode[p].e) return;
    Push_Down(p);
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k<=mid) Insert(lch(p),k,dv);
    else Insert(rch(p),k,dv);
    Push_Up(p);
}
int Find(int p,int k)
{
    int res;
    if(Tnode[p].s==Tnode[p].e) return Tnode[p].id;
    Push_Down(p);
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k<=mid) res=Find(lch(p),k);
    else res=Find(rch(p),k);
    Push_Up(p);
    return res;
}
int Get(int p,int k)
{
    int res;
    Push_Down(p);
    if(Tnode[p].v<k) return -1;
    if(Tnode[p].s==Tnode[p].e) return Tnode[p].s;  //注意特判

    if(Tnode[lch(p)].v>=k) res=Get(lch(p),k);
    else res=Get(rch(p),k-Tnode[lch(p)].v);
    Push_Up(p);
    return res;
}
void Solve()
{
    int x,pos,id;
    char s[20];
    cnt=0;
    Build(1,1,N);
    while(M--)
    {
        scanf("%s",s);
        if(s[0]=='R') {Update(1,1,N,0,-1,1);printf("Reset Now\n");}
        else
        {
            scanf("%d",&x);
            if(s[0]=='N')
            {
                //printf("*%d\n",Tnode[1].maxs);
                pos=Query(1,x);
                if(pos==-1) printf("Reject New\n");
                else
                {
                    S[cnt]=pos;E[cnt]=pos+x-1;
                    Update(1,pos,pos+x-1,1,cnt,0);
                    Insert(1,pos,1);
                    cnt++;
                    printf("New at %d\n",pos);
                }
            }
            else if(s[0]=='F')
            {
                pos=Find(1,x);
                if(pos==-1) printf("Reject Free\n");
                else
                {
                    printf("Free from %d to %d\n",S[pos],E[pos]);
                    Insert(1,S[pos],-1);
                    Update(1,S[pos],E[pos],0,-1,0);
                }
            }
            else
            {
                pos=Get(1,x);
                if(pos==-1) printf("Reject Get\n");
                else printf("Get at %d\n",pos);
            }
        }
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Solve();
    }
return 0;
}