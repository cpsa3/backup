////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-28 18:19:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <iostream>
char a[200002],b[200002];
int main ()
{
    int i,j;
    while(scanf("%s%s",a,b)!=EOF)
    {
        int n=strlen(a);
        int m=strlen(b);
        if(n<m)
        {printf("no\n");continue;}
        for(i=0,j=n;i<n;j++,i++)
            a[j]=a[i];
        int flag=0;
        for(i=0;i<=2*n-m;i++)
        {
            int w=i;
            for(j=0;j<m&&w<2*n;j++,w++)
            {
                if(a[w]!=b[j])
                    break;
            }
            if(j==m)
            {flag=1;break;}
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
return 0;
}