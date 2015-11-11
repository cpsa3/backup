////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-10 10:11:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1702
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>V;
queue<int>Q;
main ()
{
    int t,n,w,i,j;
    char a[10],b[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        scanf("%s",a);
        getchar();
        if(a[2]=='F')
        {
            while(!Q.empty())
                Q.pop();
            for(i=1;i<=n;i++)
            {
                gets(b);
                if(b[0]=='I')
                {
                    w=0;
                    for(j=3;j<strlen(b);j++)
                        w=w*10+b[j]-'0';
                    Q.push(w);
                }
                else
                {
                    if(!Q.empty())
                    {
                    printf("%d\n",Q.front());
                    Q.pop();
                    }
                    else
                        printf("None\n");
                }
            }
        }
        else
        {
            while(!V.empty())
                V.pop_back();
            for(i=1;i<=n;i++)
            {
                gets(b);
                if(b[0]=='I')
                {
                    w=0;
                    for(j=3;j<strlen(b);j++)
                        w=w*10+b[j]-'0';
                    V.push_back(w);
                }
                else    
                {
                    if(!V.empty())
                    {
                    printf("%d\n",V.back());
                    V.pop_back();
                    }
                    else
                        printf("None\n");

                }
            }            
        }
    }
return 0;
}