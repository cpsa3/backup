////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-18 21:54:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1023
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[101][101];
main ()
{
	int b[101],i,j,len,temp,n;
	b[1]=1;
	a[1][0]=1;
	len=1;
	for(i=2;i<=100;i++)
	{
		int t=i-1;
		for(j=0;j<len;j++)//逐位相乘
			a[i][j]=a[i-1][j]*(4*t+2);
		for(j=0;j<len-1;j++)//相乘结果处理
		{
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
		int r=a[i][j];
		while(r)//进位处理
		{
			a[i][len-1]=r%10;
			r/=10;
			len++;
		}
		int m=0;
		for(j=len-1;j>=0;j--)//大数除法
		{
			temp=m*10+a[i][j];
			a[i][j]=temp/(t+2);
			m=temp%(t+2);
		}
		while(!a[i][len-1])//高位零处理
			len--;
		b[i]=len;
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(j=b[n]-1;j>=0;j--)
			printf("%d",a[n][j]);
		printf("\n");
	}
return 0;
}
//C(0) = 1 ; (n+2)*C(n+1) = (4n+2)*C(n);
//卡特兰数的应用
