////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-12 13:46:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int T,N,sum;
int map[15][15];
struct px
{
	char dh;//门派
	int x,y;//坐标
	int	n;//内力
	int w;//武力
	int s;//生命力
	bool isF;//是否战斗过
	int dir;//方向1为正方向，0为反方向  少林的正方向是下 武当的正方向是右，峨眉的正方向是右下
};
struct px stu[1005];
int get_g(char dh,int n,int w,int s)//计算攻击力
{
	double ans;
	if(dh=='S')
		ans=(0.5*n+0.5*w)*(s+10)*1.0/100;
	else if(dh=='W')
		ans=(0.8*n+0.2*w)*(s+10)*1.0/100;
	else
		ans=(0.2*n+0.8*w)*(s+10)*1.0/100;
	return (int)ans;
}

void disp()//输出答案
{
	int rs,rw,re,ss,sw,se,i;
	rs=rw=re=ss=sw=se=0;
	for(i=1;i<=sum;i++)
	{
		switch(stu[i].dh)
		{
		case 'S':
			if(stu[i].s>0)
			{rs++;ss+=stu[i].s;}break;
		case 'W':
			if(stu[i].s>0)
			{rw++;sw+=stu[i].s;}break;
		case 'E':
			if(stu[i].s>0)
			{re++;se+=stu[i].s;}break;
		}
	}
	printf("%d %d\n",rs,ss);//少林
	printf("%d %d\n",rw,sw);//武当
	printf("%d %d\n",re,se);//峨眉
	printf("***\n");
}

void move()//移动
{
	int i;
	for(i=1;i<=sum;i++)
	{
		stu[i].isF=false;//每次到一个新的地方，都标为未战斗
		map[stu[i].x][stu[i].y]--;//因为要走了，所以这一点认识减一
		switch(stu[i].dh)
		{
		case 'S':
			if(stu[i].x==12) stu[i].dir=0;//方向变反
			if(stu[i].x==1) stu[i].dir=1;
			if(!stu[i].dir) stu[i].x--;
			else stu[i].x++;
			break;
		case 'W':
			if(stu[i].y==12) stu[i].dir=0;//方向变反
			if(stu[i].y==1) stu[i].dir=1;
			if(!stu[i].dir) stu[i].y--;
			else stu[i].y++;
			break;
		case 'E':
			if(stu[i].x==12||stu[i].y==12)
				stu[i].dir=0;
			if(stu[i].x==1||stu[i].y==1)
				stu[i].dir=1;
			if((stu[i].x==1&&stu[i].y==12)||(stu[i].x==12&&stu[i].y==1))//特殊情况
				break;
			else
			{
				if(!stu[i].dir)
				{stu[i].x--;stu[i].y--;}
				else
				{stu[i].x++;stu[i].y++;}
			}
			break;
		}
		map[stu[i].x][stu[i].y]++;//到了一个新的坐标，人数加一
	}	
}

void fight()
{
	int i,j,g1,g2;
	while(N--)//N步后
	{
		for(i=1;i<=sum;i++)//每次移动之前都要遍历所有人
		{
			if(map[stu[i].x][stu[i].y]==2&&!stu[i].isF&&stu[i].s>0)////当前位置只有2个人。同时大侠i在本回合内没有格斗过，到然大侠i还不能死。。   
			{
				for(j=1;j<=sum;j++)
				{
					if((stu[i].x==stu[j].x&&stu[i].y==stu[j].y)&&stu[i].dh!=stu[j].dh&&stu[j].s>0)//1,不同门派2.坐标相同3.这人没死
					{
						g1=get_g(stu[i].dh,stu[i].n,stu[i].w,stu[i].s);
						g2=get_g(stu[j].dh,stu[j].n,stu[j].w,stu[j].s);
						stu[i].s-=g2;
						stu[j].s-=g1;
						stu[i].isF=true;
						stu[j].isF=true;
					}
				}
			}
		}
	//一回合过去了，各位武林高手开始移动。。
		move();
	}
}
int main()
{
	char temp[2];
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));//地图初始化
		scanf("%d",&N); 
		sum=0;
		while(scanf("%s",temp)!=EOF)
		{
			if(temp[0]=='0')
				break;
			sum++;
			stu[sum].dh=temp[0];
			stu[sum].isF=false;
			stu[sum].dir=1;
			scanf("%d%d%d%d%d",&stu[sum].x,&stu[sum].y,&stu[sum].n,&stu[sum].w,&stu[sum].s);
			map[stu[sum].x][stu[sum].y]++;//标记该坐标上的现有人数
		}
		fight();
		disp();
	}
	return 0;
}