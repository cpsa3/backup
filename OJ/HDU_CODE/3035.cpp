////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-29 19:18:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:7500MS
////Run memory:56548KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
const unsigned int MAXN= 600 , maxint = 1<<30;
struct edge{unsigned int x,ne,cost;}e[20*MAXN*MAXN];
unsigned int n,m,st,ed,te,top,ans,hd[4*MAXN*MAXN],rr[4*MAXN*MAXN];
unsigned int heap[4*MAXN*MAXN],d[4*MAXN*MAXN],r[4*MAXN*MAXN],tmp;
void link(unsigned int x,unsigned int y,unsigned int cost)
{
    te++; e[te].x=y; e[te].ne=0; e[te].cost=cost;
    if (hd[x]){ e[rr[x]].ne=te; rr[x]=te;}
    else rr[x]=hd[x]=te;
    te++; e[te].x=x; e[te].ne=0; e[te].cost=cost;
    if (hd[y]){ e[rr[y]].ne=te; rr[y]=te;}
    else rr[y]=hd[y]=te;
}
unsigned int pop()
{
    unsigned int t=heap[1],i=1,flag=1;
    r[1]=r[heap[top]]; heap[1]=heap[top--];
    //trail[pt++]=t;
    while (flag)
    {
        flag=0;
        if (top>=i*2+1 && d[heap[i]]>d[heap[i*2+1]] && d[heap[i*2]]>d[heap[i*2+1]])
        {
            flag=1;
            tmp=r[heap[i]]; r[heap[i]]=r[heap[i*2+1]]; r[heap[i*2+1]]=tmp;
            tmp=heap[i]; heap[i]=heap[i*2+1]; heap[i*2+1]=tmp;
            i=i*2+1;
        }
        else
        if (top>=i*2 && d[heap[i]]>d[heap[i*2]])
        {
            flag=1;
            tmp=r[heap[i]]; r[heap[i]]=r[heap[i*2]]; r[heap[i*2]]=tmp;
            tmp=heap[i]; heap[i]=heap[i*2]; heap[i*2]=tmp;
            i=i*2;
        }
    }
    return t;
}
void dij()
{
    unsigned int i,j,k,ii;
    top=ed+1;
    for (i=0;i<=top;i++) {heap[i+1]=i; d[i]=maxint; r[i]=i+1;}
    d[0]=0;
    j=hd[k=st];
    while (j)
    {
        if (d[e[j].x]>d[k]+e[j].cost)
        {
            d[e[j].x]=d[k]+e[j].cost;
            ii=r[e[j].x];
            while (ii!=1 && d[heap[ii]]<d[heap[ii/2]])
            {
                tmp=r[heap[ii]]; r[heap[ii]]=r[heap[ii/2]]; r[heap[ii/2]]=tmp;
                tmp=heap[ii]; heap[ii]=heap[ii/2]; heap[ii/2]=tmp;
                ii/=2;
            }
        }
        j=e[j].ne;
    }
    for (i=st;i<=ed;i++)
    {
        k=pop(); j=hd[k];
        while (j)
        {
            if (d[e[j].x]>d[k]+e[j].cost)
            {
                d[e[j].x]=d[k]+e[j].cost;
                ii=r[e[j].x];
                while (ii!=1 && d[heap[ii]]<d[heap[ii/2]])
                {
                    tmp=r[heap[ii]]; r[heap[ii]]=r[heap[ii/2]]; r[heap[ii/2]]=tmp;
                    tmp=heap[ii]; heap[ii]=heap[ii/2]; heap[ii/2]=tmp;
                    ii/=2;
                }
            }
            j=e[j].ne;
        }
    }
    printf("%u\n",d[ed]);
}
int main()
{
    unsigned int i,j,k;
    while (scanf("%u%u",&n,&m)!=EOF)
    {
        te=0;
        memset(hd,0,sizeof(hd));
        st=0; ed=4*n*m+1;
        for (i=0;i<=n;i++)
            for (j=0;j<m;j++)
            {
                scanf("%u",&tmp);
                if (!i) link(st,4*(i*m+j)+1,tmp);
                else
                    if (i==n) link(4*((i-1)*m+j)+3,ed,tmp);
                    else link(4*(i*m+j)+1,4*((i-1)*m+j)+3,tmp);
            }
        for (i=0;i<n;i++)
            for (j=0;j<=m;j++)
            {
                k=4*(i*m+j); scanf("%u",&tmp);
                if (!j) link(k+2,ed,tmp);
                else
                    if (j==m) link(k,st,tmp);
                    else link(k,k+2,tmp);
            }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                k=4*(i*m+j);
                scanf("%u",&tmp); link(k+2,k+1,tmp);
                scanf("%u",&tmp); link(k+1,k+4,tmp);
            }
            for (j=0;j<m;j++)
            {
                k=4*(i*m+j);
                scanf("%u",&tmp); link(k+2,k+3,tmp);
                scanf("%u",&tmp); link(k+3,k+4,tmp);
            }
        }
        dij();
    }
    return 0;
}
 
