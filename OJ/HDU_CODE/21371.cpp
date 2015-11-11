////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 16:33:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100][100];
char str[100];
int len,n;
void print()
{
    int i,j;
    for(i=0;i<len;i++)
    {
       for(j=0;j<len;j++)
       {
        printf("%c",s[i][j]);
         if(s[i][j]!=' '&&s[i][j+1]==' ')break;
       }
      printf("\n");
    }
}
int main()
{
    int i,j,k,len1,sum;
    char num[10000];
    while(scanf("%s %s",str,num)!=EOF)
     {
         sum=0;
         len1=strlen(num);
         if(len1>3)
         {
           sum=num[len1-1]-'0'+(num[len1-2]-'0')*10+(num[len1-3]-'0')*100;
         }
         else sum=atoi(num);
         n=sum%8;len=strlen(str);
         for(i=0;i<len;i++)
         for(j=0;j<len;j++)
         s[i][j]=' ';
         if(n==0)
         {
             printf("%s\n",str);continue ;
         }
         else if(n==1)
         {
             for(k=0,i=len-1,j=0;i>=0;j++,i--,k++)
             s[i][j]=str[k];
        }
        else if(n==2)
        {
         for(k=0,i=len-1;k<len;k++,i--)
         s[i][len/2]=str[k];    
        }
        else if(n==3)
        {
            for(i=len-1,j=len-1,k=0;i>=0;j--,i--,k++)
            s[i][j]=str[k];
        }
        else if(n==4)
        {
        printf("%s\n",strrev(str));continue;
        }
        else if(n==5)
        {
            for(j=len-1,i=k=0;j>=0;i++,k++,j--)
            s[i][j]=str[k];
        }
        else if(n==6)
        {
            for(i=k=0;i<len;i++,k++)
            s[i][len/2]=str[k];
        }
        else 
        {
            for(i=j=k=0;i<len;i++,k++,j++)
            s[i][j]=str[k];
        }
        print();
    }
    return 0;
}
