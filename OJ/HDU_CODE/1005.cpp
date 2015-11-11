////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 12:18:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
    int a,b,n,t,start,i,j,tag;
    int f[50];
    while(cin>>a>>b>>n&&a!=0)
    {
        f[0]=1; f[1]=1; start=0; tag=0;
        for(j=2;j<50;j++)
        {
            f[j]= (a*f[j-1]%7+b*f[j-2]%7)%7;
            for(i=j-1;i>0;i--)
            {                
                if(f[j]==f[i]&&f[j-1]==f[i-1])
                {
                    t=j-i;
                    start=i-1;
                    tag=1;
                    break;
                }
                if(tag) break;
            }
            
        }
        if(n-1<start) cout<<f[n-1]<<endl;
        else cout<<f[start+(n-1-start)%t]<<endl;
    }
    return 0;
}
