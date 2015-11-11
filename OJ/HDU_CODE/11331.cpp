////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-19 16:44:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define BASE 10000
int f[205][MAX]={0};//用来存0-204的阶乘
int ans[MAX];//用来存答案的
void multiply(int a[],int Max,int b)//a[MAX-1]存最低位，a[0]存最高位
{
	int i,temp=0;
	for(i=Max-1;i>=0;i--)
	{
		temp=temp+a[i]*b;
		a[i]=temp%BASE;//注意
		temp/=BASE;
	}
}
void divide(int a[],int Max,int b)
{
	int i,temp=0;
	for(i=0;i<Max;i++)
	{
		temp=temp*BASE+a[i];
		a[i]=temp/b;//注意不能写成a[i]/=BASE也不能写成a[i]=temp/BASE
		temp%=b;//注意不能写成temp%=BASE
	}
}
void SetFact()//输入之前对所有数据进行处理
{
	int i;
	f[0][MAX-1]=f[1][MAX-1]=1;
	for(i=2;i<=200;i++)
	{
		memcpy(f[i],f[i-1],MAX*sizeof(int));//将f[i-1]的阶乘复制给f[i]；
		multiply(f[i],MAX,i);//计算f[i]的阶乘
	}
}
void OutPut(int w[MAX])
{
	int i=0;
	while(!w[i]) i++;
	printf("%d",w[i++]);//最高位特殊处理
	while(i<MAX)
		printf("%04d",w[i++]);//注意输出格式
	printf("\n");
}
main ()
{
	int m,n,k=1;
	SetFact();
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(n==0&&m==0)
			break;
		 printf ( "Test #%d:\n",k++);
		if(n>m)
		{printf("0\n");continue;}
		memcpy(ans,f[n+m],MAX*sizeof(int));//阶乘 ( m + n )!
		multiply(ans,MAX,m-n+1);//( m + n )! * ( m-n+1 )
		divide(ans,MAX,m+1);//( m + n )! * ( m-n+1 )  / ( m+ 1 ) 
		OutPut(ans);//输出答案
	}
return 0;
}