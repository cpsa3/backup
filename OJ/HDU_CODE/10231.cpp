////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-18 22:04:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1023
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define MAX 100
#define BASE 10000
void multiply(int a[],int Max,int b) //�����˷�,ע������Ĵ���
{
	
    int i,array=0;
    for (i = Max-1; i >= 0; i--)   
    {
        array += b * a[i];
        a[i] = array % BASE; // ����ÿһλ��Ŵ�������λ����
        array /= BASE;   
    }
}


void divide(int a[], int Max, int b) //ģ���������
{
    int i, div = 0;
    for (i = 0; i < Max; i++)   
    {
        div = div * BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}

int main()

{
	
    int a[101][MAX],i, n;
    memset(a[1],0,MAX*sizeof(int));
    for (i=2, a[1][MAX-1] = 1; i < 101; i++) // �������Ŵ�����λ
    {
		memcpy(a[i], a[i-1], MAX * sizeof(int));      //h[i] = h[i-1]; 
        multiply(a[i], MAX, 4 * i - 2);               //h[i] *= (4*i-2);
        divide(a[i], MAX, i + 1);                  //h[i] /= ��i+1��;
    }
    while (cin >> n)   
    {
        for (i = 0; i < MAX && a[n][i] == 0; i++); //ȥ������ǰΪ0�����֡�
        cout << a[n][i++];             //�����һ����0��
        for (; i < MAX; i++)   
        {
			printf("%04d",a[n][i]);       //��������������ÿλ������4λ����!(32767)
		}
        cout << endl;
    }
    return 0;
}


