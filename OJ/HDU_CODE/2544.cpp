////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 16:16:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#define T 99999999
int f[101][101],n,m;
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
}
main ()
{
	int x,y,z,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				f[i][j]=T;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(z<f[x][y])
			f[x][y]=f[y][x]=z;
		}
		floyd();
		printf("%d\n",f[1][n]);
	}
return 0;
}