////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:44:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1482
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int map[20],temp[20];
main ()
{
    int T,i,j;
    char a[20],b[20],c[20];
    scanf("%d",&T);
    while(T--)
    {
        memset(map,0,sizeof(map));
        for(i=1;i<=3;i++)
        {
            scanf("%s%s%s",a,b,c);
            if(!strcmp(c,"even"))
            {
                for(j=0;j<strlen(a);j++)
                    map[a[j]-65]=1;
                for(j=0;j<strlen(b);j++)
                    map[b[j]-65]=1;
            }
            else if(!strcmp(c,"up"))
            {
                memset(temp,0,sizeof(temp));
                for(j=0;j<strlen(a);j++)
                {
                    temp[a[j]-65]=1;
                    if(map[a[j]-65]==1) continue;
                    if(map[a[j]-65]==0) map[a[j]-65]=2;
                    else if(map[a[j]-65]==3) map[a[j]-65]=1;
                }
                for(j=0;j<strlen(b);j++)
                {
                    temp[b[j]-65]=1;
                    if(map[b[j]-65]==1) continue;
                    if(map[b[j]-65]==0) map[b[j]-65]=3;
                    else if(map[b[j]-65]==2) map[b[j]-65]=1;
                }
                for(j=0;j<12;j++)
                    if(!temp[j])
                        map[j]=1;
            }
            else
            {
                memset(temp,0,sizeof(temp));
                for(j=0;j<strlen(a);j++)
                {
                    temp[a[j]-65]=1;
                    if(map[a[j]-65]==1) continue;
                    if(map[a[j]-65]==0) map[a[j]-65]=3;
                    else if(map[a[j]-65]==2) map[a[j]-65]=1;
                }
                for(j=0;j<strlen(b);j++)
                {
                    temp[b[j]-65]=1;
                    if(map[b[j]-65]==1) continue;
                    if(map[b[j]-65]==0) map[b[j]-65]=2;
                    else if(map[b[j]-65]==3) map[b[j]-65]=1;
                }
                for(j=0;j<12;j++)
                    if(!temp[j])
                        map[j]=1;
            }
        }
        for(i=0;i<12;i++)
            if(map[i]!=1)
                break;
            if(map[i]==2)
                printf("%c is the counterfeit coin and it is heavy.\n",i+65);
            else
                printf("%c is the counterfeit coin and it is light.\n",i+65);
    }
return 0;
}