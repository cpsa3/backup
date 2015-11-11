////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 17:24:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main ()
{
    char a[10000],b[10000],c[10000];      
    int m,n,t,k,p,h,i,j,ww,y;
	scanf("%d",&ww);
	for(y=1;y<=ww;y++)
	{
		printf("Case %d:\n",y);	
		scanf("%s%s",a,b);
		printf("%s + %s = ",a,b);
        for(i=0;i<10000;i++)
            c[i]='0';
        m=strlen(a);
        n=strlen(b);
        if(m>=n)
        {t=n;h=m;}
        else
        {t=m;h=n;}
        j=h;
        
        for(k=t,c[h+1]='\0';k>0;k--,m--,n--,h--)
        {
			
            p=(a[m-1]-'0')+(b[n-1]-'0');
            if((((c[h]-'0')+p)/10)==1)
                c[h-1]='1';
            c[h]=(((c[h]-'0')+p)%10)+'0';
            
            
        }
        if(m>n)
        {
            for(;h>0;h--)
            {    p=(a[h-1]-'0');
            if((((c[h]-'0')+p)/10)==1)
                c[h-1]='1';
            c[h]=(((c[h]-'0')+p)%10)+'0';
            }
			
        }
        else 
        {
            for(;h>0;h--)
            {
                p=(b[h-1]-'0');
                if((((c[h]-'0')+p)/10)==1)
					c[h-1]='1';
				c[h]=(((c[h]-'0')+p)%10)+'0';
            }
        }
        if(c[0]!='0')
            
        {for(i=0;i<=j;i++)
		printf("%c",c[i]);
        printf("\n");
        }
		else
		{
			for(i=1;i<=j;i++)
		printf("%c",c[i]);
		printf("\n");
		}    
		if(y!=ww)
			printf("\n");
		
    }     
    return 0;
}
