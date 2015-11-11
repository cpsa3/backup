////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-06 19:26:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:593MS
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
    Node * NewNode(int value,Node *p)//插入新节点
    {
        Node *e=S+(++scnt);
        e->size=1;
        e->p=p;
        e->maxs=value;
        e->value=value;
        e->c[0]=e->c[1]=null;
        return e;
    }
    void Update(Node *p)//更新节点信息
    {
        if (p==null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->maxs=max(p->value,max(p->c[0]->maxs,p->c[1]->maxs));
    }
    void Rotate(Node *x,int k)//左旋 k=0；右旋 k=1；
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
    void Splay(Node *x,Node *y)//伸展
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
    void Select(int k,Node *y)//表示将第k个数移到节点y的下面
    {
        k++;
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
    void MakeTree(int l,int r,int C[],Node *p,int side)
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
    void Insert(int pos,int cnt,int C[])//插入一段数列
    {
        Select(pos,null);
        Select(pos+1,root);
        MakeTree(1,cnt,C,root->c[1],0);
        Splay(root->c[1]->c[0],null);
    }
    void Fuck(int pos,int k)//更新第pos个数为k
    {
        Select(pos,null);
        root->maxs=root->value=k;
    }
    int GetMaxs(int pos,int cnt)//返回[pos,pos+cnt-1]的区间最大值
    {
        Select(pos-1,null);
        Select(pos+cnt,root);
        return root->c[1]->c[0]->maxs;
    }
    int Index(int pos)//打印数列中第pos个数
    {
        Select(pos,null);
        printf("*%d\n",root->value);
        //return root->value;
    }
    void Print()//打印数列里的所有数
    {
        int i;
        //printf("&%d\n",scnt);
        for(i=1;i<scnt-1;i++)
            Index(i);
    }
    void Init()
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
        
        //Splay.Print();
        
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
                //Splay.Index(u);
                Splay.Fuck(u,v);
                //Splay.Index(u);
            }
        }
    }
return 0;
}
