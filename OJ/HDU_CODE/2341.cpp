////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-24 23:36:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2341
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int map[51][51];
main ()
{
	int t,h,l,i,j,k,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&l);
		for(i=1;i<=h;i++)
			for(j=1;j<=l;j++)
				scanf("%d",&map[i][j]);
			int sum=0;
			for(k=1;;k++)
			{
				int flag=0;
				for(i=1;i<=h;i++)
				{
					for(j=1;j<=l;j++)
					{
						if(map[i][j]==k)
						{
							flag=1;
							sum+=2*(i-1)*10;
							if(j-1<=l-j+1)
								sum+=5*(j-1);
							else
								sum+=5*(l-j+1);
								int temp[51],step=j-1;
							for(m=1;m<=l;m++)
							{
								if(m+step>l)
									temp[m]=map[i][m+step-l];
								else
									temp[m]=map[i][m+step];
							}
							for(m=1;m<=l;m++)
								map[i][m]=temp[m];
							break;
						}
					}
					if(flag)
						break;
				}
				if(flag==0)
					break;
			}
			printf("%d\n",sum);
	}
return 0;	
}

