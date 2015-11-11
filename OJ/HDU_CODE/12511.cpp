////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-17 17:17:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:39420KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define kind 26
#define MAXN 2000000
using namespace std;

struct Trie
{
	int v;
	int next[kind];
}Tnode[MAXN];
int snode;
char word[20];

void set_node()
{
	Tnode[snode].v=0;
	memset(Tnode[snode].next,-1,sizeof(Tnode[snode].next));
}
void Insert(char s[])
{
	int i,p,Index;
	i=p=0;
	while(s[i])
	{
		Index=s[i]-'a';
		if(Tnode[p].next[Index]==-1)
		{
			snode++;
			set_node();
			Tnode[p].next[Index]=snode;
		}
		p=Tnode[p].next[Index];
		Tnode[p].v++;
		i++;
	}
}
int Query(char s[])
{
	int i,p,Index;
	int len=strlen(s);
	i=p=0;
	for(i=0;i<len;i++)
	{
		Index=s[i]-'a';
		if(Tnode[p].next[Index]==-1) return 0;
		p=Tnode[p].next[Index];
		//if(i==len-1) return Tnode[p].v;
	}
	return Tnode[p].v;
}
int main()
{
	snode=0;
	set_node();
	while(gets(word)!=NULL)
	{
		if(strcmp(word,"")==0) break;
		Insert(word);
	}
	while(scanf("%s",word)!=EOF)
	{
		int res=Query(word);
		printf("%d\n",res);
	}
	return 0;
}
