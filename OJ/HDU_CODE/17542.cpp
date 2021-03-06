////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-06 18:19:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:5680KB
//////////////////System Comment End//////////////////
/*Splay_Tree解区间最大值*/
/*HDU_1754 [I Hate It]*/
/*AC代码：609ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define MAXN 2000003
#define MAXL 200005
#define INF (1<<30)
using namespace std;
struct Splay_Tree
{
    struct Node//节点
    {
        Node *c[2],*p;
        int maxs,size,value;
    }*root,*null,*lb,*rb,S[MAXN];
    int scnt;
    inline int max(int a,int b) {return a>b?a:b;}
    inline Node * NewNode(int value,Node *p)//插入新节点
    {
        Node *e=S+(++scnt);
        e->size=1;
        e->p=p;
        e->maxs=value;
        e->value=value;
        e->c[0]=e->c[1]=null;
        return e;
    }
    inline void Update(Node *p)//更新节点信息
    {
        if (p==null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->maxs=max(p->value,max(p->c[0]->maxs,p->c[1]->maxs));
    }
    inline void Rotate(Node *x,int k)//左旋 k=0；右旋 k=1；
    {
        Node *y=x->p;
        y->c[k]=x->c[!k];
        y->c[k]->p=y;
        x->p=y->p;
        if(y->p->c[0]==y)
            y->p->c[0]=x;
        else
            y->p->c[1]=x;
        y->p=x;
        x->c[!k]=y;
        Update(y);
        Update(x);
        if(root==y) root=x;
    }
    inline void Splay(Node *x,Node *y)//伸展
    {
        while(x->p!=y)
        {
            if(x->p->p==y)
            {
                if(x->p->c[0]==x)
                    Rotate(x,0);
                else
                    Rotate(x,1);
            }
            else if(x->p->p->c[0]==x->p)
            {
                if(x->p->c[0]==x)
                    Rotate(x->p,0),Rotate(x,0);
                else
                    Rotate(x,1),Rotate(x,0);
            }
            else
            {
                if(x->p->c[1]==x)
                    Rotate(x->p,1),Rotate(x,1);
                else
                    Rotate(x,0),Rotate(x,1);
            }
        }
        Update(x);
    }
    inline void Select(int k,Node *y)
    {
        Node *x=root;
        while(k!=x->c[0]->size+1)
        {
            if(k<=x->c[0]->size)
                x=x->c[0];
            else
            {
                k-=x->c[0]->size+1;
                x=x->c[1];
            }
        }
         Splay(x,y);
    }
    inline void Insert(int pos,int cnt,int C[])
    {
        int i;
        Node *t,*z;
        z=t=NewNode(C[1],null);
        for(i=2;i<=cnt;i++)
            z=z->c[1]=NewNode(C[i],z);
        Select(pos+1,null);
        Select(pos+2,root);
        root->c[1]->c[0]=t;
        t->p=root->c[1];
        Splay(z,null);
    }
    inline void Fuck(int pos,int k)
    {
        Select(pos,null);
        root->maxs=root->value=k;
    }
    inline int GetMaxs(int pos,int cnt)
    {
        Select(pos,null);
        Select(pos+cnt+1,root);
        return root->c[1]->c[0]->maxs;
    }
    inline int Index(int pos)
    {
        Select(pos,null);
        printf("*%d\n",root->value);
        //return root->value;
    }
    inline void Init()
    {
        scnt=-1;
        null=0;
        null=NewNode(-INF,0);
        null->size=0;
        lb=root=NewNode(-INF,null);
        rb=root->c[1]=NewNode(-INF,root);
        Update(root);
    }
}Splay;
int N,M,C[MAXL],pos,ans;
char s[20];
int main()
{
    int i,u,v;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Splay.Init();
        for(i=1;i<=N;i++)
            scanf("%d",&C[i]);
        Splay.Insert(0,N,C);
        while(M--)
        {
            scanf("%s%d%d",s,&u,&v);
            if(s[0]=='Q')
            {
                ans=Splay.GetMaxs(u,v-u+1);
                printf("%d\n",ans);
            }
            else
            {
                //Splay.Index(u+1);
                Splay.Fuck(u+1,v);
                //Splay.Index(u+1);
            }
        }
    }
return 0;
}
