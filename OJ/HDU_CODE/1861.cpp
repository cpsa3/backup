////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-17 20:48:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1861
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[101][2];
main ()
{
    int num,h,m,i,j,Sum=0,k=0;
    char w;
    for(i=0;i<=100;i++)
        f[i][0]=f[i][1]=-1;
    while(scanf("%d",&num)!=EOF)
    {
        if(num==-1)
            break;
        getchar();
        scanf("%c",&w);
        getchar();
        scanf("%d:%d",&h,&m);
        getchar();
        if(num==0)
        {
            
            //for(i=1;i<=100;i++)
            //{
            //    if(f[i][0]!=-1&&f[i][1]!=-1)
            //    {Sum+=f[i][1]-f[i][0];k++;}
            //}
            if(k==0)
                printf("0 0\n");
            else
            {
                if(Sum%k==0)
                    printf("%d %d\n",k,Sum/k);
                else
                    printf("%d %d\n",k,Sum/k+1);
            }
            for(i=0;i<=100;i++)
                f[i][0]=f[i][1]=-1;
            Sum=k=0;
        }
        else
        {
            if(w=='S')
                f[num][0]=h*60+m;
            else
                f[num][1]=h*60+m;
            if(f[num][0]!=-1&&f[num][1]!=-1)
            {
                k++;Sum+=f[num][1]-f[num][0];
                f[num][0]=f[num][1]=-1;
            }
        }
        
    }
    return 0;
}