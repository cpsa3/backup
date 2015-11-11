////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 19:10:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int f[5001]={0};
int main(){
  int max,t,i,j,a,b,cas;
  for(i=1;i<5001;i++)
  for(j=i;j<5001;j+=i)
  f[j]++;
  scanf("%d",&cas);
  while(cas--){
    scanf("%d %d",&a,&b);
    max=0;
    for(i=a;i<=b;i++){
      if(f[i]>max){max=f[i];t=i;}}
    printf("%d\n",t);}
  return 0;
}

