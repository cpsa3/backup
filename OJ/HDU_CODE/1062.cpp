////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-09 16:24:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>

char str[1001];

int main( )
{
   int T,k;
   int i,len;
   int lower,upper;

   scanf("%d",&T);
   getchar( );
   for(k=0;k<T;k++)
   {
       gets(str);
       len=strlen(str);
       i=0;
       for(;i<len;i++)
       {
           lower=i;
           while(str[i]!=' ' && str[i]!='\0')
               i++;
           upper=i-1;
           for(;upper>=lower;upper--)
               printf("%c",str[upper]);
           if(str[i]==' ')
               printf(" ");
       }
       printf("\n");
   }

   return 0;
}
