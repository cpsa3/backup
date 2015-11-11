////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-02 16:05:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,x[101],y[101],i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		double s=0;
		for(i=1;i<=n-1;i++)
			s+=x[i]*y[i+1]-x[i+1]*y[i];
		s+=x[n]*y[1]-x[1]*y[n];
		printf("%.1lf\n",s/2);
	}
	return 0;
}
//多边形面积S=0.5*[(x0*y1-x1*y0)+(x1*y2-x2*y1)+...+(xn*y0-x0*yn)];
//其中点(x0, y0), (x1, y1), ... , (xn, yn)为多边形上按逆时针顺序的顶点。