////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-13 16:20:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4038
////Problem Title: 
////Run result: Accept
////Run time:968MS
////Run memory:1000KB
//////////////////System Comment End//////////////////
/*Ä£ÄâÌâ*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MOD 1000000007
#define type __int64
#define MAXN  1000005
using namespace std;
type N,M,ans,Num[MAXN];
int cas;
bool ok;
type Pow(type x)
{
    type t;
    if(x==0) return 1;
    if(x==1) return 3;
    if(x%2)
    {
        t=Pow(x/2);
        return (((t*t)%MOD)*3)%MOD;
    }
    else
    {
        t=Pow(x/2);
        return (t*t)%MOD;
    }
}
void Init()
{
    int i;
    /*
    for(i=0;i<=10;i++)
    {
        printf("%I64d\n",Pow(i));
    }
    */
    scanf("%I64d%I64d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%I64d",&Num[i]);
}
void get_ans(type Num[],type n)
{
    int i;
    ans=1;
    for(i=0;i<n;i++)
        ans=(ans*Num[i])%MOD;
}

void Print()
{
    int i;
    for(i=0;i<N;i++)
        printf("%I64d ",Num[i]);
    printf("**********************\n");
}
void Solve()
{
    int i;
    type x,y,z,n;
    printf("Case %d: ",cas++);
    sort(Num,Num+N);
    ok=false;
    if(M==0)
    {
        get_ans(Num,N);
        ok=true;
    }
    if(ok) {printf("%I64d\n",ans);return;}

    for(i=0;i<N;i++)
    {
        if(Num[i]>=0) break;
    }
    if(i&1)                         //-;
    {
        x=Num[i-1];
        if(M>(-x))
        {
            Num[i-1]=0;
            M+=x;
        }
        else
        {
            Num[i-1]+=M;
            get_ans(Num,N);
            ok=true;
        }
    }
    //printf("***%I64d %I64d\n",M,x);
    if(ok) {printf("%I64d\n",ans);return;}
    
    for(i=0,n=0;i<N;i++)
    {
        if(Num[i]==0) n++;
    }
    if(M>n)                         //0;
    {
        for(i=0;i<N;i++)
        {
            if(Num[i]==0) Num[i]++;
        }
        M-=n;
    }
    else
    {
        for(i=0;i<N&&M;i++)
        {
            if(Num[i]==0) {Num[i]++;M--;}
        }
        get_ans(Num,N);
        ok=true;
    }
    if(ok) {printf("%I64d\n",ans);return;}
    //printf("***%I64d\n",M);
    for(i=0,n=0;i<N;i++)            //1;
    {
        if(Num[i]==1) n++;
    }
    if(M>n)
    {
        for(i=0;i<N;i++)
        {
            if(Num[i]==1) Num[i]++;
        }
        M-=n;
    }
    else
    {
        for(i=0;i<N&&M;i++)
        {
            if(Num[i]==1) {Num[i]++;M--;}
        }
        get_ans(Num,N);
        ok=true;
    }
    //printf("***%I64d\n",M);
    //Print();
    if(ok) {printf("%I64d\n",ans);return;}
    
    for(i=0,n=0;i<N;i++)                //2;
    {
        if(Num[i]==2) n++;
    }
    if(M>n)
    {
        for(i=0;i<N;i++)
        {
            if(Num[i]==2) Num[i]++;
        }
        M-=n;
    }
    else
    {
        //printf ("%I64d %I64d \n",M,n);
        for(i=0;i<N&&M;i++)
        {
            if(Num[i]==2) {Num[i]++;M--;}
        }
        get_ans(Num,N);
        ok=true;
    }
    if(ok) {printf("%I64d\n",ans);return;}
    
    
    sort(Num,Num+N);
    x=-1;
    for(i=0;i<N;i++)
    {
        if(Num[i]>0)
        {
            x=i;
            break;
        }
    }
    if(M==1)
    {
        if(x!=-1) Num[x]++;
        get_ans(Num,N);
        ok=true;
        printf("%I64d\n",ans);return;
    }
    if(M<=4)
    {
        get_ans(Num,N);
        ans=(ans*M)%MOD;
        printf("%I64d\n",ans);return;
    }
    get_ans(Num,N);
    x=M/3;
    y=M%3;
    
    if(y==0)
    {
        z=Pow(x);
        ans=(ans*z)%MOD;
    }
    else if(y==1)
    {
        z=Pow(x-1);
        ans=(ans*z)%MOD;
        ans=(ans*4)%MOD;
    }
    else
    {
        z=Pow(x);
        ans=(ans*z)%MOD;
        ans=(ans*2)%MOD;
    }
    printf("%I64d\n",ans);
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {

        Init();
        Solve();
    }
return 0;
}