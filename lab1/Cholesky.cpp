#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const int N = 8;
double a[N][N] =
{
    {4, 2, -4, 0, 2, 4, 0, 0},
    {2, 2, -1, -2, 1, 3, 2, 0},
    {-4, -1, 14, 1, -8, -3, 5, 6},
    {0, -2, 1, 6, -1, -4, -3, 3},
    {2, 1, -8, -1, 22, 4, -10, -3},
    {4, 3, -3, -4, 4, 11, 1, -4},
    {0, 2, 5, -3, -10, 1, 14, 2},
    {0, 0, 6, 3, -3, -4, 2, 19}
};
double b[N] = {0,-6,6,23,11,-22,-15,45};

bool Choleskey(double a[N][N], double b[N], double x[N])
{
    double sum = 0;
    double y[N] = {0};
    for(int k = 0; k <= N - 1; k ++)
    {
        //求对角线的元素
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
        //求非对角线元素
        for(int i = k + 1; i <= N - 1; i ++)
        {
            sum = 0;
            for(int m = 0; m <= k - 1; m ++)
            {
                sum += a[i][m] * a[k][m];
            }
            a[i][k] = (a[i][k] - sum) / a[k][k];
        }
        //解G y = b
        sum = 0;
        for(int m = 0; m <= k - 1; m ++)
        {
            sum += a[k][m] * y[m];
        }
        y[k] = (b[k] - sum) / a[k][k];
    }
    //解GT x = y
    x[N - 1] = y[N - 1] / a[N - 1][N - 1];
    for(int k = N -2; k >= 0; k --)
    {
        sum = 0;
        for(int m = k + 1; m <= N - 1; m ++)
        {
            sum += a[m][k] * x[m];
        }
        x[k] = (y[k] - sum) / a[k][k];
    }
    return true;
}

int main(void)
{
    double x[N] = {0};
    if(Choleskey(a, b, x))
    {
        //输出分解后的系数矩阵G
        for(int i = 0; i < N; i++)
        {
            for(int j = 0 ; j <= i; j ++)
            {
                printf("%6.2lf", a[i][j]);
            }
            printf("\n");
        }
        //输出解
        for(int i = 0; i < N; i ++)
        {
            printf("%10.6lf\n", x[i]);
        }
    }
    return 0;
}
