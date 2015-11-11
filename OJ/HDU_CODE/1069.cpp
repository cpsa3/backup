////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-11 15:04:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct px
{
    int a,b,h;
};
px stu[101];
int r;
int bfs()
{
    px start,temp,t;
    vector<px>V;
    int max=0,i,j;
    start.a=start.b=99999999;
    start.h=0;
    V.push_back(start);
    while(!V.empty())
    {
        temp=V[0];
        for(i=0;i<r;i++)
        {
            if(stu[i].a<temp.a&&stu[i].b<temp.b)
            {
                t.a=stu[i].a;t.b=stu[i].b;t.h=temp.h+stu[i].h;
                int flag=0;
                for(j=1;j<V.size();j++)
                {
                    if(V[j].a<=t.a&&V[j].b<=t.b&&V[j].h<=t.h)
                    {V.erase(&V[j]);j--;continue;}
                    if(V[j].a>=t.a&&V[j].b>=t.b&&V[j].h>=t.h)
                    {flag=1;break;}
                }
                if(!flag)
					V.push_back(t);
            }
        }
        if(temp.h>max)
            max=temp.h;
        V.erase(&V[0]);
    }
	return max;
}
main ()
{
    int N,a[3],i,cas=1,j;
	px t;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0) break;
        r=0;
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            sort(a,a+3);
			t.h=a[0];t.a=a[1];t.b=a[2];
			for(j=0;j<r;j++)
				if(stu[j].a==t.a&&stu[j].b==t.b&&stu[j].h==t.h)
					break;
				if(j==r) {stu[r]=t;r++;}
				
				t.h=a[1];t.a=a[0];t.b=a[2];
				for(j=0;j<r;j++)
					if(stu[j].a==t.a&&stu[j].b==t.b&&stu[j].h==t.h)
						break;
					if(j==r) {stu[r]=t;r++;}
					
					t.h=a[2];t.a=a[0];t.b=a[1];
					for(j=0;j<r;j++)
						if(stu[j].a==t.a&&stu[j].b==t.b&&stu[j].h==t.h)
							break;
						if(j==r) {stu[r]=t;r++;}
						//stu[r].h=a[1];stu[r].a=a[0];stu[r].b=a[2];r++;
						//stu[r].h=a[2];stu[r].a=a[0];stu[r].b=a[1];r++;
        }
        printf("Case %d: maximum height = %d\n",cas++,bfs());
    }
	return 0;
}