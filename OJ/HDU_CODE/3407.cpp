////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
/*DFA�Զ�����kmp*/
/*AC���룺32ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 100006
#define kind 26
using namespace std;
char word[MAXN];//ģʽ��
struct Node
{
	int next[kind],v,fail; 
}Trie[5*MAXN+10];
int snode;//�ֵ������ܽ����(��״̬��)
int N;//ģʽ����Ŀ
int cas;
void set_node(int x)
{
	memset(Trie[x].next,0,sizeof(Trie[x].next));
	Trie[x].v=0;//��ʾ�Ƿ���Σ�ս��
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
		//if(Trie[pos].v)/*Σ�ս��Ϊ���ӽ�㲻�ؼ���(��֦)*/
		//	break;
		pos=Trie[pos].next[index];
	}
	//Trie[pos].v++;
}
void Find_Fail(int pre,int ith,int now)
{
	if(!pre)//������ĸ��ڵ���root,failֱ��ָ��root 
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
			//if(Trie[Trie[temp].next[ith]].v)//ע��
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
			if(Trie[pos].next[i]!=0)//���ھ�Ҫȥ��failָ��
			{
				Find_Fail(pos,i,Trie[pos].next[i]);
				Q.push(Trie[pos].next[i]);
			}
			else//������nextָ��pos��fail��next
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