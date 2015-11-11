////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-05 00:21:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include<iostream>
#include <algorithm>
using namespace std;
#define MOD 10007

struct Matrix 
{
    int numbers[4][4];
    Matrix(int x = 0, int y = 0)
    {
        memset(numbers, 0, 4 * 4 * sizeof(int));
        numbers[0][0] = numbers[0][1] = 1;
        numbers[1][1] = x * x % MOD; numbers[1][2] = y * y % MOD; numbers[1][3] = 2 * x * y % MOD;
        numbers[2][1] = 1;
        numbers[3][1] = x; numbers[3][3] = y;
    }
    Matrix(bool flag) 
    {
        memset(numbers, 0, 4 * 4 * sizeof(int));
        numbers[0][0] = 1;
        numbers[1][1] = 1;
        numbers[2][2] = 1;
        numbers[3][3] = 1;
    }
};

Matrix operator * (const Matrix& lh, const Matrix& rh) 
{
    Matrix temp;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) 
        {
            int sum = 0;
            for (int k = 0; k < 4; ++k)
                sum = (sum + lh.numbers[i][k] * rh.numbers[k][j]) % MOD;
            temp.numbers[i][j] = sum;
        }
        return temp;
}

int main() 
{
    int n, x, y;
    while (scanf("%u%u%u", &n, &x, &y) != EOF)
    {
        Matrix mat(x % MOD, y % MOD), res(true);
        for (; n > 0; n >>= 1) 
        {
            if (n & 1)
                res = mat * res;
            mat = mat * mat;
        }
        int sum = 0;
        for (int i = 0; i < 4; ++i)
            sum = (sum + res.numbers[0][i]) % MOD;
        printf("%u\n", sum);
    }
    return 0;
}



