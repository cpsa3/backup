////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2013-05-08 22:54:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int t, m, a, s;
	cin >> t;
	while ( t != 0 )
	{
		/* printf("#%d\n",t); */
		cin >> m;
		while ( m )
		{
			s = 0;
			while ( m != 0 )
			{
				cin >> a;
				s= s + a;
				m= m - 1;
			}
			cout << s << endl;
		}
		t = t - 1;
		if ( t != 0 )
			cout << endl;
	}
	return(0);
}