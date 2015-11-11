////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:27:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
char a[1000],b[1000];
int cmp(const void *x,const void *y)
{
   return *((char *)y)-*((char *)x);
}
main ()
{
    int i;
    while(scanf("%s",a)!=EOF)
    {
        strcpy(b,a);
        qsort(b,strlen(b),sizeof(char),cmp);
        for(i=0;i<strlen(b);i++)
        {
            printf("%c",a[i]);
            if(a[i]==b[0])
                printf("(max)");
        }
        printf("\n");
    }
return 0;
}