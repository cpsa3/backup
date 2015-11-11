////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 20:49:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3927
////Problem Title: 
////Run result: Accept
////Run time:781MS
////Run memory:476KB
//////////////////System Comment End//////////////////
/*随机算法*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <ctime>
#include <map>
#define MAXN 230
using namespace std;
int N,cas;
int G[MAXN][MAXN];
int H[MAXN],W[MAXN],C1,C2;
map<int,int>hash;
map<int,int>hash1;
void Print()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<N;j++)
			printf("%d ",G[i][j]);
		printf("%d\n",G[i][j]);
	}
}
void Init()
{
	int i,j,cnt;
	hash.clear();
	memset(H,0,sizeof(H));
	memset(W,0,sizeof(W));
	C1=C2=cnt=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			cnt=(i-1)*N+j;
			G[i][j]=cnt;
			//printf("%d\n",cnt);
			H[i]+=cnt;
			W[j]+=cnt;
			if(i==j) C1+=cnt;
			if(i+j==N+1) C2+=cnt;
		}
	}
	for(i=1;i<=N;i++)
	{
		hash[H[i]]++;
		hash[W[i]]++;
	}
	hash[C1]++;
	hash[C2]++;
}
bool Judge()
{
	int i,j;
	int H1[MAXN],W1[MAXN],D1,D2;
	memset(H1,0,sizeof(H1));
	memset(W1,0,sizeof(W1));
	hash1.clear();
	D1=D2=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			H1[i]+=G[i][j];
			W1[j]+=G[i][j];
			if(i==j) D1+=G[i][j];
			if(i+j==N+1) D2+=G[i][j];
		}
	}
	bool ok=true;
	for(i=1;i<=N;i++)
	{
		hash1[H1[i]]++;
		hash1[W1[i]]++;
	}
	hash1[D1]++;
	hash1[D2]++;
	for(i=1;i<=N;i++)
	{
		if(hash1[H1[i]]>1||hash1[W1[i]]>1)
		{ok=false;break;}
	}
	if(hash1[D1]>1||hash1[D2]>1) ok=false;
	return ok;
}
void Solve()
{
	int i,x1,y1,x2,y2,w1,w2;
	while(true)
	{
		x1=rand()%N+1;y1=rand()%N+1;
		x2=rand()%N+1;y2=rand()%N+1;
		
		if(x1==x2&&y1==y2) continue;
		w1=G[x1][y1];
		w2=G[x2][y2];
		
		if(x1!=x2)
		{
			hash[H[x1]]--;
			hash[H[x2]]--;
			H[x1]=H[x1]-w1+w2;
			H[x2]=H[x2]-w2+w1;
			hash[H[x1]]++;
			hash[H[x2]]++;
		}
		if(y1!=y2)
		{
			hash[W[y1]]--;
			hash[W[y2]]--;
			
			W[y1]=W[y1]-w1+w2;
			W[y2]=W[y2]-w2+w1;
			
			hash[W[y1]]++;
			hash[W[y2]]++;
		}
		
		if(x1==y1&&x2!=y2)
		{
			hash[C1]--;
			C1=C1-w1+w2;
			hash[C1]++;
		}
		if(x2==y2&&x1!=y1)
		{
			hash[C1]--;
			C1=C1-w2+w1;
			hash[C1]--;
		}
		if(((x1+y1)==(N+1))&&((x2+y2)!=(N+1)))
		{
			hash[C2]--;
			C2=C2-w1+w2;
			hash[C2]++;
		}
		if(((x2+y2)==(N+1))&&((x1+y1)!=(N+1)))
		{
			hash[C2]--;
			C2=C2-w2+w1;
			hash[C2]++;
		}
		G[x1][y1]=w2;
		G[x2][y2]=w1;
		bool ok=true;
		for(i=1;i<=N;i++)
		{
			if(hash[H[i]]>1||hash[W[i]]>1)
			{ok=false;break;}
		}
		if(hash[C1]>1||hash[C2]>1)
			ok=false;
		if(ok)//可能是各项和维护有误，出来之前在进行精确的判断
		{
			if(Judge())
				break;
			else
				ok=true;
		}
	}
	printf("Case #%d:\n",cas++);
	Print();
}
int main()
{
	int T;
	cas=1;
	srand(time(0));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		Init();
		Solve();
	}
	return 0;
}	
