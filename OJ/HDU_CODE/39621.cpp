////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-25 01:23:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3962
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:764KB
//////////////////System Comment End//////////////////
/*自动机+矩阵乘法*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define kind 4
#define MOD 10007
#define ll(a) (a*3)
#define mm(a) (a*3+1)
#define rr(a) (a*3+2)
using namespace std;
struct mat
{
    int v[100][100]; 
    void ini(int len)
    {
        int i;
        memset(v,0,sizeof(v));
        for(i=0;i<len;i++)
            v[i][i]=1;
    }
};
mat e,ans;
struct node
{
    int next[kind],v,fail;
};
struct node Trie[10000];
int snode,N,L;
int hash[255];
char word[30];
int map[105][105];
void set_node(int x)
{
    int i;
    for(i=0;i<kind;i++)
        Trie[x].next[i]=0;
    Trie[x].v=0;
    Trie[x].fail=-1;
}
void Insert(char s[])
{
    int i,p,Index;
    i=p=0;
    while(s[i])
    {
        Index=hash[s[i]];
        if(!Trie[p].next[Index])
        {
            set_node(++snode);
            Trie[p].next[Index]=snode;
        }
        p=Trie[p].next[Index];
        i++;
    }
    Trie[p].v++;
}
void Find_Fail(int pre,int Index,int ith)
{
    if(!pre)
    {
        Trie[ith].fail=0;
        return;
    }
    int temp=Trie[pre].fail;
    while(temp!=-1)
    {
        if(Trie[temp].next[Index]!=0)
        {
            Trie[ith].fail=Trie[temp].next[Index];
            if(Trie[Trie[temp].next[Index]].v)//注意
                Trie[ith].v++;
            return ;
        }
        temp=Trie[temp].fail;
    }
    if(temp==-1) Trie[ith].fail=0;
    return ;
}
queue<int>Q;
void Build_AC_Fail()
{
    int i,p=0;
    Trie[p].fail=-1;
    while(!Q.empty()) Q.pop();
    Q.push(0);
    while(!Q.empty())
    {
        p=Q.front();Q.pop();
        for(i=0;i<kind;i++)
        {
            if(Trie[p].next[i]!=0)
            {
                Find_Fail(p,i,Trie[p].next[i]);
                Q.push(Trie[p].next[i]);
            }
            else
                Trie[p].next[i]=Trie[Trie[p].fail].next[i];
        }
    }
} 
mat matrix_mul(mat p1,mat p2,int len)//矩阵相乘
{
    int i,j,k;
    mat t;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            t.v[i][j]=0;
            for(k=0;k<len;k++)
                t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
        }
    }
    return t;
}
mat matrix_mi(mat p1,int k,int len)//矩阵求幂
{
    mat res;
    res.ini(len);
    while(k)
    {
        if(k&1) res=matrix_mul(res,p1,len);
        p1=matrix_mul(p1,p1,len); 
        k>>=1;
    }
    return res;
}
void Init()
{
    int i;
    set_node(0);snode=0;
    for(i=1;i<=N;i++)
    {
        scanf("%s",word);
        Insert(word);
    }
    Build_AC_Fail();
}
void Print(int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
            printf("%d ",e.v[i][j]);
        printf("\n");
    }
    printf("------------------\n");
    for(i=0;i<=snode;i++)
        printf("%d ",Trie[i].v);
    printf("\n");
}
void fuck()
{
    int i,j;
    for(i=0;i<=snode;i++)
    {
        for(j=0;j<kind;j++)
            printf("%d ",Trie[i].next[j]);
        printf("\n"); 
    } 
}
void Run()//构造转换矩阵
{
    int i,j,temp;
    //fuck();
    memset(e.v,0,sizeof(e.v));
    for(i=0;i<=snode;i++)
    {
        for(j=0;j<kind;j++)
        {
            temp=Trie[i].next[j];
            if(Trie[temp].v==0)
            {
                e.v[ll(i)][ll(temp)]++;
                e.v[mm(i)][mm(temp)]++;
                e.v[rr(i)][rr(temp)]++; 
            }
            else if(Trie[temp].v==1)
            {
                e.v[ll(i)][mm(temp)]++;
                e.v[mm(i)][rr(temp)]++;
                e.v[rr(i)][rr(temp)]++; 
            }
            else if(Trie[temp].v>=2)
            {
                e.v[ll(i)][rr(temp)]++;
                e.v[mm(i)][rr(temp)]++;
                e.v[rr(i)][rr(temp)]++;
            } 
        }
    }
    int len=(snode+1)*3;
    //printf("*\n");
    //Print(len);
    //ans=matrix_mul(e,e,len);
    ans=matrix_mi(e,L,len);
}
void Solve()
{
    int i,res=0;
    //get_map();
    Run();
    //Print((snode+1)*3);
    for(i=0;i<=snode;i++)
    {
        res+=ans.v[0][rr(i)];
        res%=MOD;
    }  
    printf("%d\n",res);
}
int main()
{
    hash['A']=0;hash['T']=1;hash['C']=2;hash['G']=3;
    while(scanf("%d%d",&N,&L)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}