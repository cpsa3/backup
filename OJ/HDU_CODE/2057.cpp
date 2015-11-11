////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-02 19:23:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
__int64 f(char w)
{
	if(w>='A'&&w<='F')
		return w-55;
	else 
		return w-'0';
}
char f1(__int64 w)
{
	if(w<=9)
		return w+'0';
	else
		return w+55;
}
__int64 change1(char v[20],int n)
{
	__int64 i,s=0,flag=0;
	if(v[0]=='+')
		flag=0;
	else if(v[0]=='-')
		flag=1;
	else
		s=s*16+f(v[0]);
	for(i=1;i<=n;i++)
		s=s*16+f(v[i]);
	if(flag==1)
		return -s;
	else
		return s;
}
void change2(__int64 w)
{
	__int64 a[30],i,k;
	if(w<0)
	{printf("-");w=-w;}
	if(w==0)
	{printf("0\n");return;}
	for(i=1;w;i++)
	{
		a[i]=w%16;
		w/=16;
	}
	for(k=i-1;k>=1;k--)
		printf("%c",f1(a[k]));
	printf("\n");
}
main ()
{
	char a[20],b[20];
	while(scanf("%s%s",a,b)!=EOF)
	{
		__int64 A=0,B=0;
		A=change1(a,strlen(a)-1);
		B=change1(b,strlen(b)-1);
		//printf("%d\n%d\n",A,B);
		change2(A+B);
	}
return 0;
}