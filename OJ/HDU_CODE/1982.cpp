////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-08 23:42:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1982
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*Ä£Äâ*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring> 
char ss[10005]; 
int main()
{
	int i,T,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",ss);
		int len=strlen(ss);
		w=-1;
		for(i=0;i<len;i++)
		{
			if(ss[i]>='0'&&ss[i]<='9')
			{
				if(w==-1) w=0;
				w=w*10+ss[i]-'0';
			}
			else 
			{
				if(w!=-1) printf("%c",'A'+w-1);
				w=-1;
				if(ss[i]=='#') printf(" "); 
			}  
		} 
		if(w!=-1) printf("%c",'A'+w-1);
		printf("\n");
	}
return 0;
}