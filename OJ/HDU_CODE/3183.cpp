////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-18 20:04:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3183
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*O(N^2)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define MAXN 1005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

char s[MAXN];
int n,len;

void Print()
{
	int i;
	bool ok=false;
	bool flag=false;
	for(i=0;i<len;i++)
	{
		if(s[i]=='*') continue;
		if(s[i]!='0')
		{
			ok=true;
			flag=true;
			printf("%c",s[i]);
		}
		else if(ok) 
		{
			printf("%c",s[i]);
			flag=true;
		}
	}
	if(!flag) printf("0");
	printf("\n");
}
void Solve()
{
	int i,a,Index,p;
	len=strlen(s);
	while(n--)
	{
		i=0;
		while(s[i]=='*') i++;
		a=s[i]-'0';
		bool ok=false;
		p=i;
		for(i=p+1;i<len;i++)
		{
			if(s[i]=='*') continue;
			if(s[i]-'0'<a) 
			{
				ok=true;
				Index=i;
				break;
			}
			else
			{
				a=s[i]-'0';
				p=i;
			}
		}
		//if(ok) s[Index]='*';
		//else s[p]='*';
		s[p]='*';
	}
	Print();
	//printf("%s\n",s);
}
int main()
{
	while(scanf("%s%d",s,&n)!=EOF)
	{
		Solve();
	}
	return 0;
} 