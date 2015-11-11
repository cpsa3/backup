////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 11:46:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*数列递归衍生问题*/
/*AC代码：0ms*/
#include <iostream>
#define min(a,b) (a<b?a:b)
int f[6000];
void Init()
{
	int x2,x3,x5,x7,i;
	f[1]=1;
	x2=x3=x5=x7=1;
	for(i=2;i<=5842;i++)
	{
		f[i]=min(min(f[x2]*2,f[x3]*3),min(f[x5]*5,f[x7]*7));
		if(f[i]==f[x2]*2) x2++;
		if(f[i]==f[x3]*3) x3++;
		if(f[i]==f[x5]*5) x5++;
		if(f[i]==f[x7]*7) x7++;
	} 
}
int main()
{
	int n;
	Init();
	while(scanf("%d",&n),n)
	{
		int x=n%10,y=n%100;
		if(x==1&&y!=11) printf("The %dst humble number is %d.\n",n,f[n]);
		else if(x==2&&y!=12) printf("The %dnd humble number is %d.\n",n,f[n]);
		else if(x==3&&y!=13) printf("The %drd humble number is %d.\n",n,f[n]);
		else printf("The %dth humble number is %d.\n",n,f[n]);
	}
	return 0;
}