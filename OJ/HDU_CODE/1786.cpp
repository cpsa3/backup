////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-30 13:48:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1786
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*�ݹ�*/
#include <iostream>
#include <stdlib.h>
int w[12];
int N,M;
int cmp(const void *p1,const void *p2)
{return *(int *)p2-*(int *)p1;}
int min(int a,int b)
{return a<b?a:b;}
void get_w()//����w[i]
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&w[i]);
	qsort(w+1,N,sizeof(int),cmp);
}
int get_ans(int s,int k)//����s�������ӵ�k����Ʒ��ʼ��������Ҫ����
{
	int i,ans=99999999,t;
	if(s%w[k]==0)//��������ֱ�ӷ���
		return s/w[k];
	if(k==N)//û�з����Һ���û����Ʒ�ͷ���-1
		return -1;
	int l=min(s/w[k],w[k+1]-1);//����������
	//����˵������������w[k+1]����ֻҪ����w[k]����ٷ�(w[k+1]-1)�μ���
	for(i=0;i<=l;i++)//�����ٷ�w[k]�Ĵ���0��w[k+1]-1
	{
		t=get_ans(s%w[k]+i*w[k],k+1);
		if(t==-1)//���ܷ���
			continue;
		ans=min(t+s/w[k]-i,ans);
	}
return ans;
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)
			break;
		get_w();
		printf("%d\n",3*get_ans(M,1));
	}
	return 0;
}