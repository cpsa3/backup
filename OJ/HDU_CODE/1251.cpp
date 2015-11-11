////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-21 21:17:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:43792KB
//////////////////System Comment End//////////////////
#include <iostream>
//#include<stdlib.h>
#include <string.h>
struct Trie
{
	struct Trie *child[26];
	int n;//统计以此为前缀的单词数
};
struct Trie *root;//根节点
void Insert(char *source)
{
	int i,j,len;
	struct Trie *node,*p;
	len=strlen(source);
	if(len==0) return;
	p=root;//p为当前的点 
	for(i=0;i<len;i++)
	{
		if(p->child[source[i]-'a']!=0)//已经存在，就不用新建结点
		{
			p=p->child[source[i]-'a'];
			p->n=p->n+1;
		}
		else
		{
			node=(struct Trie*)malloc(sizeof(struct Trie));
			for(j=0;j<26;j++)
				node->child[j]=0;
			//memset(node->child,0,sizeof(node->child));
			p->child[source[i]-'a']=node;
			p=node;
			p->n=1;
		}
	}
}
int Find(char *source)
{
	int i,len;
	len=strlen(source);
	struct Trie *p;
	p=root;
	if(len==0) return 0;
	for(i=0;i<len;i++)
	{
		if(p->child[source[i]-'a']!=0)
			p=p->child[source[i]-'a'];
		else
			return 0;
	}
	return p->n;
}
char temp[11];
int main()
{
	int i;
	root=(struct Trie*)malloc(sizeof(struct Trie));
	for(i=0;i<26;i++)
		root->child[i]=0;
	root->n=0;
	while(gets(temp),strcmp(temp,"")!=0)
		Insert(temp);
	while(scanf("%s",temp)!=EOF)
	{
		int ans=Find(temp);
		printf("%d\n",ans);
	}
	return 0;
}
