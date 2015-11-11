////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-29 16:31:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*旋转的次数可能是负数，表示顺时针，水平时只输出一行，每行字符后面没有多余的空格*/
/*要考虑N是大数*/
#include <iostream>
#include <string.h>
char s[100],N[1000];
int len;
void reserve()
{
	int i,j;
	char t[100];
	for(i=0,j=len-1;i<len;i++,j--)
		t[i]=s[j];
	t[i]='\0';
	strcpy(s,t);
}
int main()
{
	int i,j,ans;
	while(scanf("%s%s",s,N)!=EOF)
	{
		len=strlen(s);
		int lenN=strlen(N);
		ans=0;
		if(lenN<=3)
		{
			for(i=0;i<lenN;i++)
				ans=ans*10+N[i]-'0';
		}
		else
		{
			for(i=lenN-3;i<lenN;i++)
				ans=ans*10+N[i]-'0';
		}
		ans=ans%8;
		if(ans==0||ans==4)
		{
			//for(i=1;i<=len/2;i++)
			//	printf("\n");
			if(ans==4)
				reserve();
			puts(s);
			//for(i=1;i<=len/2;i++)
			//	printf("\n");
		}
		else if(ans==1||ans==5)
		{
			if(ans==1)
				reserve();
			for(i=0;i<len;i++)
			{
				for(j=1;j<=len-i-1;j++)
					printf(" ");
				printf("%c\n",s[i]);
			}
		}
		else if(ans==2||ans==6)
		{
			if(ans==2)
				reserve();
			for(i=0;i<len;i++)
			{
				for(j=1;j<=len/2;j++)
					printf(" ");
				printf("%c\n",s[i]);
			}
		}
		else
		{
			if(ans==3)
				reserve();
			for(i=0;i<len;i++)
			{
				for(j=1;j<=i;j++)
					printf(" ");
				printf("%c\n",s[i]);
			}
		}
	}
return 0;
}