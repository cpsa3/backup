////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-30 23:20:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1542
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:452KB
//////////////////System Comment End//////////////////
#include<iostream>
#include <algorithm>
using namespace std;
double x[201],y[201],s[101][4];
int xy[201][201];
int n,cas=0;
double sum;
int main()
{
    int i,j,k;
    while(cin>>n)
    {   
        if(n==0)
            break;
        cas++;
        k=0;
        sum=0.0;
        memset(xy,0,sizeof(xy));
        for(i=1;i<=n;i++)
        {
            cin>>s[i][0]>>s[i][1]>>s[i][2]>>s[i][3];
            x[k]=s[i][0];
            y[k]=s[i][1];
            k++;
            x[k]=s[i][2];
            y[k]=s[i][3];
            k++;
        }
        sort(x,x+2*n);
        sort(y,y+2*n);
        for(k=1;k<=n;k++)
        {
            int i1,i2,j1,j2;
            for(i1=0;i1<2*n;i1++)
            {
                if(x[i1]==s[k][0])
                    break;
            }
            for(i2=0;i2<2*n;i2++)
            {
                if(x[i2]==s[k][2])
                    break;
            }
            for(j1=0;j1<2*n;j1++)
            {
                if(y[j1]==s[k][1])
                    break;
            }
            for(j2=0;j2<2*n;j2++)
            {
                if(y[j2]==s[k][3])
                    break;
            }
            for(i=i1;i<i2;i++)
            {
                for(j=j1;j<j2;j++)
                {
                    xy[i][j]=1;
                }
            }
        }
        for(i=0;i<2*n;i++)
        {
            for(j=0;j<2*n;j++)
            {
                sum+=xy[i][j]*(x[i+1]-x[i])*(y[j+1]-y[j]);
            }
        }
        printf("Test case #%d\n",cas);
        printf("Total explored area: %.2f\n",sum);
        printf("\n");
    }
    return 0;
}
