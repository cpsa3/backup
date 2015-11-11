////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
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
	char S[101];//存学科名字
	int D,C;//D表示死亡线，C表示需要多少天
};
char out[16][101],str[16][101];//out[][]用来存最终输出顺序，str[][]用于临时储存
px stu[16];
int N;
const int IF=99999999;
int flag[65536];//用来存完成这么多作业的最小花费
int mark[16];//用于标记
int work[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void dfs(int day,int cost, int num,int sum)
//day表示开始时间，cost表示已用的花费，num表示已经处理的作业数，sum记录作业完成的顺序
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
				flag[sum]=temp;//DP思想，动态优化
				strcpy(str[num++],stu[i].S);
				dfs(day+stu[i].C,temp,num,sum);
				num--;//回溯
			}
			mark[i]=0;//回溯
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
		//memset(flag,IF,sizeof(flag));//初始化
		for(i=0;i<65536;i++)
            flag[i] =IF;
		memset(mark,0,sizeof(mark));
		dfs(0,0,0,0);
		int ans=0;
		for(i=1;i<=N;i++)
			ans+=work[i];//结果存放在下标为ans的flag[ans]值中
		printf("%d\n",flag[ans]);
		for(i=0;i<N;i++)
			puts(out[i]);
	}
	return 0;
}