////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-06 22:06:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1455
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int a[100],n,ss,ll,mark[100],flag,ww[2000];
void dfs(int c,int sum1,int k)
{
    int i; 
	if(!ww[ll-sum1])
		return;
    if(flag||c==ss-1)
	{flag=1;return;}
	if(sum1==ll)
	{
		for(i=n;i>=1;i--)//剪枝1：搜索下一根大棍子的时候，找到第一个还没有使用的小棍子开始
			if(!mark[i])//由于排序过，找到的第一根肯定最长，也肯定要使用，所以从下一根开始搜索
				break;
			mark[i]=1;
			dfs(c+1,a[i],i-1);
			mark[i]=0;//一定要加，不然WA
	}
	else
	{
		for(i=k;i>=1;i--)
		{
			if(i<n&&mark[i+1]==0&&a[i+1]==a[i])//剪枝2：前后两根长度相等时，如果前面那根没被使用，也就是由前面那根
				continue;//开始搜索不到正确结果，那么再从这根开始也肯定搜索不出正确结果，此剪枝威力较大
			if(!mark[i]&&a[i]+sum1<=ll)//剪枝3：最简单的剪枝，要拼成一根大棍子还需要的长度L>=当前小棍子长度，才能选用                   
			{
				mark[i]=1;
				dfs(c,sum1+a[i],i-1);
				mark[i]=0;
				if(a[i]+sum1==ll)//剪枝4：威力巨大的剪枝，程序要运行到此处说明往下的搜索失败，若本次的小棍长度刚好填满剩下长度，但是后
					break;//面的搜索失败，则应该返回上一层
			}
		}
	}
	return;
}
int main ()
{
    int i,sum,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
		memset(ww,0,sizeof(ww));
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+1+n);//剪枝5
		if(a[1]>50)
			continue;
        while(a[n]>50) 
        {sum-=a[n];n--;}
		ww[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=sum-a[i];j>=0;j--)
				if(ww[j])
					ww[j+a[i]]=1;
		}
        for(i=a[n];i<=sum;i++)
        {
            if(sum%i||!ww[i])
                continue;
            memset(mark,0,sizeof(mark));
            ss=sum/i;
            ll=i;
			flag=0;
			dfs(0,0,n);
            if(flag)
            {printf("%d\n",i);break;}
			if(2*i>=sum)
			{printf("%d\n",sum);break;}
        }
    }
	return 0;
}

