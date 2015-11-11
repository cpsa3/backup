////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-23 16:35:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1336
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
char a[10],b[10],c[10];
main ()
{
	int k,j,i;
	while(scanf("%s",b)!=EOF)
	{
		if(strlen(b)>6||!(b[0]>='a'&&b[0]<='z'))
		{printf("0\n");continue;}
		for(i=1;i<strlen(b);i++)
			if(b[i-1]>=b[i]||!(b[i]>='a'&&b[i]<='z'))
				break;
			if(i!=strlen(b))
			{printf("0\n");continue;}
			memset(a,'\0',sizeof(a));
			memset(c,'\0',sizeof(c));
			a[0]='a';
			c[0]=a[0];
			int s=1;
			while(strcmp(c,b))
			{
				a[0]++;
				s++;
				k=0;
				while(a[k]>('z'-k))
				{
					k++;
					if(a[k]=='\0')
					{a[k]='a';break;}
					else  a[k]++; 
				}
				k--;
				for(;k>=0;k--)
					a[k]=a[k+1]+1;
				k=9;
				while(a[k]=='\0') k--;
				for(j=0;k>=0;k--,j++)
					c[j]=a[k];
				c[j]='\0';
			}	
			printf("%d\n",s);
	}
return 0;
}