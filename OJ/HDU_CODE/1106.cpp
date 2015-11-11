////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-10 22:38:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include<stdlib.h> 
using namespace std;
char a[1010];
int b[1000];
int cmp(const void *a,const void *b)
{
return *((int *)a)-*((int *)b);

}


main ()
{
	int m,i,t,j;
	while(gets(a))
	{
		m=strlen(a);
		j=0;
		for(i=0,t=0;i<m;i++)
		{
			if(a[i]!='5')
				t=t*10+a[i]-'0';
			if(a[i]!='5'&&(i==m-1||a[i+1]=='5'))
			{
				b[++j]=t;
				t=0;
			}

		}
		qsort(b+1,j,sizeof(int),cmp);
		for(i=1;i<j;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[i]);
	}

return 0;
}