////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-23 10:19:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int w[18][301];
main ()
{
	int n,i,j,k;
	for(i=1;i<=17;i++)
		for(j=0;j<=300;j++)
			if(i==1||j==0)/*��ʼ��w��ֵ����<=1��ֵ��Ȼ��һ�ַ�����j=0��ʼ��Ϊ1��ԭ���ǣ�   
      w[i][j] += w[i-1][j-k*i*i]�����j-k*i*i == 0,����k����ֵΪ   
      i*i��Ӳ��ǡ�ÿ����滻���е����е�Ӳ����֧���������������1������0��   
      ��Ƚ����⣬����<=(i-1)*(i-1)��ֵ��Ǯ����j-k*i*i�ķ����������*/   
				w[i][j]=1;
			else
				w[i][j]=0;
	for(i=2;i<=17;i++)
		for(j=1;j<=300;j++)
			for(k=0;j-k*i*i>=0;k++)
				w[i][j]+=w[i-1][j-k*i*i];
	while(scanf("%d",&n)!=EOF&&n)
		printf("%d\n",w[17][n]);
return 0;
}