////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-09-29 18:48:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",2*n*n-n+1);
	}
return 0;
}
/*
n��ƽ�������ķֵ�ƽ������1 + 4n(n+1)/2 - 2n = 2n2 + 1��
ÿ��һ��ƽ�����ཻ�󣬾ͻ����һ����
�������չ�ʽΪ��2n2 - n + 1 */
