////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-11-30 16:10:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1264
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 1005
struct Line 
{
    int x,y_up,y_down;
    int side;
}L[2*MAXN];
struct Tree
{
    int x,y_up,y_down;
    int cover;
    bool flag;
}Tnode[8*MAXN];
int Y[2*MAXN];
int K;
void change(int &a,int &b)
{
    int t;
    if(a>b)
    {t=a;a=b;b=t;}
}
bool cmp(Line a,Line b)
{return a.x<b.x;}
void Build(int p,int s,int e)
{
    Tnode[p].x=-1;
    Tnode[p].cover=0;
    Tnode[p].y_down=Y[s];//Ð¡
    Tnode[p].y_up=Y[e];
    Tnode[p].flag=false;
    if(s+1==e)
    {
        Tnode[p].flag=true;
        return;
    }
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid,e);
}
int Insert(int p,int x,int s,int e,int side)
{
    if(e<=Tnode[p].y_down||s>=Tnode[p].y_up)
        return 0;
    if(s<=Tnode[p].y_down&&e>=Tnode[p].y_up&&Tnode[p].flag)
    {
        if(Tnode[p].cover>0)
        {
            int temp_x=Tnode[p].x;
            Tnode[p].x=x;
            Tnode[p].cover+=side;
            return (Tnode[p].y_up-Tnode[p].y_down)*(x-temp_x);    
        }
        else
        {
            Tnode[p].x=x;
            Tnode[p].cover+=side;
            return 0;
        }
    }
    return Insert(lch(p),x,s,e,side)+Insert(rch(p),x,s,e,side);
}

int main ()
{
    int x1,y1,x2,y2,i,flag=0;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
    {
        if(x1==-2&&x2==-2&&y1==-2&&y2==-2)
            break;
        change(x1,x2);change(y1,y2);
        L[1].x=x1;
        L[1].y_down=y1;
        L[1].y_up=y2;
        L[1].side=1;
        Y[1]=y1;
        L[2].x=x2;
        L[2].y_down=y1;
        L[2].y_up=y2;
        L[2].side=-1;
        Y[2]=y2;
        K=3;
        while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
        {
            if(x1==-1&&x2==-1&&y1==-1&&y2==-1)
                break;
            if(x1==-2&&x2==-2&&y1==-2&&y2==-2)
            {flag=1;break;}
            change(x1,x2);change(y1,y2);//×¢Òâµã
            L[K].x=x1;
            L[K].y_down=y1;
            L[K].y_up=y2;
            L[K].side=1;
            Y[K]=y1;
            K++;
            L[K].x=x2;
            L[K].y_down=y1;
            L[K].y_up=y2;
            L[K].side=-1;
            Y[K]=y2;
            K++;
        }
        sort(L+1,L+K,cmp);
        sort(Y+1,Y+K);
        Build(1,1,K-1);
        int ans=0;
        for(i=1;i<K;i++)
            ans+=Insert(1,L[i].x,L[i].y_down,L[i].y_up,L[i].side);
        printf("%d\n",ans);
        if(flag) break;
    }
    return 0;
}
