////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-09-29 10:51:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:3296KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<char>v;
char a[20],b[20];
int n,flag=0;
void fit(int c[30])//�ж������ջ˳���������˳���ǲ���һ��
{
    int i,s,j;
    char w[20];
    for(i=1,s=0,j=0;i<=2*n;i++)
    {
        if(c[i]==1)
        {v.push_back(a[s]);s++;}//��vectorģ��𳵳���˳��
        else
        {w[j]=v.back();j++;v.pop_back();}
    }
 
    for(i=0;i<n;i++)
        if(w[i]!=b[i])
            break;
        if(i==n)
        flag=1;
return;
}
 
void dfs(int c[30],int p,int in,int out)//c[30]������¼����ջ��˳��p����¼�Ѿ���¼�Ķ���������in��¼��ջ�Ĵ�����out��¼��ջ��˳��
{
    int j;
    if(flag)
        return;
    if(p==2*n)//���p�����ܴ��������ж��Ƿ����
    {
        fit(c);
        if(flag)
        {
            printf("Yes.\n");
            for(j=1;j<=p;j++)
            	c[j]==1?printf("in\n"):printf("out\n");
        }
        return;
    }
    if(in>out)//ֻ��in>out������£���ջδ�գ�ʱ���ܳ�ջ
    {
        c[p+1]=-1;
        dfs(c,p+1,in,out+1);
    }
    c[p+1]=1;//ÿ�ζ��ܽ�ջ
    dfs(c,p+1,in+1,out);
return;
}
 
 
 
main ()
{
    
    while(scanf("%d%s%s",&n,a,b)!=EOF)
    {
        flag=0;
        int c[30]={0};
        dfs(c,0,0,0);
        if(!flag)
            printf("No.\n");
            printf("FINISH\n");
    }
return 0;
}
