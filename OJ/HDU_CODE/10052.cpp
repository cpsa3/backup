////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-03 12:29:54
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
		for(i=3;i<=59;i++)
		{
			f[i]=(A*f[i-1]+B*f[i-2])%7;
			for(j=2;j<=i-1;j++)
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
			n=(n-start-1)%len+1;
			printf("%d\n",f[start+n]);
		}
	}
return 0;
}
//����Ҫע��ľ���ѭ����һ���Ǵ���ʼλ�ÿ�ʼ��,�����Ǵ��м��ĳ��λ��i��ʼ,��jΪһ��ѭ��
/*f[n-1]��f[n-2]���������������һ����7*7=49����;
��ô���f[i-1]��f[i-2]��ֵΪm��n,��������ȥ,��49������֮��,�϶������f[j-1]��f[j-2]��ֵΪm��n*/
