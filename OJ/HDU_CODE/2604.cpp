////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-26 00:58:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2604
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*’“πÊ¬…+æÿ’Û≥À∑®*/
/*F[n]=F[n-1]+F[n-3]+F[n-4]*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
struct mat
{
    int v[6][6];
    void ini(int len)
    {
        int i;
        memset(v,0,sizeof(v));
        for(i=0;i<len;i++)
            v[i][i]=1;
    }
};
mat e,ans;
int MOD;
int L;
int F[5];
mat matrix_mul(mat p1,mat p2,int len)//æÿ’Ûœ‡≥À
{
	int i,j,k;
	mat t;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
	   {
			t.v[i][j]=0;
			for(k=0;k<len;k++)
				t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
		}
	 }
	return t;
}
mat matrix_mi(mat p1,int k,int len)//æÿ’Û«Û√›
{
    mat res;
    res.ini(len);
    while(k)
    {
        if(k&1) res=matrix_mul(res,p1,len);
        p1=matrix_mul(p1,p1,len);
        k>>=1;
    }
    return res;
}
int main()
{
    int i;
    memset(e.v,0,sizeof(e.v));
    e.v[0][0]=e.v[0][1]=e.v[1][2]=e.v[2][0]=e.v[2][3]=1;
    e.v[3][0]=e.v[3][4]=1;
    F[0]=1;F[1]=2;F[2]=4;
    F[3]=6;F[4]=9;
    while(scanf("%d%d",&L,&MOD)!=EOF)
    {
        if(L<=4)
        {printf("%d\n",F[L]%MOD);continue;}
        ans=matrix_mi(e,L-4,5);
        int res=0;
        for(i=0;i<5;i++)
        {
            res=res+F[i]*ans.v[4-i][0];
            res%=MOD;
        }
        printf("%d\n",res);
    }
return 0;
}