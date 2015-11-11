////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 20:46:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1990
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<char>V;
char a[200];
int f(int n)
{
	int i,s=1;
	if(n==0) return 1;
	for(i=1;i<=n;i++)
		s*=2;
	return s;
}
main ()
{
	int T,i,k;
	scanf("%d",&T);
	getchar();
	for(k=1;k<=T;k++)
	{
		gets(a);
		V.clear();
		int max=0;
		for(i=0;i<strlen(a);i++)
		{
			if(V.empty())
				V.push_back(a[i]);
			else if(V.back()=='['&&a[i]==']')
			{
				if(max<V.size())
					max=V.size();
				V.pop_back();
			}
			else V.push_back(a[i]);
		}
		printf("%d %d\n",k,f(max));
	}
return 0;
}