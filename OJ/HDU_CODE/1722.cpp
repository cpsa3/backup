////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-05-05 16:41:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1722
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*
 * =====================================================================================
 *
 *       Filename:  a.c
 *
 *    Description:  ���·
 *
 *        Version:  1.0
 *        Created:  2011��05��05�� 15ʱ39��26��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S��dwestfalen, Iserlohn
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
int f(int a,int b)
{
	if(b%a==0) return b;
	return b-b%a+f(b%a,a);
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",f(a,b));
	}
return 0;
}