////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-21 11:46:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1065
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*ˮ��*/
/*
�����λ������ ��Ϊ��ҵ�λ��
��Բ�Ŀ�ʼ ½�ؿ�ʼ��ʴ ��һ����Բ����״��ʼ��ʴ
ÿ�궼��ʴ50 square miles ��ڼ��긯ʴ����ҵ�λ��
*/
#include <iostream>
#include <cmath>
#define P 3.1415926
int main()
{
	int T,i;
	scanf("%d",&T);
	double x,y;
	for(i=1;i<=T;i++)
	{
		scanf("%lf%lf",&x,&y);
		double r=sqrt(x*x+y*y);
		double area=P*r*r/2;
		double ans=area/50;
		if(ans!=(int)ans)
			ans++;
		printf("Property %d: This property will begin eroding in year %d.\n",i,(int)ans);
	}
	printf("END OF OUTPUT.\n"); 
return 0;
}