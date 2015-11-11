////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-19 22:37:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#define MAX 100000
#define LEN 8000
using namespace std;
void multiply(int a[],int n)//倒存的，a[0]为最低位
{
	int i,p=1,j,temp=0;//p为a[]的长度
	a[0]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<p;j++)
		{
			temp=temp+a[j]*i;//注意这里要先强制转换成__int64，不然会溢出
			a[j]=temp%MAX;
			temp/=MAX;
		}
		if(temp>0)
		{a[p++]=temp;temp=0;}
	}
	p--;
	printf("%d",a[p--]);
	for(;p>=0;)
		printf("%05d",a[p--]);
	printf("\n");
}

main ()
{
	int a[LEN],n;
	while(scanf("%d",&n)!=EOF)
		multiply(a,n);
return 0;
}