////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-21 16:52:30
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
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		string x,y,tx,ty;//每一次都进行了初始化
		gets(a);
		while(strcmp(a,"END"))
		{
			if(strlen(a)>0)
			{
				for(i=0;i<strlen(a);i++)
					if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n') x+=a[i];//按顺序存那些有效字符
					else tx+=a[i];//按顺序存那些无效字符
			}
			else tx+='a';//如过输入的字符长度为0，即直接输入了'\n',也按顺序储存起来
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
			else ty+='a';
			gets(a);
		}
		if(tx==ty&&x==y) printf("Accepted\n");
		else if(x==y&&tx!=ty) printf("Presentation Error\n");
		else if(x!=y) printf("Wrong Answer\n");
	}
return 0;
}