////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-06 11:49:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1066
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
 * =====================================================================================
 *
 *       Filename:  a.c
 *
 *    Description:  N!最后一个非零数
 *
 *        Version:  1.0
 *        Created:  2011年05月06日 10时47分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10005
int lastdigit(char buf[])
{
	const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
	int len=strlen(buf),a[MAXN],i,c,res=1;
	if(len==1) return mod[buf[0]-'0'];
	for(i=0;i<len;i++) a[i]=buf[len-1-i]-'0';
	for(;len;len-=!a[len-1])
	{
		res=res*mod[a[1]%2*10+a[0]]%5;
		for(c=0,i=len-1;i>=0;i--)
			c=c*10+a[i],a[i]=c/5,c%=5;
	}
	return res+res%2*5;
}
int main()
{
	char s[MAXN];
	while(scanf("%s",s)!=EOF)
	printf("%d\n",lastdigit(s));
	return 0;
}