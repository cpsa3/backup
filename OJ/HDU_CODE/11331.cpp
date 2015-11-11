////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
int f[205][MAX]={0};//������0-204�Ľ׳�
int ans[MAX];//������𰸵�
void multiply(int a[],int Max,int b)//a[MAX-1]�����λ��a[0]�����λ
{
	int i,temp=0;
	for(i=Max-1;i>=0;i--)
	{
		temp=temp+a[i]*b;
		a[i]=temp%BASE;//ע��
		temp/=BASE;
	}
}
void divide(int a[],int Max,int b)
{
	int i,temp=0;
	for(i=0;i<Max;i++)
	{
		temp=temp*BASE+a[i];
		a[i]=temp/b;//ע�ⲻ��д��a[i]/=BASEҲ����д��a[i]=temp/BASE
		temp%=b;//ע�ⲻ��д��temp%=BASE
	}
}
void SetFact()//����֮ǰ���������ݽ��д���
{
	int i;
	f[0][MAX-1]=f[1][MAX-1]=1;
	for(i=2;i<=200;i++)
	{
		memcpy(f[i],f[i-1],MAX*sizeof(int));//��f[i-1]�Ľ׳˸��Ƹ�f[i]��
		multiply(f[i],MAX,i);//����f[i]�Ľ׳�
	}
}
void OutPut(int w[MAX])
{
	int i=0;
	while(!w[i]) i++;
	printf("%d",w[i++]);//���λ���⴦��
	while(i<MAX)
		printf("%04d",w[i++]);//ע�������ʽ
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
		memcpy(ans,f[n+m],MAX*sizeof(int));//�׳� ( m + n )!
		multiply(ans,MAX,m-n+1);//( m + n )! * ( m-n+1 )
		divide(ans,MAX,m+1);//( m + n )! * ( m-n+1 )  / ( m+ 1 ) 
		OutPut(ans);//�����
	}
return 0;
}