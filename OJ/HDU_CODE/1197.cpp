////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 18:52:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool Judge(int x)
{
	int t=x;
	int a=x/1000+(x%1000)/100+(x%100)/10+x%10;
	int b=0;
	while(x)
	{
		b+=x%12;
		x/=12;
	}
	if(a!=b) return false;
	int c=0;
	while(t)
	{
		c+=t%16;
		t/=16;
	}
	if(c!=b) return false;
	return true;
}
int main()
{
	int i;
	for(i=2992;i<=9999;i++)
	{
		if(Judge(i))
			printf("%d\n",i);
	}
return 0;
}