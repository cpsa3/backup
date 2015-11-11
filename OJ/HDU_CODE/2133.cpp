////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 01:22:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*自己的AC代码，纯模拟*/
/*15ms*/ 
#include <iostream>
int month1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};//闰年
int month2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//非闰年
char date[8][20]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int y,m,d;
bool judge(int n)//判断是否是闰年
{
	if((n%4==0)&&(n%100)||(n%400==0))
		return true;
	return false;
}
bool Illegal()//无语，一定要注意这里
{
	//注意这部分，不然WA
	//---------------------//
	if(m==0)
		return true;
	if(d==0)
		return true;
	//---------------------//
	if(judge(y)&&d>month1[m])
			return true;
	if(!judge(y)&&d>month2[m])
			return true;
return false;
}
int cha()//计算相差天数
{
	int ans=0,i;
	if(y==2007)
	{
		if(m>11)
			return 13+d;
		else if(m<11)
		{
			for(i=m;i<11;i++)
				ans+=month2[i];
			ans+=17-d;
			return -ans;
		}
		else
		return d-17;
	}
	else if(y>2007)
	{
		for(i=2007;i<y;i++)
		{
			if(judge(i))
				ans+=366;
			else
				ans+=365;
		}
		for(i=1;i<m;i++)
		{
			if(judge(y))
			ans+=month1[i];
			else
				ans+=month2[i];
		}
		return ans+d-321;
	}
	else
	{
		for(i=y;i<2007;i++)
		{
			if(judge(i))
				ans+=366;
			else
				ans+=365;
		}
		for(i=1;i<m;i++)
		{
			if(judge(y))
			ans-=month1[i];
			else
			ans-=month2[i];
		}
		return -(ans+321-d);//原本这里忘记取反了WA一次
	}
}
void get_ans(int n)
{
	n=n%7;
	if(n<0)
		n+=7;
	printf("%s\n",date[n]);
}
int main()
{
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		if(Illegal())
		{printf("illegal\n");continue;}
		//printf("%d\n",cha());
		get_ans(cha()); 	
	}
return 0;
}