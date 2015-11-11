////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-23 22:19:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1686
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1260KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
char S[1000005];
char T[10005];
int next[10005];
int lens,lent,ans;
void get_next()
{
	int i=1,t;
	next[0]=-1;
	while(i<=lent)
	{
		t=next[i-1];
		while((t+1)&&T[t+1]!=T[i])
			t=next[t];
		next[i]=t+1;
		i++;
	}
}
void get_ans()
{
	get_next();
	int i,p=0;
	for(i=1;i<=lens;i++)
	{
		while(p>0&&T[p+1]!=S[i])
			p=next[p];
		if(T[p+1]==S[i])
			p++;
		if(p==lent)
		{ans++;p=next[p];}
	}
	printf("%d\n",ans);
}
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%s",T+1);
		scanf("%s",S+1);
		lent=strlen(T+1);
		lens=strlen(S+1);
		ans=0;
		get_ans();
	}
	return 0;
}
