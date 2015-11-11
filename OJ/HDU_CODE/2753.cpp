////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-07 17:27:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2753
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:4116KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int a[105],f[1000005];
main ()
{
    int T,n,i,m,j;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d",&m,&n);
            for(i=1;i<=n;i++)
                scanf("%d",&a[i]);
            sort(a+1,a+1+n);//从小到大排序 
            memset(f,0,sizeof(f));
            f[0]=1;
            for(i=1;i<=n;i++)
            {
                for(j=100000;j>=0;j--)
                {
                    if(f[j])
                    {
                        if(!f[j+a[i]])
                        f[j+a[i]]=f[j]+1;
                        else 
                        {
                            if(f[j+a[i]]>f[j]+1)
                                f[j+a[i]]=f[j]+1;
                        }

                    }
                }
            }
            for(i=m;;i++)
                if(f[i])
                    break;
                printf("%d %d\n",i,f[i]-1);
        }
    }
return 0;
}