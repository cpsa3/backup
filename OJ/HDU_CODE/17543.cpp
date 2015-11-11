////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-09-06 19:08:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:5680KB
//////////////////System Comment End//////////////////
/*Splay_Tree���������ֵ*/
/*HDU_1754 [I Hate It]*/
/*AC���룺609ms*/
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
    struct Node//�ڵ�
    {
        Node *c[2],*p;
        int maxs,size,value;
    }*root,*null,*lb,*rb,S[MAXN];
    int scnt;
    inline int max(int a,int b) {return a>b?a:b;}
    inline Node * NewNode(int value,Node *p)//�����½ڵ�
    {
        Node *e=S+(++scnt);
        e->size=1;
        e->p=p;
        e->maxs=value;
        e->value=value;
        e->c[0]=e->c[1]=null;
        return e;
    }
    inline void Update(Node *p)//���½ڵ���Ϣ
    {
        if (p==null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->maxs=max(p->value,max(p->c[0]->maxs,p->c[1]->maxs));
    }
    inline void Rotate(Node *x,int k)//���� k=0������ k=1��
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
    inline void Splay(Node *x,Node *y)//��չ
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
    inline void MakeTree(int l,int r,int C[],Node *p,int side)
    {
        if(l>r) return;
        int mid=(l+r)>>1;
        Node *x;
        x=NewNode(C[mid],p);
        p->c[side]=x;
        MakeTree(l,mid-1,C,x,0);
        MakeTree(mid+1,r,C,x,1);
        Update(x);
    }
    inline void Insert(int pos,int cnt,int C[])
    {
        Select(pos+1,null);
        Select(pos+2,root);
        MakeTree(1,cnt,C,root->c[1],0);
        Splay(root->c[1]->c[0],null);
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
        /*
        for(i=1;i<=N;i++)
            Splay.Index(i+1);
            */
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
