////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-10-02 14:54:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:276KB
//////////////////System Comment End//////////////////
/*HDU_1231 �������������*/
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
#define MAXN 10005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N;
int w[MAXN];
int ss,ee,ans;
int s,now;

void Init()
{
    int i;
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
    now=-INF;
    for(i=1;i<=N;i++)
    {
        if(now<w[i])
        {now=w[i];pos=i;}
    }
    if(now<0)     //�����������<0��ֱ������
    {
        printf("0 %d %d\n",w[1],w[N]);
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
    printf("%d %d %d\n",ans,w[ss],w[ee]);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}