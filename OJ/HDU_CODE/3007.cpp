////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2012-03-12 16:21:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3007
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*��С����Բģ����*/
#include <iostream>
#include<cstdio>
#include<cmath>
#define MAXN 2000000
using namespace std;
struct node
{
	double x,y;
};
node p[MAXN];
int n;//��ĸ���
double r;//��С����Բ�İ뾶
node O;//��С����Բ������
double dist(node a,node b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
void calc(double a,double b,double c,double d,double e,double f)//��������ֱ��ax+by+c=0,dx+ey+f=0 �󽻵�
{//ע�⵽�������������д��߲�����ƽ�У����Բ��������0����
	O.y=(c*d-f*a)/(b*d-e*a);
	O.x=(c*e-f*b)/(a*e-b*d);
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		//��������
		for (i=1;i<=n;++i) 
			scanf("%lf%lf",&p[i].x,&p[i].y);
		O=p[1];r=0;//��ʼC1
		int count=0;
		for (i=2;i<=n;++i)//A
		if (dist(O,p[i])>r+1e-6)
		{
			O=p[i];r=0;
			for (j=1;j<=i-1;++j)//B
				if (dist(O,p[j])>r+1e-6)
				{
					O.x=(p[i].x+p[j].x)/2;O.y=(p[i].y+p[j].y)/2;r=dist(O,p[j]);
					for (k=1;k<=j-1;++k){//C
						count++;
						if (dist(O,p[k])>r+1e-6)
						{
							calc(p[j].x-p[i].x,p[j].y-p[i].y,(p[j].x*p[j].x+p[j].y*p[j].y-p[i].x*p[i].x-p[i].y*p[i].y)/2,
								p[k].x-p[i].x,p[k].y-p[i].y,(p[k].x*p[k].x+p[k].y*p[k].y-p[i].x*p[i].x-p[i].y*p[i].y)/2);
							r=dist(O,p[k]);
						}
					}
				}
		}
		printf("%.2lf %.2lf %.2lf\n",O.x,O.y,r);
	}
return 0;
}
