////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:53:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>   
using namespace std;   
int main()   
{   
    int n,i;   
    int a[20001];   
    int s,e,maxn,sum,t;   
    while(scanf("%d",&n)!=EOF && n)   
    {   
		for(i=0;i<n;i++)   
			scanf("%d",&a[i]);   
		maxn=-1;   
		for(i=0,sum=0,t=0;i<n;i++)   
		{   
			sum+=a[i];   
			if(sum>maxn)   
			{   
				maxn=sum;   
				s=t;   
				e=i;   
			}   
			if(sum<0)   
			{   
				sum=0;   
				t=i+1;   
			}   
		}   
		if(maxn<0)   
		{   
			maxn=0;   
			s=0;   
			e=n-1;   
		}   
		printf("%d %d %d\n",maxn,a[s],a[e]);   
    }   
    return 0;   
}   