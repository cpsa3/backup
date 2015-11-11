////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 13:31:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int p[101][4];
int wei[101];
int shu[101];
int panduan(int a[],int n)
{
	int flag[4];
	int w,s,i,j,k;
	for(i=0;i<n;i++)
	{
		memset(flag,0,4*sizeof(int));
		s=w=0;
		for(j=0;j<4;j++)
			if(a[j]==p[i][j]) w++;
			for(j=0;j<4;j++)
				for(k=0;k<4;k++)
					if(a[j]==p[i][k]&&!flag[k])
					{s++;flag[k]=1;break;}

					if(w!=wei[i]||s!=shu[i])
						return 0;
	
	}

	return 1;


}


main ()
{
	char v[101][6];
	int i,j,k,n,d[4],t,a[3];
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",v[i],&shu[i],&wei[i]);
			for(j=0;j<4;j++)
				p[i][j]=v[i][j]-'0';
		}

		for(i=1000,t=0;i<10000;i++)
		{
			k=i;
			for(j=0;j<4;j++)
			{
				d[j]=k%10;
				k=k/10;
			
			}
			swap(d[0],d[3]);
			swap(d[1],d[2]);
			if(panduan(d,n))
			{a[t++]=i;}
			if(t>=2)
				break;
		}
		if(t!=1)
			cout<<"Not sure"<<endl;
		else
			cout<<a[0]<<endl;
		
	
	}



return 0;


}