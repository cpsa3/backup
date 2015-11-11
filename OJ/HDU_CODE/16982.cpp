////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-25 19:58:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include<stdio.h>

int a[100001][3],c[100001];

int main()

{

    int t,i,j,n,m,sum,v,w=1;

    scanf("%d",&t);

    while(t--&&scanf("%d %d",&n,&m))

    {

        sum=0;

        for(i=1;i<=m;i++)

        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);

        for(i=1;i<=n;i++)

        {

            v=1;

            for(j=m;j>=1;j--)

            {

                if(a[j][0]<=i&&a[j][1]>=i)

                {

                    v=a[j][2];

                    break;

                }

            }

            sum+=v;

        }

        printf("Case %d: The total value of the hook is %d.\n",w++,sum);

    }

}

