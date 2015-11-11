////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-23 10:19:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int w[18][301];
main ()
{
	int n,i,j,k;
	for(i=1;i<=17;i++)
		for(j=0;j<=300;j++)
			if(i==1||j==0)/*初始化w的值，用<=1币值显然有一种方法，j=0初始化为1的原因是，   
      w[i][j] += w[i-1][j-k*i*i]，如果j-k*i*i == 0,即用k个币值为   
      i*i的硬币恰好可以替换所有的所有的硬币来支付，这个方法数是1而不是0，   
      这比较特殊，与用<=(i-1)*(i-1)币值的钱来付j-k*i*i的方法数不相等*/   
				w[i][j]=1;
			else
				w[i][j]=0;
	for(i=2;i<=17;i++)
		for(j=1;j<=300;j++)
			for(k=0;j-k*i*i>=0;k++)
				w[i][j]+=w[i-1][j-k*i*i];
	while(scanf("%d",&n)!=EOF&&n)
		printf("%d\n",w[17][n]);
return 0;
}