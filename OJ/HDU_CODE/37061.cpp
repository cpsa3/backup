////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 13:30:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3706
////Problem Title: 
////Run result: Accept
////Run time:2171MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <iostream>
int N,A,B;
struct px
{
	int pos;
	__int64 value;
};
struct px Q[10000001];
main ()
{
	int i,j,head,tail;
	__int64 ans;
	while(scanf("%d%d%d",&N,&A,&B)!=EOF)
	{
		struct px s;
		head=1,tail=0;
		s.pos=1;s.value=1;
		ans=1;
		for(i=1;i<=N;i++)
		{
			s.pos=i;s.value=s.value*A%B;
			while(head<=tail && Q[tail].value>=s.value) tail--;
			tail++;
			Q[tail]=s;
			while(head<=tail && Q[head].pos<i-A) head++;
			ans=ans*Q[head].value%B;
		}
		printf("%I64d\n",ans);
	}
return 0;
}