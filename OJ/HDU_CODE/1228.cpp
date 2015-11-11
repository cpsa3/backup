////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-27 22:22:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
main ()
{
    const  char a[12][6]={"zero","one","two","three","four","five","six","seven","eight","nine","+","="};
    int x,y;
    int i,j,k;
    char stu[300];
    char t[10];
    char s[30];
    do
    {
        i=j=k=x=y=0;
        memset(stu,'\0',sizeof(stu));
        memset(t,'\0',sizeof(t));
        memset(s,'\0',sizeof(s));
        gets(stu);
        for(i=0,k=0;i<strlen(stu);++i)
        {
            for(j=0;!isspace(stu[i])&&i<strlen(stu);++j,++i)
                t[j]=stu[i];
            t[j]='\0';
            for(j=0;j<12;j++)
            
                if(!strcmp(t,a[j]))
                {
                    if(j<=9) s[k++]=j+'0';
                    if(j==10) s[k++]='+';
                    if(j==11) s[k++]='=';
                    break;
                }
        }
        s[k]='\0';
        sscanf(s,"%d+%d=",&x,&y);
        if(x==0&&y==0)
            break;
        else
            printf("%d\n",x+y);
    }while(1);
return 0;
}
