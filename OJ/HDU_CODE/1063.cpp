////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-21 13:59:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#define N 160
int in[N],out[N],temp[N];
char ans[N];
void A(char *s)
{
	int len = strlen(s);
    char *p = s + len - 1;
    if (strchr(s, '.'))
		while (!(*p>='1'&&*p<='9')&&*p!='.') *p-- = '\0';//让*p='\0',然后p--;
		if (*p == '.') *p = '\0';
}
void multiply(int a[N],int b[N],int c[N])
{
	int i,j,w=0,v=0,m,n;
	for(i=0;i<N;i++)//初始化
		c[i]=0;
	m=n=N-1;
	while(!a[m]&&m>0) m--;
	while(!b[n]&&n>0) n--;
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			c[i+j]+=a[i]*b[j];//很巧妙
		for(i=0;i<N-1;i++)//进位处理
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
}
int main ()
{
	char *pa,a[20];
	int i,b,k,j;
	while(scanf("%s %d",a,&b)!=EOF)
	{
		memset(in,0,sizeof(in));
		memset(temp,0,sizeof(temp));
		memset(out,0,sizeof(out));
		memset(ans,'\0',sizeof(ans));
		if(b==0)
		{printf("1\n");continue;}
		int flag=-12,flag1=0;//标记输入的是否是整数
		for(k=0,i=strlen(a)-1;i>=0;i--)
		{
			if(a[i]=='.')
				flag=strlen(a)-i-1;//记录小数点位子，即小数点后有几位
			else
				in[k++]=a[i]-'0';
		}
		for(i=0;i<k;i++)
			temp[i]=out[i]=in[i];
		int tt=k-1;
		while(out[tt]==0&&tt>=0) tt--;//n==1时去前导0
		if(tt<0)
		{printf("0\n");flag1=1;continue;}
		int T=b-1;//要乘的次数
		while(T--)
		{
			multiply(in,temp,out);
			memcpy(temp,out,N*sizeof(int));
		}
		//int pos=flag*b;
		if(flag==-12)//输入为整数的情况
		{
			i=N-1;
			while(!temp[i]) i--;
			if(i<0)
				printf("0");
			for(;i>=0;i--)
				printf("%d",temp[i]);
			printf("\n");
		}
		else
		{
			int pos=flag*b;
			for(i=0,j=N-1;i<N;i++,j--)
			{
				if(i<pos)
					ans[j]=out[i]+'0';
				else if(i==pos)
				ans[j]='.';
				else
					ans[j]=out[i-1]+'0';
			}
			pa=ans;
			A(pa);
			while(*pa=='0') pa++;
			puts(pa);
		}
	}
	return 0;
}