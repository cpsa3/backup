////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-17 20:49:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1865
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1004KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
int f[201][1000];
main ()
{
    int i,n,w,j;
    char a[400];
    f[0][0]=1;f[1][0]=1;f[2][0]=2;f[3][0]=3;
    for(i=4;i<=200;i++)
    {
        for(j=0,w=0;j<1000;j++)
        {
        f[i][j]=f[i-1][j]+f[i-2][j]+w;
        w=f[i][j]/10;
        f[i][j]=f[i][j]%10;
        }
    }
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s",a);
        int m=strlen(a),flag=0;
        for(j=999;j>=0;j--)
        {
            if(f[m][j]||flag)
            {printf("%d",f[m][j]);flag=1;}
        }
        printf("\n");
    }
return 0;
} 