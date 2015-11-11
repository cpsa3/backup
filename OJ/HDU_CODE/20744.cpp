////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2013-06-08 00:33:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1256KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int	i, j, n, k;
	char	a, b, c;
	char	ch[1000][1000];
	int t = 0;
	while ( cin >> n >> a >> b )
	{
		if(t != 0){
			cout<<endl;
		}
		t ++;
		for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		ch[i][j]='\0';
		if((n-1)%4 != 0){
			c=a;a=b;b=c;
		}
		
		if ( n == 1 ){
			cout << a <<endl;
			continue;
		}
			
		for ( i = 0; i < n / 2 + 1; i++ )
		{
			if ( i == 0 )
			{
				for ( k = 0; k < n; k++ )
				{
					ch[0][k]	= a;
					ch[n - 1][k]	= a;
				}
			}else{
				if ( i % 2 == 0 )
					c = a;
				else
					c = b;
				for ( j = 0; j < n; j++ )

					ch[i][j] = c;
				for ( j = 0; j < i; j++ )
				{
					if ( j % 2 == 0 )
						c = a;
					else
						c = b;
					ch[i][j] = ch[i][n - j - 1] = c;
				}
				for ( j = 0; j < n; j++ )
					ch[n - i - 1][j] = ch[i][j];
			}

			ch[0][0]		= ' ';
			ch[0][n - 1]		= ' ';
			ch[n - 1][0]		= ' ';
			ch[n - 1][n - 1]	= ' ';
			cout << ch[i] << endl;
		}
		for ( i = n / 2 + 1; i < n; i++ )
			cout << ch[i] << endl;
	}
	return(0);
}


