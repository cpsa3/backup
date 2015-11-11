////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-11 23:35:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1713
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <cstring>
using namespace std;
__int64 a,b,c,d;
__int64 gcd(__int64 a,__int64 b)//最大公约数
{
	return b==0?a:gcd(b,a%b); 
}
__int64 lcm(__int64 a,__int64 b)//最小公倍数
{
	return a/gcd(a,b)*b;
}
int main()
{
	int i,T,N,t;
	__int64 w1,w2;
	char s1[100],s2[100];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s1,s2);
		int len1=strlen(s1);
		int len2=strlen(s2);
		t=0;
		for(i=0;i<len1;i++)
		{
			if(s1[i]=='/')
			{a=t;t=0;}
			else
				t=t*10+s1[i]-'0';  
		}
		b=t;
		t=0;
		for(i=0;i<len2;i++)
		{
			if(s2[i]=='/')
			{c=t;t=0;}
			else
				t=t*10+s2[i]-'0';
		}
		d=t;
		w1=gcd(a,b);a/=w1;b/=w1;
		w2=gcd(c,d);c/=w2;d/=w2;
		w1=lcm(b,d);
		a*=(w1/b);c*=(w1/d);
		w2=lcm(a,c);
		__int64 w=gcd(w1,w2);
		if(w2%w1==0)
			printf("%I64d\n",w2/w1);
		else
			printf("%I64d/%I64d\n",w2/w,w1/w); 	
	}
return 0;
}