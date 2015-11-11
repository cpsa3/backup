////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-02-14 21:02:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

char s[10005];
int main()
{
	int i;
	while(scanf("%s",s)!=EOF)
	{
		i=0;
		while(s[i]!='\0')
		{
			if(s[i]=='b') s[i]=' ';
			else if(s[i]=='q') s[i]=',';
			else if(s[i]=='t') s[i]='!';
			else if(s[i]=='m') s[i]='l';
			else if(s[i]=='i') s[i]='e';
			else if(s[i]=='c') s[i]='a';
			else if(s[i]=='a') s[i]='c';
			else if(s[i]=='e') s[i]='i';
			else if(s[i]=='l') s[i]='m';
			i++;
		}
		printf("%s\n",s);
	}
return 0;
}