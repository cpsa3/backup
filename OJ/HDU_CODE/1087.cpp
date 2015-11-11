////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 19:58:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int N = 1002;
int str[N], cnt[N];
int main()
{
    int n;
    int i, j, result;
    while(cin>>n && n)
    {
        for(i = 0; i < n; i++)
            scanf("%d", str + i);
        result = cnt[0] = str[0];
        for(i = 1; i < n; i++)
        {
            cnt[i] = str[i];
            for(j = 0; j < i; j++)
                if(str[j] < str[i] && cnt[j] + str[i] > cnt[i])
                    cnt[i] = cnt[j] + str[i];
            if(result < cnt[i])
                result = cnt[i];
        }
        cout<<result<<endl;
    }
    return 0;
}