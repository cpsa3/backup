////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-25 23:53:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1131
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:660KB
//////////////////System Comment End//////////////////
/*����������Ӧ��*/
/*�����������Ĳ�ͬ���췽�����п����������ģ��������ﲻ�޶�����
Ϊ���������ʸ�����ΪCatalan��*A��n��n),*/
/*���ƹ�ʽ��h(n+1)=(n+1)*(4n+2)/(n+2)*h(n)   h(0)=1;*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int a[200][2000];
int b[200];
int N;
void fuck()
{
    int i,j,len,temp;
    b[1]=1;a[1][0]=1;
    len=1;
    for(i=2;i<=100;i++)
	{
		int t=i-1;
		for(j=0;j<len;j++)//��λ���
			a[i][j]=a[i-1][j]*(4*t+2)*(t+1);
		for(j=0;j<len-1;j++)//��˽������
		{
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
		int r=a[i][j];
		while(r)//��λ����
		{
			a[i][len-1]=r%10;
			r/=10;
			len++;
		}
		int m=0;
		for(j=len-1;j>=0;j--)//��������
		{
			temp=m*10+a[i][j];
			a[i][j]=temp/(t+2);
			m=temp%(t+2);
		}
		while(!a[i][len-1])//��λ�㴦��
			len--;
		b[i]=len;
	}
}
int main()
{
    int i,j;
    fuck();
    while(scanf("%d",&N),N)
    {
        for(j=b[N]-1;j>=0;j--)
            printf("%d",a[N][j]);
        printf("\n");
    }
return 0;
}