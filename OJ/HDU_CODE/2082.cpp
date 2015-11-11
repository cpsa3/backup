////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-09-18 14:20:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<iostream>
int a[27];
int c;
void dfs(int pi, int s,int n)
{
    s+=n*pi;
	c++;  
    int i;
    for(i=pi+1;i<=26;i++)
    {
        if(s+i>50)//剪枝
            break;
        if(a[i]>0)//如果有这个字母
        {
            int j;
            for(j=1;j<=a[i];j++)
            {
                if(s+i*j>50)
                    break;
                dfs(i,s,j);
            }
        }
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		c=-1;
		int i;
		a[0]=0;
		for(i=1;i<=26;i++)
			scanf("%d",&a[i]);
		dfs(0,0,0);
		printf("%d\n",c);
	}
	return 0;
}

