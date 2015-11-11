////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-17 23:33:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3552
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1776KB
//////////////////System Comment End//////////////////
#include <iostream>
#define maxn 100005
using namespace std;

struct node
{
    unsigned long long x,y;
}q[maxn];   

int cmp(const void *a,const void *b)
{
    node *x = (node*) a;
    node *y = (node*) b;
    if(x->x != y->x)
    return y->x - x->x;
else
   return y->y - x->y;
}   

int main()
{
    int i,j,k,numcase,n,ans;
    unsigned long long x,y;
    scanf("%d",&numcase);
    for(k = 0; k < numcase; k++)
    {
        scanf("%d",&n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&q[i].x,&q[i].y);
        }
        qsort(q,n,sizeof(q[0]),cmp);
        y = q[0].y; 
        ans = q[0].x;
        for(i = 1; i < n; i++)
        {
            if(q[i-1].y > y)
            y = q[i-1].y;
        if(q[i].x + y < ans)
           ans = q[i].x + y;
        }
        printf("Case %d: %d\n",k+1,ans);        
    }    
    return 0;
}   
