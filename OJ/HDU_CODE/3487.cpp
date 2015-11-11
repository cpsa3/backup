////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-08 21:10:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3487
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:8440KB
//////////////////System Comment End//////////////////
/*Splay_Tree*/
/*HDU_3487 Play with Chain*/
/*
区间操作：
(1):CUT a b c :将区间[a,b]切下来插入到c后面;
(2):FLIP a b  :对区间[a,b]进行翻转操作
*/
/*AC代码：875ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define Stop system("pause")
#define type int
#define MAXN 1500005
#define MAXL 300005
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Splay_Tree
{
    struct Node//节点
    {
        Node *c[2],*p;
        int value,size;
        bool rev;
    }*root,*null,*lb,*rb,S[MAXN];
    int scnt;
    bool flag;
    inline Node * NewNode(int value,Node *p)//插入新节点
    {
        Node *e=S+(++scnt);
        e->value=value;
        e->size=1;
        e->p=p;
        e->rev=false;
        e->c[0]=e->c[1]=null;
        return e;
    }
    inline void Update(Node *p)//更新节点信息
	{
		if (p==null) return;
		p->size=p->c[0]->size+p->c[1]->size+1;
	}
    inline void PushDown(Node *x)//更新标记
    {
        if(x==null) return;
        if(x->rev)
        {
            x->rev=false;
            Node *t=x->c[0]; x->c[0]=x->c[1]; x->c[1]=t;
            x->c[0]->rev=!x->c[0]->rev;
            x->c[1]->rev=!x->c[1]->rev;
        }
    }
    inline void Rotate(Node *x,int k)//左旋 k=0；右旋 k=1；
    {
        Node *y=x->p;
        PushDown(x->c[0]);
        PushDown(x->c[1]);
        PushDown(y->c[!k]);
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
        PushDown(x);
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
        PushDown(x);
        while(k!=x->c[0]->size+1)
        {
            if(k<=x->c[0]->size)
                x=x->c[0];
            else
            {
                k-=x->c[0]->size+1;
                x=x->c[1];
            }
            PushDown(x);
        }
		Splay(x,y);
    }
    inline void MakeTree(int l,int r,type C[],Node *p,int side)
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
    inline void Insert(int pos,int cnt,type C[])//在pos后插入长度为cnt的区间
    {
        Select(pos+1,null);
        Select(pos+2,root);
        MakeTree(1,cnt,C,root->c[1],0);
        Splay(root->c[1]->c[0],null);
    }

    inline void Delete(int pos,int cnt,int Ind)//删除pos后长度为cnt的区间
    {
        Node *p1;

        Select(pos,null);
        Select(pos+cnt+1,root);

        p1=root->c[1]->c[0];
        root->c[1]->c[0]=null;

		/*
        Print(p1);
        printf("*\n");
		*/

        Splay(root->c[1],null);

		
        Select(Ind+1,null);
        Select(Ind+2,root);

        root->c[1]->c[0]=p1;

        Splay(root->c[1],null);//注意不是Splay(root->c[1]->c[0],null)

    }

    /*
    inline void Delete(int pos,int cnt)//删除pos开始长度为cnt的区间
    {
        Select(pos,null);
        Select(pos+cnt+1,root);
        root->c[1]->c[0]=null;
        //scnt-=cnt;
        Splay(root->c[1],null);
    }
    */
    inline void Reverse(int pos,int cnt)//旋转pos后长度为cnt的区间
    {
        Select(pos,null);
        Select(pos+cnt+1,root);
        root->c[1]->c[0]->rev=!root->c[1]->c[0]->rev;
        Splay(root->c[1]->c[0],null);
    }
    inline void fuck(int pos,int cnt ,int C[])
    {
        int i,j;
        for(i=pos,j=1;i<pos+cnt;i++,j++)
        {
            Select(i+1,null);
            C[j]=root->value;
        }
    }
    void Index(int pos)
    {
        Select(pos+1,null);
        printf("%d",root->value);
    }
    inline void Out()//打印区间
    {
        flag=false;
        Print(root);
        printf("\n");
    }
    inline void Print(Node *now)
    {
        if(now==null) return;
        if(now->c[0]==null&&now->c[1]==null)
        {
            if(now->value!=INF)
            {
                if(flag) printf(" ");
                printf("%d",now->value);
                flag=true;
            }
            return;
        }
        PushDown(now);
        Print(now->c[0]);
        if(now->value!=INF)
        {
            if(flag) printf(" ");
            printf("%d",now->value);
            flag=true;
        }
        Print(now->c[1]);
    }
    inline void Init()
    {
        scnt=-1;
        null=0;
        null=NewNode(INF,0);
        null->size=0;
		lb=root=NewNode(INF,null);
        rb=root->c[1]=NewNode(INF,root);
        Update(root);
    }
}Splay;
int N,M,pos;
type C[MAXL],ans;
char s[20];
int main()
{
    int i,j,a,b,c;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N<0&&M<0) break;
        Splay.Init();
        for(i=1;i<=N;i++)
            C[i]=i;
        Splay.Insert(0,N,C);
        //Splay.Out();
        while(M--)
        {
            scanf("%s",s);
            if(s[0]=='C')
            {
                scanf("%d%d%d",&a,&b,&c);
                Splay.Delete(a,b-a+1,c);
                //Splay.fuck(a,b-a+1,C);
                //Splay.Delete(a,b-a+1);
                //Splay.Insert(c,b-a+1,C);
            }
            else
            {
                scanf("%d%d",&a,&b);
                Splay.Reverse(a,b-a+1);
            }
            //Splay.Out();
        }
        Splay.Out();
    }
return 0;
}
