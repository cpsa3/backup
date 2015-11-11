////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-04-11 17:34:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2719
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*×Ö·û´®*/
#include <iostream>
#include <cstring>
char s[100];
int main()
{
	int i;
	while(gets(s))
	{
		if(s[0]=='#') break;
		int len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]==' ') printf("%%20");
			else if(s[i]=='!') printf("%%21");
			else if(s[i]=='$') printf("%%24");
			else if(s[i]=='%') printf("%%25");
			else if(s[i]=='(') printf("%%28");
			else if(s[i]==')') printf("%%29");
			else if(s[i]=='*') printf("%%2a");
			else printf("%c",s[i]); 
		}
		printf("\n"); 
	}
return 0;
}

