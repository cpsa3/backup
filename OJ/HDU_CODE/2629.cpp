////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 18:26:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2629
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void Show(char x,char y)
{
	if(x=='3') 
	{
		if(y=='3')
		printf("Zhejiang");
		else
			printf("Shanghai");
	}
	else if(x=='1') printf("Beijing");
	else if(x=='7') printf("Taiwan");
	else if(x=='8') 
	{
		if(y=='1')
		printf("Hong Kong");
		else
			printf("Macao");
	}
	else if(x=='5') printf("Tibet");
	else if(x=='2') printf("Liaoning");
}
int main()
{
	int T;
	char s[200];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		printf("He/She is from ");
		Show(s[0],s[1]);
		printf(",and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",s[10],s[11],s[12],s[13],s[6],s[7],s[8],s[9]);
	}
return 0;
}