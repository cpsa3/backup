////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2013-06-04 23:46:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <set>
#include <string>
using namespace std;
char str[100005];
set<string> hash;
int main()
{
	while(gets(str))
	{
		if(str[0] == '#') break;
		hash.clear();
		string x = "";
		int len = strlen(str);
		for(int i=0;i<len;i++)
		{
			if(str[i] != ' ') x += str[i];
			if(str[i] == ' ' && i != 0 && str[i-1] != ' ')
			{
				hash.insert(x);
				x = "";
			}
		}
		if(str[len-1] != ' ')
			hash.insert(x);
		cout<< hash.size()<<endl;
	}
	return 0;
}
