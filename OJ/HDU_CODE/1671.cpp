////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-26 10:18:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:3448KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <malloc.h>   
struct Trie
{
	struct Trie *child[10];
	bool n;//ͳ���Դ�Ϊǰ׺�ĵ�����
};
char a[10005][15];
struct Trie *root;//���ڵ�
int flag;
void Insert(char *source)
{
	int i,j,len;
	struct Trie *node,*p;
	len=strlen(source);
	if(len==0) return;
	p=root;//pΪ��ǰ�ĵ� 
	for(i=0;i<len;i++)
	{
		if(p->child[source[i]-'0']!=0)//�Ѿ����ڣ��Ͳ����½����
			p=p->child[source[i]-'0'];
		else
		{
			node=(struct Trie*)malloc(sizeof(struct Trie));
			for(j=0;j<10;j++)
				node->child[j]=0;
			node->n=false;
			p->child[source[i]-'0']=node;
			p=node;
		}
	}
	p->n=true; 
}
void clear(Trie *p)//�ݹ鶨�� 
{   
    if(p->n) 
       free(p);   
	else 
	{   
        for (int i=0;i<10;i++)  
            if(p->child[i]!=NULL)
                clear(p->child[i]);   
        free(p);   
    }   
}  
bool Find(char *source)
{
    int i,len;
    len=strlen(source);
    struct Trie *p;
    p=root;
    if(len==0) return 1;
    for(i=0;i<len-1;i++)
    {
        if(p->child[source[i]-'0']!=0)
		{
			p=p->child[source[i]-'0'];
			if(p->n)//һ��Ҫ���ں���
				return 0;
		}
    }
    return 1;
} 
int main()
{
	int i,T,n,t;
	scanf("%d",&T);
	while(T--)
	{
		root=(struct Trie*)malloc(sizeof(struct Trie));
		for(i=0;i<10;i++)
			root->child[i]=0;
		root->n=false;
		scanf("%d",&n);
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			Insert(a[i]);
		}
		for(i=0;i<n;i++)
		{
			t=Find(a[i]);
			if(!t)
			{flag=1;break;}
		
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
		clear(root);
	}
	return 0;
}