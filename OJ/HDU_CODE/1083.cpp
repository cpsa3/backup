////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-22 12:35:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <iostream>
bool map[105][305];//�ڽӾ��� true�����б�����
bool flag[305];//��¼V2�е�ÿ�����Ƿ�������
int result[305];//��¼V2�еĵ�ƥ��ĵ�ı��
int T,P,N,ans;
void init()
{
	int i,j,x,n;
	ans=0;
	memset(map,false,sizeof(map));
	memset(result,0,sizeof(result));
	scanf("%d%d",&P,&N);
	for(i=1;i<=P;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			map[i][x]=true;
		}
	}
}
bool Find(int a)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(map[a][i]&&!flag[i])//����ڵ�i��a���ڲ���δ�����ҹ�
		{
			flag[i]=true;//���iΪ�Ѳ��ҹ�
			if(result[i]==0||Find(result[i]))//���iδ��ǰһ��ƥ��M��||//i��ƥ��M��,���Ǵ���i���ڵĽڵ��������������·
			{
				result[i]=a;//��¼���ҳɹ���¼
				return true;//���ز��ҳɹ� 
			}
		}
	}
	return false;
}
int main()
{
	int i;
	scanf("%d",&T);
	while(T--)
	{
		init();
		for(i=1;i<=P;i++)
		{
			memset(flag,false,sizeof(flag));//����ϴ�����ʱ�ı�� 
			if(Find(i)) ans++;//�ӽڵ�i������չ
		}
		if(ans==P)
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;
}