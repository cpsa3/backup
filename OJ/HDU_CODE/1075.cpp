////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-21 11:48:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:67244KB
//////////////////System Comment End//////////////////
/*�ֵ���(��̬����)*/
/*AC���룺250ms*/
#include <iostream>
#include <cstring>
#define kind 26
using namespace std;
struct Trie
{
	char word[30];
	struct Trie *child[kind];
	Trie()//���캯��
	{
		word[0]='\0';
		for(int i=0;i<kind;i++)
			child[i]=NULL;
	}
	~Trie()//���������������ͷ��ڴ�
	{
		for(int i=0;i<kind;i++)
			if(child[i]!=NULL)
				delete child[i];
	}
};
struct Trie *root;
void Insert(char str[],char word[])
{
	int i,len,index;
	struct Trie *p;
	len=strlen(str);
	if(!len) return;
	p=root;
	for(i=0;i<len;i++)
	{
		index=str[i]-'a';
		if(!p->child[index])
		{
			p->child[index]=new Trie();
			if(i==len-1)//�ж��Ƿ����һ���ַ���������Ϣ��������
			strcpy(p->child[index]->word,word);
		}	
		p=p->child[index];
	}
}
bool Query(char word[])
{
	//printf("*\n");
	int i=0,index,len=strlen(word);
	if(!len) return false;//һ��Ҫ��
	struct Trie *p=root;
	char ans[30];
	if(p==NULL) return false;
	ans[0]='\0';
	while(word[i])
	{
		index=word[i]-'a';
		if(!p->child[index])
			return false;
		p=p->child[index];
		i++;
	}
	strcpy(ans,p->word);
	if(ans[0]=='\0')//����������peng,ȴ����pen�����´���������Ա���
		return false;
	printf("%s",ans);
	return true;//��ʾ�Ѿ��ҵ�
}
int main()
{
	int i=0;
	root=new Trie();
	char E_word[30],M_word[30],temp[30],w;
	gets(temp);
	while(scanf("%s",E_word)!=EOF)//�����ֵ���
	{
		if(!strcmp(E_word,"END"))
			break;
		scanf("%s",M_word);
		Insert(M_word,E_word);
	}
	getchar();//����һ��huiche
	gets(temp);//ȥ����START��
	while(1)//һ�����ַ�����
	{
		temp[i]=getchar();
		if(temp[i]=='E')//����END
			break;
		if(temp[i]<'a'||temp[i]>'z')
		{
			w=temp[i];
			temp[i]='\0';
			if(!Query(temp))
				printf("%s",temp);
			printf("%c",w);
			i=-1;//��i������0
		}
		i++;
	}
return 0;
}