////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-17 11:08:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:708KB
//////////////////System Comment End//////////////////
#include <iostream>
int flag[250005];
main ()
{
	int n,i,j,a[51],b[51];
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			break;
		int sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			sum+=a[i]*b[i];
		}
		for(i=1;i<=sum;i++)
			flag[i]=0;
		flag[0]=1;
		for(i=1;i<=n;i++)
		{
			while(b[i]--)
			{
				for(j=sum-a[i];j>=0;j--)
					if(flag[j])
						flag[j+a[i]]=1;
			}
		}
		//if(sum==1)
		//	printf("1 0\n");
			if(sum%2==0)
				i=sum/2;
			else
				i=sum/2+1;
			while(!flag[i]) i++;
			printf("%d %d\n",i,sum-i);
	}
return 0;
}
