////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:15:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2725
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[50];
int len;

struct Node
{
    int s,d;
    int c,l;
    bool cmp(Node u)
    {
        if(u.c!=c) return u.c>c;
        if(u.l!=l) return u.l>l;
        if(u.s!=s) return u.s>s;
        return u.d<d;
    }
    void Update(Node u)
    {
        if(cmp(u)) *this=u;
    }
};
Node ans;

Node fuck(int s1,int d1)
{
    Node res;
    int c=0;
    //res.c=0;
    while(true)
    {
        if(s1<len&&s[s1]=='.')
        {
            s1+=d1;
            c++;
            //res.c++;
        }
        else break;
    }
    res.c=c;
    if(s1>=len) s1=len-1;
    res.l=s1;
    return res;
}
void Solve()
{
    int i,j;
    ans.c=ans.l=0;
    ans.s=0;ans.d=len-1;
    len=strlen(s);
    Node t;
    for(i=0;i<len;i++)
    {
        for(j=1;j+i<=len;j++)
        {
            t=fuck(i,j);
            t.s=i;t.d=j;
            ans.Update(t);
        }
    }
    printf("%d %d\n",ans.s,ans.d);
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"END")==0) break;
        Solve();
    }
return 0;
}