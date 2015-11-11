////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-24 23:35:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2333
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct px
{
    char type[30];
    char name[30];
    int p,q;
};
struct px stu[1001];
int N,B,high,low,sum,flag,vv[1001];
int cmp(const void *x,const void *y)
{
    if(strcmp(((struct px *)x)->type,((struct px *)y)->type))
        return strcmp(((struct px *)x)->type,((struct px *)y)->type);
    else if(((struct px *)y)->q!=((struct px *)x)->q)
        return ((struct px *)y)->q-((struct px *)x)->q;
    else
        return ((struct px *)x)->p-((struct px *)y)->p;
}
 
void dfs(int k,int qian,int mid)
{
    int i;
    if(qian>B)
        return; 
    if(k==sum)
    {
        flag=1;
        return;
    }
    int min=9999999,ww=0;
    for(i=vv[k]+1;i<=vv[k+1];i++)
    {
        if(stu[i].q>=mid&&stu[i].p<min)
        {min=stu[i].p;ww=1;}
        //if(!strcmp(stu[i].type,tp)&&stu[i].q>=mid)
            //dfs(i+1,k+1,stu[vv[k+1]].type,qian+stu[i].p,mid);
    }
    if(ww==0)
        return;
    dfs(k+1,qian+min,mid);
return;
}
 
main ()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&B);
        for(i=1;i<=N;i++)
            scanf("%s%s%d%d",stu[i].type,stu[i].name,&stu[i].p,&stu[i].q);
        qsort(stu+1,N,sizeof(stu[0]),cmp);
        high=stu[1].q;
        low=0;
        sum=1;
        vv[1]=1;
        vv[0]=0;
        char temp[30];
        strcpy(temp,stu[1].type);
        for(i=2;i<=N;i++)
        {
            if(strcmp(temp,stu[i].type))
            {
                if(stu[i].q<high)
                    high=stu[i].q;
                strcpy(temp,stu[i].type);
                sum++;
                vv[sum]=vv[sum-1]+1;
            }
            else
                vv[sum]++;
        }
        while(high!=low)
        {
            int mid=(high+low+1)/2;
            flag=0;
            dfs(0,0,mid);
            if(flag)
                //low=mid+1;
                low=mid;
            else
                high=mid-1;
        }
        printf("%d\n",low);
    }
return 0;
}
