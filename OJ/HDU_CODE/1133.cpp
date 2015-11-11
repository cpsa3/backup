////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-19 16:37:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
#define MAX 100
#define BASE 10000
void multiply(int a[],int Max,int b)  //������С��
{
    int i,array=0;
    for (i=Max-1; i>=0; i--)   
    {
        array+=b*a[i];
        a[i] = array%BASE;
        array /= BASE;   
    }
}
 
void divide(int a[], int Max, int b)  //������С��
{
    int i,div=0;
    for (i=0;i<Max; i++)   
    {
        div = div*BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}
int fact[205][MAX];
void setFact ()
{
     fact[0][MAX-1] = fact[1][MAX-1] = 1;
     for ( int i = 2; i <= 200; ++ i )
     {
           memcpy ( fact[i] , fact[i-1] , MAX * sizeof ( int ) );
           multiply ( fact[i] , MAX , i ); 
     } 
}
void outPut ( int ctl[MAX] )
{
     int i = 0;
     while ( i < MAX && ctl[i] == 0 )
     {
             i ++ ; //ȥǰ��0 
     }
     printf ( "%d", ctl[i++] );             
     while ( i < MAX )   
     {
             printf ( "%04d", ctl[i++] );   
     } 
     putchar ( '\n' ); 
}
int res[MAX];
int main ()
{
     int M,N;
     int ca = 1;
     setFact();
     while ( cin >> M >> N , M + N )
     {
             printf ( "Test #%d:\n",ca++ );
             if ( N > M )
             {
                  puts ( "0" );
                  continue; 
             }
             memcpy ( res , fact[M+N] , MAX * sizeof ( int ) );      //�׳� ( m + n )!
             multiply ( res, MAX, M - N + 1 );                               //( m + n )! * ( m-n+1 )
             divide ( res, MAX, M + 1 );                                        //( m + n )! * ( m-n+1 )  / ( m+ 1 )         
             outPut ( res );
     }
     return 0;
}
