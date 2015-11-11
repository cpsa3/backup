////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
	char dh;//����
	int x,y;//����
	int	n;//����
	int w;//����
	int s;//������
	bool isF;//�Ƿ�ս����
	int dir;//����1Ϊ������0Ϊ������  ���ֵ����������� �䵱�����������ң���ü��������������
};
struct px stu[1005];
int get_g(char dh,int n,int w,int s)//���㹥����
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

void disp()//�����
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
	printf("%d %d\n",rs,ss);//����
	printf("%d %d\n",rw,sw);//�䵱
	printf("%d %d\n",re,se);//��ü
	printf("***\n");
}

void move()//�ƶ�
{
	int i;
	for(i=1;i<=sum;i++)
	{
		stu[i].isF=false;//ÿ�ε�һ���µĵط�������Ϊδս��
		map[stu[i].x][stu[i].y]--;//��ΪҪ���ˣ�������һ����ʶ��һ
		switch(stu[i].dh)
		{
		case 'S':
			if(stu[i].x==12) stu[i].dir=0;//����䷴
			if(stu[i].x==1) stu[i].dir=1;
			if(!stu[i].dir) stu[i].x--;
			else stu[i].x++;
			break;
		case 'W':
			if(stu[i].y==12) stu[i].dir=0;//����䷴
			if(stu[i].y==1) stu[i].dir=1;
			if(!stu[i].dir) stu[i].y--;
			else stu[i].y++;
			break;
		case 'E':
			if(stu[i].x==12||stu[i].y==12)
				stu[i].dir=0;
			if(stu[i].x==1||stu[i].y==1)
				stu[i].dir=1;
			if((stu[i].x==1&&stu[i].y==12)||(stu[i].x==12&&stu[i].y==1))//�������
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
		map[stu[i].x][stu[i].y]++;//����һ���µ����꣬������һ
	}	
}

void fight()
{
	int i,j,g1,g2;
	while(N--)//N����
	{
		for(i=1;i<=sum;i++)//ÿ���ƶ�֮ǰ��Ҫ����������
		{
			if(map[stu[i].x][stu[i].y]==2&&!stu[i].isF&&stu[i].s>0)////��ǰλ��ֻ��2���ˡ�ͬʱ����i�ڱ��غ���û�и񶷹�����Ȼ����i������������   
			{
				for(j=1;j<=sum;j++)
				{
					if((stu[i].x==stu[j].x&&stu[i].y==stu[j].y)&&stu[i].dh!=stu[j].dh&&stu[j].s>0)//1,��ͬ����2.������ͬ3.����û��
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
	//һ�غϹ�ȥ�ˣ���λ���ָ��ֿ�ʼ�ƶ�����
		move();
	}
}
int main()
{
	char temp[2];
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));//��ͼ��ʼ��
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
			map[stu[sum].x][stu[sum].y]++;//��Ǹ������ϵ���������
		}
		fight();
		disp();
	}
	return 0;
}