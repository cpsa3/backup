////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-12 15:33:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
int p[26] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int a[26];
int b[26];
char c;
main ()
{
	int k,m,w,q;

	while(1)
	{
		int i=1;
		while(1)
		{
			scanf("%d",&a[i]);
			i++;
			scanf("%c",&c);
			if(c!=',')
				break;
		}
		int j=1;
		while(1)
		{
			scanf("%d",&b[j]);
			j++;
			scanf("%c",&c);
			if(c!=',')
				break;
		}
		if(a[1]==0&&b[1]==0)
			break;
	
		a[0]=b[0]=0;
		if(i>=j)
		{
			for(k=j-1,m=i-1,w=1,q=0;m>=0;k--,m--,w++)
			{
				if(a[m]+b[k]+q>=p[w])
				{a[m]=a[m]+b[k]+q-p[w];q=1;}
				else
				{a[m]=a[m]+b[k]+q;q=0;}
				if(k==0)
					k++;
			}
			if(a[0]!=0)
				printf("%d,",a[0]);

				for(k=1;k<i-1;k++)
					printf("%d,",a[k]);
				printf("%d\n",a[k]);
		}
		else if(i<j)
		{
			for(k=i-1,m=j-1,w=1,q=0;m>=0;k--,m--,w++)
			{
				if(a[k]+b[m]+q>=p[w])
				{b[m]=a[k]+b[m]+q-p[w];q=1;}
				else
				{b[m]=a[k]+b[m]+q;q=0;}
				if(k==0)
					k++;
			}
			if(b[0]!=0)
				printf("%d,",b[0]);
			for(k=1;k<j-1;k++)
				printf("%d,",b[k]);
			printf("%d\n",b[k]);
		}	
	}
return 0;	
}
