////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-21 16:45:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
main ()
{
	char a[5005];
	int t,i;
	//string x,y,tx,ty;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		string x,y,tx,ty;
		gets(a);
		while(strcmp(a,"END"))
		{
			if(strlen(a)>0)
			{
				for(i=0;i<strlen(a);i++)
					if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n') x+=a[i];
					else tx+=a[i];
			}
			else tx+='\n';
			gets(a);
		}
		gets(a);
		while(strcmp(a,"END"))
		{
			if(strlen(a)>0)
			{
				for(i=0;i<strlen(a);i++)
					if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n') y+=a[i];
					else ty+=a[i];
			}
			else ty+='\n';
			gets(a);
		}
		if(tx==ty&&x==y) printf("Accepted\n");
		else if(x==y&&tx!=ty) printf("Presentation Error\n");
		else if(x!=y) printf("Wrong Answer\n");
	}
return 0;
}