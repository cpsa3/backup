////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-18 23:51:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3957
////Problem Title: 
////Run result: Accept
////Run time:8203MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*
 * File:   main.cpp
 * Author: nyroro
 *
 * Created on 2011年8月17日, 下午3:20
 */

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define inf 0x7fffffff
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

/*
 *
 */
#define MAXN 55
#define ONE ((long long)1)
#define M ((ONE<<(n))-1)
long long st[MAXN],latter[MAXN];
int n,pn;
bool dfs(long long state,int step,int begin,int maxlength)
{
    if(state==M)
        return true;
    if(step==maxlength)
        return false;
    if(begin>n)
        return false;

    for(int i=begin;i<=n;i+=2)
    {  
        if((state|latter[i])!=(ONE<<(n))-1)
        {
            break;
        }
        if((state|st[i])==state)
            continue;
        if(dfs(state|st[i],step+1,i+2,maxlength))
            return true;


        if((state|latter[i+1])!=(ONE<<(n))-1)
        {
            break;
        }
        if((state|st[i+1])==state)
            continue;

        if(dfs(state|st[i+1],step+1,i+2,maxlength))
            return true;
    }
    return false;
}

int main()
{
//   freopen("in", "r", stdin);
    int t;
    scanf("%d",&t);
    int ti=1;

    while(t--)
    {
        scanf("%d",&n);
        pn=n;
        n*=2;
        int i,j;
        long long state=0;
        for(i=1;i<=n;i++)
        {
            latter[i]=0;
            st[i]=0;
            st[i]|=(ONE<<(i-1));
            st[i]|=(ONE<<((i-1)^1));
        }

        for(i=1;i<=pn;i++)
        {
            int k;
            scanf("%d",&k);
            if(k==1)
                state|=(ONE<<(2*(i-1)+1));
            int kn,a,b;
            for(j=0;j<k;j++)
            {
                scanf("%d",&kn);
                for(int m=0;m<kn;m++)
                {
                    scanf("%d%d",&a,&b);
                    st[2*(i-1)+j+1]|=(ONE<<(2*a+b));
                }
            }
        }
        latter[n]=st[n];
        for(i=n-1;i>=1;i--)
            latter[i]=st[i]|latter[i+1];

//
//        cout<<state<<endl;
//        cout<<st[1]<<endl;
        printf("Case %d: ",ti++);
        for(i=1;i<=pn;i++)
        {
            if(dfs(state,0,1,i))
            {
                printf("%d",i);
                break;
            }
        }
        cout<<endl;
    }

    return 0;
}

