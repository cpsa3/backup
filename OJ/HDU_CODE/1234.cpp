////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-27 22:29:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct time
{
	char a[30];
	int h1;
	int m1;
	int s1;
	int h2;
	int m2;
	int s2;


};
main ()
{
	struct time stu[100];
	struct time t,s;
	int N,M,i;
	while(cin>>N)
	{
		while(N--)
		{
			cin>>M;
			for(i=1;i<=M;i++)
			{
				scanf("%s",stu[i].a);
				scanf("%d:%d:%d",&stu[i].h1,&stu[i].m1,&stu[i].s1);	
				scanf("%d:%d:%d",&stu[i].h2,&stu[i].m2,&stu[i].s2);
			}
			t=s=stu[1];
			for(i=2;i<=M;i++)
			{
				if(s.h1>stu[i].h1)
					s=stu[i];
				else if(s.h1==stu[i].h1)
					if(s.m1>stu[i].m1)
						s=stu[i];
					else if(s.m1==stu[i].m1)
						if(s.s1>stu[i].s1)
							s=stu[i];
			}
			for(i=2;i<=M;i++)
			{
				if(t.h2<stu[i].h2)
					t=stu[i];
					else if(t.h2==stu[i].h2)
					if(t.m2<stu[i].m2)
						t=stu[i];
					else if(t.m2==stu[i].m2)
						if(t.s2<stu[i].s2)
						t=stu[i];
			}
			printf("%s %s\n",s.a,t.a);	
		}
	}
return 0;
}