////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-10-02 13:19:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:628KB
//////////////////System Comment End//////////////////
/*HDU_1003 Max Sum*/
/*DP O(n)*/
/*
˼·��
(1):now ��ʾ��ǰ�ε�ֵ��
(2):s��ʾ��ǰ�ε���ʼ��
(3):ans��ʾ��ǰ���ֵ
(4):ss��ʾ���ε���ʼ��
    ee��ʾ���ε���ֹ��
(5):if(w[i]>0) now+=w[i]; s++��
    else
    {
        if(w[i]+now>=0) now+=w[i];s++;
        else
        {
            pos=��i�����һ���Ǹ�����λ��
            s=pos;
            now=w[pos];
        }
    }
    if(now>ans) ans=now;ss=s;ee=i;
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 100005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N,cas;
int w[MAXN];
int ss,ee,ans;
int s,now;

void Init()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&w[i]);
}
int Pos(int x)       //��xλ�ÿ�ʼ��һ���Ǹ�����λ��
{
    int i;
    for(i=x;i<=N;i++)
    {
        if(w[i]>=0) return i;
    }
    return -1;
}
void Solve()
{
    int i,pos;
    
    printf("Case %d:\n",cas++);
    
    now=-INF;
    for(i=1;i<=N;i++)
    {
        if(now<w[i])
        {now=w[i];pos=i;}
    }
    if(now<=0)     //�����������<=0��ֱ������
    {
        printf("%d %d %d\n",now,pos,pos);
        return;
    }
    
    pos=Pos(1);
    s=ss=ee=pos;
    now=ans=w[pos];
    for(i=pos+1;i<=N;i++)
    {
        if(w[i]+now>=0)
            now+=w[i];
        else
        {
            pos=Pos(i);
            if(pos==-1) break;
            i=s=pos;
            now=w[pos];
        }
        if(now>ans)
        {
            ans=now;
            ss=s;
            ee=i;
        }
    }
    printf("%d %d %d\n",ans,ss,ee);
}
int main()
{
    int T;
    cas=1;
    bool flag=false;
    scanf("%d",&T);
    while(T--)
    {
        if(flag) printf("\n");
        Init();
        Solve();
        flag=true;
    }
return 0;
}