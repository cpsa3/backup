////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-08 10:32:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*Ä£ÄâÌâ*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;
int cas;
string s;
int main()
{
    int i,ps,pe;
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        int len=s.size();
        ps=pe=-1;
        for(i=0;i<len;i++)
        {
            if(s[i]==':'&&s[i+1]=='/')
            {ps=i+3;i+=2;continue;}
            if(ps!=-1&&(s[i]==':'||s[i]=='/'))
            {pe=i-1;break;}
        }
        if(pe==-1) pe=len-1;
		//cout<<pe<<endl;
		printf("Case #%d: ",cas++);
		cout<<s.substr(ps,pe-ps+1)<<endl;
    }
return 0;
}