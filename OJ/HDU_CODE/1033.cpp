////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 03:37:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*模拟题*/
/*V表示逆时针旋转；A表示顺时针旋转*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;
char s[300];
int main()
{
	int i,d,x,y;
	while(scanf("%s",s)!=EOF)
	{
		printf("300 420 moveto\n310 420 lineto\n");
		x=310;y=420;d=0;
		int len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(d==0)
			{
				if(s[i]=='V')
				{
					y+=10;
					d=3;
					printf("%d %d lineto\n",x,y);
				}
				else
				{
					y-=10;
					d=1;
					printf("%d %d lineto\n",x,y);
				}
			}
			else if(d==1)
			{
				if(s[i]=='V')
				{
					x+=10;
					d=0;
					printf("%d %d lineto\n",x,y);
				}
				else
				{
					x-=10;
					d=2;
					printf("%d %d lineto\n",x,y);
				}
			}
			else if(d==2)
			{
				if(s[i]=='V')
				{
					y-=10;
					d=1;
					printf("%d %d lineto\n",x,y);
				}
				else
				{
					y+=10;
					d=3;
					printf("%d %d lineto\n",x,y);
				}
			}
			else
			{
				if(s[i]=='V')
				{
					x-=10;
					d=2;
					printf("%d %d lineto\n",x,y);
				}
				else
				{
					x+=10;
					d=0;
					printf("%d %d lineto\n",x,y);
				}
			}
		}
		printf("stroke\nshowpage\n"); 
	}
return 0;
}