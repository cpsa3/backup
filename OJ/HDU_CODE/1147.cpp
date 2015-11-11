////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-19 11:05:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1147
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*线段相交判断*/
/*AC代码：547ms*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;
struct Point
{
	double x,y;
}; 
struct Line
{
	Point s,e;
	int id; 
};
vector<Line>V;
vector<Line>::iterator pos;
int Cmp(double x)//判断符号
{
	if(fabs(x)<eps)
		return 0;
	return x>0?1:-1; 
}
double Cross(Point s,Point e,Point o)////叉乘
{
	return (s.x-o.x)*(e.y-o.y)-(s.y-o.y)*(e.x-o.x);
}
bool Judge(Line l1,Line l2)//判断两线段是否相交
{
	if(Cmp(Cross(l1.s,l1.e,l2.s))*Cmp(Cross(l1.s,l1.e,l2.e))<eps&&Cmp(Cross(l2.s,l2.e,l1.s))*Cmp(Cross(l2.s,l2.e,l1.e))<eps)
		return true;
	return false;
}
int main()
{
	int N,i,j;
	Line l;
	while(scanf("%d",&N),N)
	{
		V.clear();
		for(i=1;i<=N;i++)
		{
			scanf("%lf%lf%lf%lf",&l.s.x,&l.s.y,&l.e.x,&l.e.y);
			l.id=i;
			for(pos=V.begin(),j=0;j<V.size()&&pos!=V.end();pos++,j++)
			{
				if(Judge(V[j],l))
				{V.erase(pos);pos--;j--;}//注意
			}
			V.push_back(l); 
		}
		printf("Top sticks:");
		for(i=0;i<V.size()-1;i++)
			printf(" %d,",V[i].id);
		printf(" %d.\n",V[i].id);
	}
return 0;
} 
