////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 18:48:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:859MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int main() 
{
    int n,i,j,k,m,t;     
    while(scanf("%d",&n)!=EOF)
    {
        m=0;
        t=0;
        for(i=1;i<=sqrt((double)n);i++)
        {                
            for(j=i;j<=sqrt((double)n);j++)    
            {
                for(k=j;k<=sqrt((double)n);k++)            
                    if(i*i+j*j+k*k==n)
                    {
                        printf("%d %d %d\n",i,j,k);
                        t=1;
                        break;
                    }    
                if(t)
                {
                    m=1;
                    break;    
                }                        
            }    
            if(m)
                break;                                    
        }                
    }  
    return 0;
} 

