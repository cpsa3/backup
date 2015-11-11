////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-29 23:03:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3407
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:944KB
//////////////////System Comment End//////////////////
/*DFA自动机或kmp*/
/*AC代码：32ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 100006
#define kind 26
using namespace std;
char word[MAXN];//模式串
struct Node
{
	int next[kind],v,fail; 
}Trie[5*MAXN+10];
int snode;//字典树的总结点数(总状态数)
int N;//模式串数目
int cas;
void set_node(int x)
{
	memset(Trie[x].next,0,sizeof(Trie[x].next));
	Trie[x].v=0;//表示是否是危险结点
	Trie[x].fail=0; 
}
void Insert(char s[])
{
	int i=0,pos=0,index;
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		index=s[i]-'a';
		if(Trie[pos].next[index]==0)
		{
			set_node(++snode);
			Trie[pos].next[index]=snode; 
		}
		//if(Trie[pos].v)/*危险结点为其子结点不必继续(剪枝)*/
		//	break;
		pos=Trie[pos].next[index];
	}
	//Trie[pos].v++;
}
void Find_Fail(int pre,int ith,int now)
{
	if(!pre)//如果他的父节点是root,fail直接指向root 
	{ 
	 	Trie[now].fail=0;
	 	return;
	}
	int temp=Trie[pre].fail;
	while(temp!=-1)
	{
		if(Trie[temp].next[ith]!=0)
		{
			Trie[now].fail=Trie[temp].next[ith];
			//if(Trie[Trie[temp].next[ith]].v)//注意
			//	Trie[now].v++;
			return;
		}
		temp=Trie[temp].fail; 
	}
	if(temp==-1)
		Trie[now].fail=0;
	return; 
}
queue<int>Q;
void Build_AC_Fail()
{
	int i,pos;
	while(!Q.empty()) Q.pop(); 
	Trie[0].fail=-1; 
	Q.push(0); 
	while(!Q.empty())
	{
		pos=Q.front();Q.pop();
		for(i=0;i<kind;i++)
		{
			if(Trie[pos].next[i]!=0)//存在就要去找fail指针
			{
				Find_Fail(pos,i,Trie[pos].next[i]);
				Q.push(Trie[pos].next[i]);
			}
			else//让它的next指向pos的fail的next
				Trie[pos].next[i]=Trie[Trie[pos].fail].next[i];
		}
	}
}
void Solve()
{
	int i,j;
	set_node(0);snode=0;
	Insert(word);
	Build_AC_Fail();
	for(i=0;i<=snode;i++)
	{
		printf("%d",i);
		for(j=0;j<26;j++)
			printf(" %d",Trie[i].next[j]);
		printf("\n");
	}
}
int main()
{
	while(scanf("%s",word)!=EOF)
	{
		if(word[0]=='0') break;
		Solve();
	}
return 0;
}