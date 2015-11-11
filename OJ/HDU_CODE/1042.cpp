////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-19 22:26:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <iostream>
#define MAX 1000000000
#define LEN 4000
using namespace std;
void multiply(int a[],int n)//����ģ�a[0]Ϊ���λ
{
	__int64 temp=0;
	int i,p=1,j;//pΪa[]�ĳ���
	a[0]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<p;j++)
		{
			temp=temp+(__int64)a[j]*i;//ע������Ҫ��ǿ��ת����__int64����Ȼ�����
			a[j]=temp%MAX;
			temp/=MAX;
		}
		if(temp>0)
		{a[p++]=temp;temp=0;}
	}
	p--;
	printf("%d",a[p--]);
	for(;p>=0;)
		printf("%09d",a[p--]);
	printf("\n");
}

main ()
{
	int a[LEN],n;
	while(scanf("%d",&n)!=EOF)
		multiply(a,n);
return 0;
}