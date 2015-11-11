////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 15:11:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,t,a,b,c,i,j;
	char x;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			cin>>x;
				cin>>t;
			a=t/6+1;
			b=(t-3)/2;
			c=t-b-3;
			for(i=1;i<=a;i++)
				cout<<" ";
			for(i=1;i<=c;i++)
				cout<<x;
			cout<<endl;
			for(i=1;i<=b;i++)
			{
				for(j=1;j<=a;j++)
					cout<<x;
				for(j=1;j<=c;j++)
					cout<<" ";
				for(j=1;j<=a;j++)
					cout<<x;
				cout<<endl;
			}
			for(i=1;i<=a;i++)
				cout<<" ";
			for(i=1;i<=c;i++)
				cout<<x;
			cout<<endl;

				for(i=1;i<=c;i++)
			{
				for(j=1;j<=a;j++)
					cout<<x;
				for(j=1;j<=c;j++)
					cout<<" ";
				for(j=1;j<=a;j++)
					cout<<x;
				cout<<endl;
			}
			for(i=1;i<=a;i++)
				cout<<" ";
			for(i=1;i<=c;i++)
				cout<<x;
			cout<<endl;
		if(n>=1)
				cout<<endl;
		}
	}

return 0;
}
