////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
#include <set>//��STL�еļ���
#include <string>
using namespace std;
main ()
{
	set<string>st;//����һ��string��ļ���
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
				st.insert(s);//�����в���s
			s="";//���
		}
		printf("%d\n",st.size());
		st.clear();//��ռ���
		s="";
	}
return 0;
}