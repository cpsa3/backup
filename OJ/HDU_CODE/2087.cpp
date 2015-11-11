////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 21:24:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main ()
{
    char a[1001],b[1001];
    int i,j,s;
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='#') break;
        scanf("%s",b);
        s=0;
        for(i=0,j=0;i<strlen(a);i++,j++)
        {
            
            if(a[i]!=b[j])
                j=-1;
            if(j==strlen(b)-1) {s++;j=-1;}
        }
        printf("%d\n",s);
    }
return 0;
}