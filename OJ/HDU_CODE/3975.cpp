////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-26 20:19:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3975
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define eps 1e-7
#define PI 3.1415926

struct P{
	double vx,vy;
}dia[4];

P get_P(double v,double rad){
	P p;
	p.vx = v*cos(rad);
	p.vy = v*sin(rad);
	return p;
}
bool isMul(double X21,double X31,double Vx21,
		   double Vx31,double Vy21,double Vy31){
	if( fabs(Vx21*Vy31-Vx31*Vy21)<eps && fabs(X31*Vy21-X21*Vy31)<eps )
		return true;
	return false;
}
bool isNot(double X21,double X31,double Vx21,
		   double Vx31,double Vy21,double Vy31){
	if( fabs(Vx21*Vy31-Vx31*Vy21)<eps || fabs(X31*Vy21-X21*Vy31)<eps )
		return true;
	else
		return false;
}

int main(){
	int T,cas=1;
	cin>>T;
	double x1,x2,x3;
	double v1,v2,v3;
	double a,b,c,minTime;
	while(T --){
		cin>>x1>>x2>>x3;
		cin>>v1>>v2>>v3;
		cin>>a>>b>>c;
		dia[1] = get_P(v1,a);
		dia[2] = get_P(v2,b);
		dia[3] = get_P(v3,c);
		minTime = dia[1].vy;
		if(minTime > dia[2].vy)
			minTime = dia[2].vy;
		if(minTime > dia[3].vy)
			minTime = dia[3].vy;
		minTime = minTime / 10 * 2;

		double X21 = x2-x1;
		double X31 = x3-x1;
		double Vx21 = dia[2].vx-dia[1].vx;
		double Vx31 = dia[3].vx-dia[1].vx;
		double Vy21 = dia[2].vy-dia[1].vy;
		double Vy31 = dia[3].vy-dia[1].vy;
		double Vy13 = -Vy31;
		//printf("%.4lf\n",X31*Vy21-X21*Vy31);
		//printf("%.4lf\n",Vx21*Vy31-Vx31*Vy21);
		//printf("%.4lf %.4lf %.4lf\n",dia[1].vy,dia[2].vy,dia[3].vy);
		printf("Case #%d: ",cas ++);

		double t1 = (X31*Vy21-X21*Vy31)/(Vx21*Vy31-Vx31*Vy21) ;
		//double t2 = (X31*Vy21-X21*Vy13)/(Vx21*Vy13-Vx31*Vy21) ;
		//printf("%.4lf %.4lf\n",t1,t2);
		if(dia[1].vy==0 || dia[2].vy ==0 || dia[3].vy == 0 ){
			printf("-1\n");
		}

		else if( isMul(X21,X31,Vx21,Vx31,Vy21,Vy31)) {
			printf("Multiply answer\n");
		}
		else if( isNot(X21,X31,Vx21,Vx31,Vy21,Vy31) ) {
			printf("-1\n");
		}else if( t1 > 0 && t1 <= minTime){
				printf("%.4lf\n",t1);
		}
		else
        {
			printf("-1\n");
		}	
	}return 0;
}
/*
1 1 2
1.414 2.236 30162
0.7853 0.462 0.3215
*/