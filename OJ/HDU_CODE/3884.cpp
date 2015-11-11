////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-10 20:03:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3884
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:524KB
//////////////////System Comment End//////////////////
#include <iostream>

#include <algorithm>

#include <string.h>

#include <stdio.h> 

using namespace std;


typedef __int64 lld;



const int maxn=10000+2;

struct Pt

{
	
    lld x;
	
    lld p;
	
} a[maxn];

lld s[maxn];

lld b[maxn];

bool operator <(Pt a,Pt b)

{
	
    return a.x<b.x;
	
}

int n;

lld m;

int maxtot=0;

void addh(int &i,int l,int r,lld &m)

{
	
    i++;
	
    m+=(b[r]+s[r-1]-s[i-1])*(a[i].x-a[i-1].x);
	
    m-=(s[i-1]-s[l-1])*(a[i].x-a[i-1].x);
	
}

void move(int &i,int l,int r,lld &m)

{
	
    while (( i<r ) && (i < l || s[i]-s[l-1]<=s[r-1]-s[i]+b[r]))
		
		addh(i,l,r,m);
	
}

int l,r,heart,tot;

void mr(lld &m)

{ 
	
	lld k;
	
	while (m>=0 && r<=n)
		
    {
		
        if ((a[r].p-b[r])*(a[r].x-a[heart].x)<=m)
			
			k=a[r].p-b[r];
		
        else
			
            k=m/(a[r].x-a[heart].x);
		
        if (k==0)
			
            break;
		
        m-=k*(a[r].x-a[heart].x);
		
        b[r]+=k;
		
        tot+=k;
		
		if (b[r]==a[r].p)
			
            r++;
		
    }
	
}

void work(lld m)

{
	
    memset(b,0,sizeof(b));
	
	s[0]=0;
	
    for (int i=1;i<=n;i++)
		
        s[i]=s[i-1]+a[i].p;
	
	
    b[1]=a[1].p;
	
    tot=a[1].p;
	
    l=1; r=2;heart=1;
	
	
	mr(m);
	
    if (tot>maxtot)
		
        maxtot=tot;
	
	
    while (heart<n)
		
    {
		
		addh(heart,l,r,m);
		
		mr(m);
		
		while (m <0 || (r<=n && a[r].x-a[heart].x< a[heart].x-a[l].x) )
			
		{
			
			l++;
			
			tot-=a[l-1].p;
			
			b[l-1]=0;
			
			m+=a[l-1].p*(a[heart].x-a[l-1].x);
			
			mr(m);
			
		}
		
		
        if (tot>maxtot)
			
            maxtot=tot;
		
    }
	
}

int main()

{
	
    int i;
	
	
    while (scanf("%d%I64d",&n,&m)!=EOF)
		
    {
		
        for (i=1;i<=n;i++)
			
            scanf("%I64d%I64d",&a[i].x,&a[i].p);
		
		
        sort(a+1,a+n+1);
		
		
        maxtot=0;
		
        
		
        work(m);
		
		
        for (i=1;i<=n/2;i++)
			
            swap(a[i],a[n-i+1]);
		
        for (i=1;i<=n;i++)
			
            a[i].x*=-1;
		
        work(m);
		
        
		
        printf("%d\n",maxtot);
		
    }
	
    return 0;
	
}
