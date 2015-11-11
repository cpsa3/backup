////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 20:41:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3456
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
char a[1005];
char b[1005];
int main()
{
	int i;
	while(gets(a)!=NULL)
	{
		int len=strlen(a);
		int flag=0;
		int k=0;
		for(i=0;i<len;i++)
		{
			if(flag)
			{
				if(a[i]=='?')
				{
					b[k++]='.';
					b[k]='\0';
					printf("%s\n",b);
					flag=0;
				}
				else if(a[i]=='.')
					flag=0;
				else
					b[k++]=a[i];
			}
			else
			{
				if(a[i]=='W')
				{
					if(a[i+1]=='h'&&a[i+2]=='a'&&a[i+3]=='t'&&a[i+4]==' '&&a[i+5]=='i'&&a[i+6]=='s')
					{
						flag=1;
						strcpy(b,"Forty-two is");
						i=i+6;
						k=12;
					}
				}
			}
		}
	}
	return 0;
}