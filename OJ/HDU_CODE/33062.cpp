////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-05 00:29:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#define MOD 10007
struct mat
{
    __int64 v[4][4];
};
int N,X,Y;
mat e,ans;//转换矩阵
mat matrix_mul(mat p1,mat p2)//矩阵相乘
{
    int i,j,k;
    mat t;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            t.v[i][j]=0;
            for(k=0;k<4;k++)
                t.v[i][j]=(t.v[i][j]+p1.v[i][k]*p2.v[k][j])%MOD;
        }
        return t;
}
mat matrix_mi(mat p1,int k)//矩阵求幂
{
    if(k==1)
        return p1;
    if(k&1)
        return matrix_mul(matrix_mi(p1,k-1),p1);
    else
    {
        mat t=matrix_mi(p1,k>>1);
        return matrix_mul(t,t);
    }
}
int main()
{
	int i,j;
	while(scanf("%d%d%d",&N,&X,&Y)!=EOF)
	{
		memset(e.v,0,sizeof(e.v));
		//if(!N)
		//{printf("1\n");continue;}
		X=X%MOD;Y=Y%MOD;//不加会WA！！！！！！(错了很多次，注意)
		e.v[0][0]=1;//输入转换矩阵
		e.v[1][0]=1;
		e.v[1][1]=X*X%MOD;
		e.v[1][2]=X%MOD;
		e.v[1][3]=1;
		e.v[2][1]=2*X*Y%MOD;
		e.v[2][2]=Y%MOD;
		e.v[3][1]=Y*Y%MOD;
		ans=matrix_mi(e,N);
		/*
		for(i=0;i<4;i++)
		{
		for(j=0;j<4;j++)
		printf("%I64d ",ans.v[i][j]);
		printf("\n");
		}
		*/
		//__int64 ANS=(ans.v[0][0]+ans.v[1][0]+ans.v[2][0]+ans.v[3][0])%MOD;
		__int64 ANS=0;
		for(i=0;i<4;i++)
			ANS=(ANS+ans.v[i][0])%MOD;
		printf("%I64d\n",ANS);
	}
	return 0;
}