////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 00:39:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>   

#include <cmath>   

 using namespace std;   

 __int64 myPow ( int n , int e )   

 {   

     __int64 mlt = 1;   

     for ( int i = 1; i <= e ; ++ i )   

    {   

           mlt *= n;    

     }    

     return mlt;   

}   

int main ()   

{   

     int N;   

     int T;   

     cin >> T;   

     while ( T -- )   

     {   

             cin >> N ;   

             printf("%I64d\n",myPow ( 3, N - 1 ) + 1 );   

     }   

     return 0;    

 } 
