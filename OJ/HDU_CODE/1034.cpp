////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 12:40:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
 
int main() 
{
    int count;
    int pieces[500];
    int i;
    int times;
    int temp;
    
    while(scanf("%d", &count)!=EOF)
    {
        
        if(count==0)
            break;
        times = 0;
        for(i=0; i<count; i++)
        {
            scanf("%d", &pieces[i]);
        }
        while(true)
        {
            times++;
            temp = pieces[count-1];//????????????????
            for(i=count-1; i>0; i--)
            {
                pieces[i] = pieces[i]/2 + pieces[i-1]/2;
                pieces[i] += pieces[i] % 2;//????????????????
            }
            pieces[0] = pieces[0]/2 + temp/2;
            pieces[0] += pieces[0] % 2;
            for(i=0; i<count; i++)
            {
                if(pieces[i] != pieces[0])
                    break;
            }
            if(i == count)//??????????????????????
                break;
        }
        printf("%d %d\n", times, pieces[0]);
        
        
    }
    return 0;
}