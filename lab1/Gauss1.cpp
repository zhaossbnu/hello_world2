#include<stdio.h>
#include<stdlib.h>

const int N = 10;
double a[N][N] =
{
    {4, 2, -3, -1, 2, 1, 0, 0, 0, 0},
    {8, 6, -5, -3, 6, 5, 0, 1, 0, 0},
    {4, 2, -2, -1, 3, 2, -1, 0, 3, 1},
    {0, -2, 1, 5, -1, 3, -1, 1, 9, 4},
    {-4, 2, 6, -1, 6, 7, -3, 3, 2, 3},
    {8, 6, -8, 5, 7, 17, 2, 6, -3, 5},
    {0, 2, -1, 3, -4, 2, 5, 3, 0, 1},
    {16, 10, -11, -9, 17, 34, 2, -1, 2, 2},
    {4, 6, 2, -7, 13, 9, 2, 0, 12, 4},
    {0, 0, -1, 8, -3, -24, -8, 6, 3, -1}
};
double b[N] = {5, 12, 3, 2, 3, 46, 13, 38, 19, -21};
bool Gauss(double a[N][N], double b[N], double x[N])
{
    for(int k = 0; k < N - 1; k ++)
    {
        //�����������
        for(int i = k + 1; i <= N - 1; i ++)
        {
            if(a[k][k] == 0)
            {
                printf("Divided by zero!");
                return false;
            }
            double l = a[i][k] / a[k][k];
            for(int j = k + 1; j <= N - 1; j++)
            {
                a[i][j] = a[i][j] - l * a[k][j];
            }
            b[i] = b[i] - l * b[k];
        }
    }
    //�ش����
    x[N - 1] =  b[N - 1] / a[N - 1][N - 1];
    for(int i = N - 2; i >= 0; i --)
    {
        double sum = 0;
        for(int j = i + 1; j <= N - 1; j ++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum ) / a[i][i];
    }
    return true;
}

int main(void)
{
    double x[N] = {0};
    if(Gauss(a, b, x))
    {
        //����������������
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                printf("      ");
            }
            for(int j = i ; j < N; j ++)
            {
                printf("%6.2lf", a[i][j]);
            }
            printf("%6.2lf\n", b[i]);

        }
        //�����
        for(int i = 0; i < N; i ++)
        {
            printf("%10.6lf\n", x[i]);
        }
    }

    return 0;
}
