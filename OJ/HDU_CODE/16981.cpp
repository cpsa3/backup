////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-25 19:57:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:4348KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

struct segment_tree
{
       int left,right,value,num;
}tree[300010];

void Bulid(int left,int right,int i)
{
     tree[i].left=left;
     tree[i].right=right;
     tree[i].num=right-left+1;
     
     if(left==right) { tree[i].value=1; return ; }
     else 
     {
       int mid=(left+right)/2;
       tree[i].value=0;
       Bulid(left,mid,2*i);
       Bulid(mid+1,right,2*i+1);
     }
}
void Update(int left,int right,int value,int i)
{
     if(left<=tree[i].left && right>=tree[i].right)
     { 
        tree[i].value=value;
        tree[i].num=(tree[i].right-tree[i].left+1)*value;
        return ;
     }
     else 
     {
       if(tree[i].value>0)
       {
         tree[2*i].value=tree[i].value;
         tree[2*i].num=(tree[2*i].right-tree[2*i].left+1)*tree[2*i].value;
         tree[2*i+1].value=tree[i].value;
         
         tree[2*i+1].num=(tree[2*i+1].right-tree[2*i+1].left+1)*tree[2*i+1].value;
         tree[2*i+1].value=tree[i].value;
         tree[i].value=0;
       }
       if(left<=tree[2*i].right) Update(left,right,value,2*i);
       if(right>=tree[2*i+1].left) Update(left,right,value,2*i+1);
       tree[i].num=tree[2*i].num+tree[2*i+1].num;
     }
}
int main()
{
   int T,n,Q,i,j,left,right,value;
   scanf("%d",&T);
   for(i=1;i<=T;i++)
   {
     scanf("%d%d",&n,&Q);
     Bulid(1,n,1);
     while(Q--)
     {
        scanf("%d%d%d",&left,&right,&value);
        Update(left,right,value,1);
     }
     printf("Case %d: The total value of the hook is %d.\n",i,tree[1].num);
   }
   return 0;
}


