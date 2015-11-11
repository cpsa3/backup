////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 19:57:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3750
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
double ans;
double binary(int l,int r,int k)
{
    int mid;
    double w=0;
    if(l==r)
        return 1*k;
    mid=(l+r)/2;
    double a=(double)(1.0/(r-l+1));
    double b=(double)((mid-l)*1.0/(r-l+1));
    double c=(double)((r-mid)*1.0/(r-l+1));
    //printf("%.2lf %.2lf %.2lf\n",a,b,c);
    w+=a*k;
    if(b>0)
        w+=b*binary(l,mid-1,k+1);
    if(c>0)
        w+=c*binary(mid+1,r,k+1);
    return w;

}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        ans=binary(1,N,1);
        printf("%.2lf\n",ans);
    }
return 0;
}