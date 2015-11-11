////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-11-03 20:27:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1074
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:476KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct px
{
	char S[101];//��ѧ������
	int D,C;//D��ʾ�����ߣ�C��ʾ��Ҫ������
};
char out[16][101],str[16][101];//out[][]�������������˳��str[][]������ʱ����
px stu[16];
int N;
const int IF=99999999;
int flag[65536];//�����������ô����ҵ����С����
int mark[16];//���ڱ��
int work[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void dfs(int day,int cost, int num,int sum)
//day��ʾ��ʼʱ�䣬cost��ʾ���õĻ��ѣ�num��ʾ�Ѿ��������ҵ����sum��¼��ҵ��ɵ�˳��
{
	int i,temp;
	if(num==N)
	{
		flag[sum]=cost;
		for(i=0;i<N;i++)
			strcpy(out[i],str[i]);
		return;
	}
	for(i=1;i<=N;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			sum+=work[i];
			temp=day+stu[i].C-stu[i].D;
			if(temp<0)
				temp=cost;
			else
				temp+=cost;
			if(flag[sum]>temp)
			{
				flag[sum]=temp;//DP˼�룬��̬�Ż�
				strcpy(str[num++],stu[i].S);
				dfs(day+stu[i].C,temp,num,sum);
				num--;//����
			}
			mark[i]=0;//����
			sum-=work[i];
		}
	}
	return;
}
main ()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			scanf("%s%d%d",stu[i].S,&stu[i].D,&stu[i].C);
		//memset(flag,IF,sizeof(flag));//��ʼ��
		for(i=0;i<65536;i++)
            flag[i] =IF;
		memset(mark,0,sizeof(mark));
		dfs(0,0,0,0);
		int ans=0;
		for(i=1;i<=N;i++)
			ans+=work[i];//���������±�Ϊans��flag[ans]ֵ��
		printf("%d\n",flag[ans]);
		for(i=0;i<N;i++)
			puts(out[i]);
	}
	return 0;
}