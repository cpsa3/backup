////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-02 21:52:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <set>//用STL中的集合
#include <string>
using namespace std;
main ()
{
	set<string>st;//建立一个string类的集合
	string s="";
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='#') break;
		s+=c;
		while(c!='\n')
		{
			while((c=getchar())!=' '&&c!='\n')
				s+=c;
			if(s.length())
				st.insert(s);//集合中插入s
			s="";//清空
		}
		printf("%d\n",st.size());
		st.clear();//清空集合
		s="";
	}
return 0;
}