////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-12-01 00:48:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3783
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[105];
int main()
{
	int i,j;
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='E') break;
		int len=strlen(s);
		int n1,n2,n3;
		n1=n2=n3=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='Z') n1++;
			else if(s[i]=='O') n2++;
			else n3++;
		}
		while(n1||n2||n3)
		{
			if(n1) {
				printf("Z");n1--;
			}
			if(n2){
				printf("O");n2--;
			}
			if(n3){
				printf("J");n3--;
			}
		}
		printf("\n");
	}
	return 0;
}