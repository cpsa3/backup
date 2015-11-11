////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
		for(i=n;i>=1;i--)//��֦1��������һ������ӵ�ʱ���ҵ���һ����û��ʹ�õ�С���ӿ�ʼ
			if(!mark[i])//������������ҵ��ĵ�һ���϶����Ҳ�϶�Ҫʹ�ã����Դ���һ����ʼ����
				break;
			mark[i]=1;
			dfs(c+1,a[i],i-1);
			mark[i]=0;//һ��Ҫ�ӣ���ȻWA
	}
	else
	{
		for(i=k;i>=1;i--)
		{
			if(i<n&&mark[i+1]==0&&a[i+1]==a[i])//��֦2��ǰ�������������ʱ�����ǰ���Ǹ�û��ʹ�ã�Ҳ������ǰ���Ǹ�
				continue;//��ʼ����������ȷ�������ô�ٴ������ʼҲ�϶�����������ȷ������˼�֦�����ϴ�
			if(!mark[i]&&a[i]+sum1<=ll)//��֦3����򵥵ļ�֦��Ҫƴ��һ������ӻ���Ҫ�ĳ���L>=��ǰС���ӳ��ȣ�����ѡ��                   
			{
				mark[i]=1;
				dfs(c,sum1+a[i],i-1);
				mark[i]=0;
				if(a[i]+sum1==ll)//��֦4�������޴�ļ�֦������Ҫ���е��˴�˵�����µ�����ʧ�ܣ������ε�С�����ȸպ�����ʣ�³��ȣ����Ǻ�
					break;//�������ʧ�ܣ���Ӧ�÷�����һ��
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
        sort(a+1,a+1+n);//��֦5
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

