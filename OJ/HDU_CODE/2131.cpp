////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-08 20:14:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2131
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
main ()
{
	char w;
	string S;
	int i;
	while(cin>>w)
	{
		getchar();
		cin>>S;
		double v=0;
		transform(S.begin(),S.end(),S.begin(),::tolower);
		if(w>='A'&&w<='Z')
			w+=32;
		for(i=0;i<S.size();i++)
			if(S[i]==w)
				v++;
			v=v*1.0/S.size();
			printf("%.5lf\n",v);
	}
return 0;
}