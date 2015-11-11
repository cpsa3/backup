////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-21 11:44:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1053
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*Huffman��*/
/*����С���ȶ��н��д洢����*/
/*AC���룺485ms*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
class cmp//���������
{
public:
	bool operator()(int s1,int s2)
	{return s1>s2;}//ע�����
};
char s[500];
int c[200];
priority_queue<int,vector<int>,cmp>Q;
int main()
{
	int i,a,b;
	while(gets(s))
	{
		if(!strcmp(s,"END")) break;
		while(!Q.empty()) Q.pop();
		memset(c,0,sizeof(c));
		int len=strlen(s);
		for(i=0;i<len;i++)
			c[s[i]]++;
		for(i=0;i<200;i++)
		{
			if(c[i])
				Q.push(c[i]),c[i]=0;
		}
		//���Ĵ���
		int sum=0;
		while(Q.size()>1)
		{
			a=Q.top();Q.pop();
			b=Q.top();Q.pop();
			sum+=a+b;
			Q.push(a+b);
		}
		if(!sum)
			sum=len;
		printf("%d %d %.1lf\n",8*len,sum,double(double(8*len)/sum)); 
	}
return 0;
}
