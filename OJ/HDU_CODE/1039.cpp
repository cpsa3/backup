////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-09 15:46:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int vo(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		return 1;
	else
		return 0;
}
int f1(char a[30])
{
	int i;
	for(i=0;i<strlen(a);i++)
		if(vo(a[i]))
			return 1;
		return 0;
}

int f2(char a[30])
{
	int i;
	if(strlen(a)<3)
		return 1;
	for(i=0;i<=strlen(a)-3;i++)
	{
		if(vo(a[i])==vo(a[i+1])&&vo(a[i])==vo(a[i+2]))
			return 0;
	}
	return 1;
}

int f3(char a[30])
{
	int i;
	if(strlen(a)<2)
		return 1;
	for(i=0;i<=strlen(a)-2;i++)
	{
		if(a[i]==a[i+1]&&a[i]!='e'&&a[i]!='o')
			return 0;
	}
return 1;
}

main ()
{
	char a[30],b[4]={'e','n','d','\0'};
	while(scanf("%s",a)!=EOF)
	{
		if(!strcmp(a,b))
			break;
		printf("<%s>",a);
		if(f1(a)&&f2(a)&&f3(a))
			printf(" is acceptable.\n");
		else
			printf(" is not acceptable.\n");
	}
return 0;
}