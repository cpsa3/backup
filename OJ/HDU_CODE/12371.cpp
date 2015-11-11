////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2012-02-14 20:22:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////

/*
中缀表达式->后缀表达式：栈中的操作符从栈顶到栈底 严格递减
(即保证push到符号栈的符号必然比栈顶符号优先级高，否则pop)
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define MAXN 205
using namespace std;
struct OP
{
	char kind;
	int v;
	void Kind()
	{
		if(v<=2) kind='a';
		else kind='b';
	}
};
char s[MAXN];
double num[MAXN];
OP op[MAXN];
int Len,Ns,Os;
bool Isnum(char x)
{
	if(x>='0'&&x<='9')
		return true;
	return false;
}
int get_op(char x)
{
	if(x=='+') return 1;
	if(x=='-') return 2;
	if(x=='*') return 3;
	if(x=='/') return 4;
}
double get_num(int &pos)
{
	double res=0;
	while(pos<Len&&Isnum(s[pos]))
	{
		res=res*10+s[pos]-'0';
		pos++;
	}
	return res;
}
double cal(int o,double num1,double num2)
{
	if(o==1) return num1+num2;
	if(o==2) return num1-num2;
	if(o==3) return num1*num2;
	if(o==4) return num1/num2;
}
void Solve()
{
	int i;
	OP x;
	Len=strlen(s);
	Ns=Os=0;
	for(i=0;i<Len;i++)
	{
		if(s[i]==' ') continue;
		if(Isnum(s[i]))
		{
			num[Ns++]=get_num(i);
			i--;
		}
		else
		{
			x.v=get_op(s[i]);
			x.Kind();
			while(Os>0&&op[Os-1].kind>=x.kind)
			{
				//printf("*%d %d\n",op[Os-1].kind,x.kind);
				num[Ns-2]=cal(op[--Os].v,num[Ns-2],num[Ns-1]);
				Ns--;//Os--;
			}
			op[Os++]=x;
		}
	}
	while(Os>0)
	{
		num[Ns-2]=cal(op[--Os].v,num[Ns-2],num[Ns-1]);
		Ns--;//Os--;
	}
	printf("%.2lf\n",num[0]);
}
int main()
{
	while(gets(s))
	{
		if(!strcmp(s,"0"))
			break;
		Solve();
	}
return 0;
}
