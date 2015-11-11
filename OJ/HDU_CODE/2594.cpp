////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-29 17:13:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2594
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:816KB
//////////////////System Comment End//////////////////
/*KMP*/
/*AC´úÂë£º15ms*/
#include <iostream>
#include <cstring>
#define MAXN 50005
#define min(a,b) (a<b?a:b)
using namespace std;
char s[2*MAXN];
char s1[MAXN],s2[MAXN];
int next[2*MAXN];
int len1,len2,len;
void get_next()
{
	int i=1,t;
	next[0]=-1;
	while(i<=len)
	{
		t=next[i-1];
		while((t+1)&&s[t+1]!=s[i])
			t=next[t];
		next[i]=t+1;
		i++;
	}
}
int main()
{
    int i;
	while(scanf("%s%s",s1+1,s2+1)!=EOF)
	{
	   len1=strlen(s1+1);
	   len2=strlen(s2+1);
	  // printf("%d %d \n",len1,len2);
	   for(i=1;i<=len1;i++)
		   s[i]=s1[i];
	   for(i=1;i<=len2;i++)
	   {
	       s[len1+i]=s2[i];
       }
	   s[len1+i]='\0';
	   len=len1+len2;
       get_next();
	   int ans=min(next[len],min(len1,len2));
	   if(ans==0)
		   printf("0\n");
	   else
	   {
		   for(i=1;i<=ans;i++)
			   printf("%c",s[i]);
		   printf(" %d\n",ans);
	   }
	}
return 0;
}