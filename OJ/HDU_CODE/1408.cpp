////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-09-15 22:46:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
 double VUL,D;
 int d,j;
 while(scanf("%lf %lf",&VUL,&D)==2)
 {
  d=VUL/D; //算出完整水滴的数目
  if(d<VUL/D) d++; //如果最后一滴不足一滴,做修正.
  for(j=1;VUL>0;j++) VUL -= j*D; //算出停的次数,其中滴了j-1次,就是停了j-2次.
  printf("%d\n",j-2+d); //所用时间为停止次数(j-2)加上水滴数目d.
 }
 return 0;
} 