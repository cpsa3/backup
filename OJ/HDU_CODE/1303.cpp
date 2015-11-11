////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-23 09:34:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1303
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
	int k=1,i,j;
	while(scanf("%d",&a[k])!=EOF)
	{
		if(a[k]==-1)
			break;
		if(a[k]==0)
		{
			sort(a+1,a+k);
			/*for(i=1;i<=k;i++)
				printf("%d ",a[i]);
			printf("\n");*/
			int ans=0;
			for(i=1;i<k-1;i++)
			{
				for(j=i+1;j<k;j++)
				{
					if((a[j]/a[i]==2)&&(a[j]%a[i]==0))
					{ans++;break;}
				}
			}
			printf("%d\n",ans);
			k=1;
		}
		else
			k++;
	}
return 0;
} 
