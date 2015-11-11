////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-27 22:27:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h> 
using namespace std;
main ()
{
	char a[500];
	char b[11]={'0','1','2','3','4','5','6','7','8','9'};
	double c[500];
	char d[500];
	char A[2]={'0'};
	int m,i,j,k,s,t,x,y;
	while(gets(a))
	{

		if(!strcmp(a,A))
			break;
		k=0;
		s=0;
		t=0;
		m=strlen(a);
		for(i=0;i<m;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				j=0;
				while(a[i]-b[j])
					j++;
				s=s*10+j;
			}
			if(a[i]==' '&&(a[i-1]>='0'&&a[i-1]<='9'))
			{c[++k]=s;s=0;}
			if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
				d[++t]=a[i];
			if(i==m-1)
			{c[++k]=s;s=0;}
		}
		for(i=1;i<=t;i++)
		{
			if(d[i]=='*')
			{
				c[i]=c[i]*c[i+1];
				for(x=i;x<t;x++)
					d[x]=d[x+1];
				t--;
				for(y=i+1;y<k;y++)
					c[y]=c[y+1];
				k--;
				i--;
				continue;
			}
			if(d[i]=='/')
			{
				c[i]=c[i]/c[i+1]*1.0;
				for(x=i;x<t;x++)
					d[x]=d[x+1];
				t--;
				for(y=i+1;y<k;y++)
					c[y]=c[y+1];
				k--;
				i--;
				continue;
			}
		}
		for(i=1;i<=t;)
		{
			if(d[i]=='+')
			{
				c[i]=c[i]+c[i+1];
				for(x=i;x<t;x++)
					d[x]=d[x+1];
				t--;
				for(y=i+1;y<k;y++)
					c[y]=c[y+1];
				k--;
				continue;
			}
			if(d[i]=='-')
			{
				c[i]=c[i]-c[i+1];
				for(x=i;x<t;x++)
					d[x]=d[x+1];
				t--;
				for(y=i+1;y<k;y++)
					c[y]=c[y+1];
				k--;
				continue;
			}
		}
		printf("%.2lf\n",c[1]);
	}
return 0;
}