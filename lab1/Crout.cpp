#include<stdio.h>
#include<stdlib.h>

const int N = 10;
double a[N] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
double c[N - 1] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
double d[N] = {0, -1, -1, -1, -1, -1, -1, -1, -1, -1};
double b[N] = {7, 5, -13, 2, 6, -12, 14, -4, 5, -5};
bool Crout(double a[N],double c[N], double d[N], double b[N], double x[N])
{
    //分解矩阵
    for(int i = 0; i <= N - 2; i ++)
    {
        c[i] = c[i] / a[i];
        a[i + 1] = a[i + 1] - d[i + 1] * c[i];
    }
    //分析知 实际上并不需要中间变量y[N]
    //计算逻辑上的y[N]
    x[0] = b[0] / a[0];
    for(int i = 1; i <= N - 1; i ++)
    {
        x[i] = (b[i] - d[i] * x[i - 1]) / a[i];
    }
    //求出x[N];
    for(int i = N - 2; i >=0; i --)
    {
        x[i] = x[i] - c[i] * x[i + 1];
    }
    return true;
}

int main(void)
{
    //A = TM
    double x[N] = {0};
    if(Crout(a, c, d, b, x))
    {
        //打印T
        printf("%6.2lf\n", a[0]);
        for(int i = 1; i <= N-1; i++)
        {
            for(int k = 0; k <= i - 2; k ++)
            {
                printf("      ");
            }
            printf("%6.2lf%6.2lf\n", d[i], a[i]);
        }
        //打印M
        for(int i = 0; i <= N-2; i++)
        {
            for(int k = 0; k <= i - 1; k ++)
            {
                printf("      ");
            }
            printf("  1.00%6.2lf\n", a[i]);
        }
        for(int k = 0; k <= N - 2; k ++)
        {
            printf("      ");
        }
        printf("  1.00\n");
        //输出解
        for(int i = 0; i < N; i ++)
        {
            printf("%10.6lf\n", x[i]);
        }
    }

    return 0;
}
