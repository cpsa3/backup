////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-26 10:29:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:3448KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <malloc.h>   
struct Trie
{
	struct Trie *child[10];
	bool n;//�ж��Ƿ��������
};
char a[10005][15];
struct Trie *root;//���ڵ�
int flag;
void Insert(char *source)//����
{
	int i,j,len;
	struct Trie *node,*p;
	len=strlen(source);
	if(len==0) return;
	p=root;//pΪ��ǰ�ĵ� 
	for(i=0;i<len;i++)
	{
		if(p->child[source[i]-'0']!=0)//�Ѿ����ڣ��Ͳ����½����
		{
			p=p->child[source[i]-'0'];
			if(p->n)
				flag=1;
		}
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
bool Find(char *source)//�����Ƿ��и����ַ�����ǰ׺�ڵ��ʱ���
{
    int i,len;
    len=strlen(source);
    struct Trie *p;
    p=root;
    if(len==0) return 1;
    for(i=0;i<len-1;i++)
    {
		p=p->child[source[i]-'0'];
		if(p->n)//һ��Ҫ���ں���(��Ȼ��WA��Ϊ���ж��˵����ڶ���)
			return 0;
    }
    return 1;
} 
void clear(Trie *p)//�����ͷŶ�̬������ڴ棬�ݹ鶨�� 
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
		if(!flag)
		{
			for(i=0;i<n;i++)
			{
				t=Find(a[i]);
				if(!t)
				{flag=1;break;}
				
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
		clear(root);
	}
	return 0;
}