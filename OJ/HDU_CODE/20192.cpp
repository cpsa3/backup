////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-02-03 21:50:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:156KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
    int v;
    node *next;
};
int main()
{
    int n,m;
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
		if(n==0&&m==0) break;
        node *root=(node *)malloc(sizeof(node));
        root->next=NULL;
        node *p=root;
        for(i=0;i<n;i++)
        {
            node *k=(node *)malloc(sizeof(node));
            scanf("%d",&k->v);
            k->next=NULL;
            p->next=k;
            p=p->next;
        }
        p=root;
        while(p->next!=NULL)
        {
            if(p->next->v>=m)
            {
                node *k=(node *)malloc(sizeof(node));
                k->v=m;
                k->next=p->next;
                p->next=k;
                break;
            }
            p=p->next;
        }
        p=root;
        printf("%d",p->next->v);
        p=p->next;
        while(p->next)
        {
            printf(" %d",p->next->v);
            p=p->next;
        }
        printf("\n");
    }
    return 0;
}