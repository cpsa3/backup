////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-12 23:07:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:3000KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int p[100001];//�����ֵ����������һ����
//��������һ�������Լ�ʱ����ʾ������������ĸ���
int mark[100001],flag;//������¼�ñ���Ƿ���ֹ�,flag������¼�γɵ�ͼ�Ƿ�ɻ�
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x];
}

void bin(int x,int y)
{
	int a=find_set(x);
	int b=find_set(y);
	if(a!=b)
		p[a]=b;//ע�ⲻ��x��y
	else//�����������ͬ�ĸ��ڵ�˵���Ѿ��ɻ�
		flag=0;
}

main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==-1&&m==-1)
			break;
		if(n==0)
		{printf("Yes\n");continue;}//�ص㣬ע��յ�ͼҲΪ�桢��
		//����Ϊ�������Ϊֻ��һ����������(����ɢС����)����Ψһ�ļ��Ͽ���Ϊ��
		for(i=1;i<=100000;i++)
		{
			mark[i]=0;
			p[i]=i;//�����������Լ��ĸ�
		}
		mark[n]=mark[m]=1;//��ʾ�õ��Ѿ����ֹ�
		bin(n,m);
		flag=1;//��ʼ��Ϊ���ɻ�
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			if(n==0&&m==0)
				break;
			mark[n]=mark[m]=1;
			bin(n,m);
		}
		int w=0;//��¼�������
		for(i=1;i<=100000;i++)
		{
			if(mark[i]&&p[i]==i)
				w++;
			if(w>1)
			{flag=0;break;}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
return 0;
}