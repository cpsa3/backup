////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:46:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2714
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
char s[20];

void Solve()
{
	int i,sum,pos;
	sum=0;
	for(i=0;i<10;i++)
	{
		if(s[i]=='?') pos=10-i;
		else
		{
			if(s[i]=='X') sum+=10*(10-i);
			else sum+=(s[i]-'0')*(10-i);
		}
	}
	int ans=-1;
	for(i=0;i<=10;i++)
	{
		if((sum+pos*i)%11==0) 
		{ans=i;break;}
	}
	if(i==11||(i==10&&pos!=1))
		ans=-1;
	if(ans==10)
		printf("X\n");
	else
		printf("%d\n",ans);
}
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		Solve();
	}
return 0;
}