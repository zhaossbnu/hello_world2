#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdbool.h>
// M = 多项式最高次幂 + 1
// N为离散数据组数
const int M = 4, N = 11;
using namespace std;
double t[N] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
double y[N] = {0, 1.27, 2.16, 2.86, 3.44, 3.87, 4.15, 4.37, 4.51, 4.58, 4.02};

// 点乘
double dot_product(double a[N], double b[N])
{
    double result = 0;
    for(int i = 0 ; i < N; i ++)
    {
        result += a[i] * b[i];
    }
    return result;
}

// 解正定线性方程组 from 实验1
bool Choleskey(double a[M][M], double b[M], double x[M])
{
    double sum = 0;
    double y[M] = {0};
    for(int k = 0; k <= M - 1; k ++)
    {
        sum = 0;
        for(int m = 0; m <= k - 1; m ++)
        {
            sum += a[k][m] * a[k][m];
        }
        a[k][k] = sqrt(a[k][k] - sum);
        if(a[k][k] == 0)
        {
            printf("Divided by zero!");
            return false;
        }
        for(int i = k + 1; i <= M - 1; i ++)
        {
            sum = 0;
            for(int m = 0; m <= k - 1; m ++)
            {
                sum += a[i][m] * a[k][m];
            }
            a[i][k] = (a[i][k] - sum) / a[k][k];
        }
        sum = 0;
        for(int m = 0; m <= k - 1; m ++)
        {
            sum += a[k][m] * y[m];
        }
        y[k] = (b[k] - sum) / a[k][k];
    }
    x[M - 1] = y[M - 1] / a[M - 1][M - 1];
    for(int k = M -2; k >= 0; k --)
    {
        sum = 0;
        for(int m = k + 1; m <= M - 1; m ++)
        {
            sum += a[m][k] * x[m];
        }
        x[k] = (y[k] - sum) / a[k][k];
    }
    return true;
}

int main(void)
{
    //
    double phi[M][N] = {0};
    for(int i = 0; i < M; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            phi[i][j] = pow(t[j], i);
        }
    }
    // 系数矩阵
    double a[M][M] = {0};
    // 值向量
    double b[M] = {0};
    // 待求解系数向量
    double x[M] = {0};
    for(int i = 0; i < M; i ++)
    {
        for(int j = 0; j < M; j ++)
        {
            a[i][j] = dot_product(phi[i], phi[j]);
        }
        b[i] = dot_product(y, phi[i]);
    }
    Choleskey(a, b, x);
    // 输出表达式
    cout<<"y = "<<x[0];
    for(int i = 1 ; i < M; i ++)
    {
        if(x[i] < 0)
            cout<<" - "<<fabs(x[i])<<"x^"<<i;
        else
            cout<<" - "<<x[i]<<"x^"<<i;
    }
    cout<<endl;
    // 输出误差
    for(int i = 0 ; i < N; i ++)
    {
        double result = 0;
        for(int j = 0; j < M; j ++)
        {
            result += x[j] * pow(t[i], j);
        }
        cout<<"y"<<i<<" - y"<<i<<"' = "<<y[i] - result<<endl;
    }
    return 0;
}
