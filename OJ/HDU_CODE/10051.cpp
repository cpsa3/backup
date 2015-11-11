////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 12:24:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[60];
main()
{
	int A,B,n,i,start,len,j;
	while(scanf("%d%d%d",&A,&B,&n)!=EOF)
	{
		if(A==0&&B==0&&n==0)
			break;
		f[1]=f[2]=1;
		int flag=0;
		for(i=3;i<=51;i++)
		{
			f[i]=(A*f[i-1]+B*f[i-2])%7;
			for(j=i-1;j>1;j--)
			{
				if(f[j]==f[i]&&f[j-1]==f[i-1])
				{start=j-1;len=i-j;flag=1;break;}
			}
			if(flag)
		 		break;
		}
		if(n<start)
			printf("%d\n",f[n]);
		else
		{
			n=(n-start)%len;
			if(n==0)
				printf("%d\n",f[start+len]);
			else
			printf("%d\n",f[start+n]);
		}
	}
return 0;
}
