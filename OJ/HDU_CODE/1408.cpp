////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
  d=VUL/D; //�������ˮ�ε���Ŀ
  if(d<VUL/D) d++; //������һ�β���һ��,������.
  for(j=1;VUL>0;j++) VUL -= j*D; //���ͣ�Ĵ���,���е���j-1��,����ͣ��j-2��.
  printf("%d\n",j-2+d); //����ʱ��Ϊֹͣ����(j-2)����ˮ����Ŀd.
 }
 return 0;
} 