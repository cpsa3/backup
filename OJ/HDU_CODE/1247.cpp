////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-22 07:29:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:7368KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
using namespace std;
char s[60000][100],s1[100],s2[100];
struct Trie
{
	struct Trie *child[26];
	bool flag;//统计以此为前缀的单词数
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
			p=p->child[source[i]-'a'];
		else
		{
			node=new Trie;
			for(j=0;j<26;j++)
				node->child[j]=0;
			node->flag=false;
			p->child[source[i]-'a']=node;
			p=node;
			//p->flag=true;
		}
	}
	p->flag=true;//*注意:只有完全相同才标记为true
}
bool Find(char *source)
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
	return p->flag;
}
int main()
{
	int i,len,j,k,t;
	root=new Trie;
	for(i=0;i<26;i++)
		root->child[i]=0;
	root->flag=false;
	int n=0;
	while(gets(s[n])!=NULL)
	{
		Insert(s[n]);
		n++;
	}
	for(i=0;i<n;i++)
	{
		len=strlen(s[i]);
		for(j=1;j<len-1;j++)//分成两段
		{
			for(k=0;k<j;k++)
				s1[k]=s[i][k];
			s1[k]='\0';
			for(k=0,t=j;t<len;t++,k++)
				s2[k]=s[i][t];
			s2[k]='\0';
			if(Find(s1)&&Find(s2))
			{
				printf("%s\n",s[i]);
				break;
			}
		}
	}
	return 0;
}
