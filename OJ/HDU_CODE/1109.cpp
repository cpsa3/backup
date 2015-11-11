////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-06 22:08:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1109
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
const int RanN=10;
const int RunN=25;
const double P=0.7;
int X,Y,M;
struct px
{
	double x,y,d;
};
struct px stu[1001];
struct px S[RanN+1];
int Max(int x,int y)
{
	return x>y?x:y;
}
double get_dis(px t)
{
	double sum=1e10,temp;
	int i;
	for(i=1;i<=M;i++)
	{
		temp=sqrt((double)((t.x-stu[i].x)*(t.x-stu[i].x)+(t.y-stu[i].y)*(t.y-stu[i].y)));
		if(sum>temp)
			sum=temp;
	}
	return sum;
}
void get_ans()
{
	int i,r;
	double delta,epsilon=1e-2,k1,k2,max;
	px temp;
	delta=(double)Max(X,Y)/(sqrt(1.0*M));
	for(r=1;r<=RanN;r++)
	{
		S[r].x=double(rand()%1000+1)/1000.000*X;
		S[r].y=double(rand()%1000+1)/1000.000*Y;
		S[r].d=get_dis(S[r]);
	}
	while(delta>epsilon)
	{
		for(r=1;r<=RanN;r++)
		{
			for(i=1;i<=RunN;i++)
			{
				k1=double(rand()%1000+1)/1000.000*delta;//������
				k2=sqrt(delta*delta-k1*k1);//k1,k2��ƽ���Ϳ�������delta
				if (rand()%2==1) k1*=-1;//������
				if (rand()%2==1) k2*=-1;
				temp.x=S[r].x+k1;
				temp.y=S[r].y+k2;
				if(temp.x<=X&&temp.x>=0&&temp.y<=Y&&temp.y>=0)//�ڽ��ڲŴ���
				{
					max=get_dis(temp);
					if(max>S[r].d)//ֱ�Ӹ��¸õ�
					{S[r].d=max;S[r].x=temp.x;S[r].y=temp.y;}
				}
			}
		}
		delta*=P;
	}
	max=0;
	px ans;
	for(i=1;i<=RanN;i++)
	{
		if(S[i].d>max)
		{max=S[i].d;ans=S[i];}
	}
	printf("The safest point is (%.1lf, %.1lf).\n",ans.x,ans.y);
}
int main ()
{
    int T,i;
    scanf("%d",&T);
    srand((unsigned)time(NULL)); 
    while(T--)
    {
        scanf("%d%d%d",&X,&Y,&M);
        for(i=1;i<=M;i++)
        {
            scanf("%lf%lf",&stu[i].x,&stu[i].y);
            //if(stu[i].x<0||stu[i].x>X||stu[i].y<0||stu[i].y>Y)//��ȥ�����
			//{i--;M--;}
        }
        get_ans();
    }
	return 0;
}

