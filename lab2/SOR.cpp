#include<iostream>
#include<math.h>
using namespace std;
const int N = 10;
//最大迭代次数
const int max_iteration = 1000000;
double a[N][N] =
{
    {4, -1, 0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 4, -1, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, 4, -1, 0, 0, 0, 0, 0, 0},
    {0, 0, -1, 4, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, -1, 4, -1, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, 4, -1, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 4, -1, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 4, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 4, -1},
    {0, 0, 0, 0, 0, 0, 0, 0, -1, 4}
};
double b[N] = {7, 5, -13, 2, 6, -12, 14, -4, 5, -5};
bool SOR(double a[N][N], double b[N], double x[N], double e, double w)
{
    for(int k = 1; k <= max_iteration; k ++)
    {
        double R = 0;
        for(int i = 0; i < N; i ++)
        {
            // 迭代
            double sum = 0;
            for(int j = 0; j < N; j ++)
            {
                sum += a[i][j] * x[j];
            }
            double R1 = w * (b[i] - sum) / a[i][i];
            if(fabs(R1) > fabs(R))
            {
                R = R1;
            }
            x[i] += R1;
            // 判断是否发散
            if(_isnan(x[i])!=0)
            {
                cout<<"算法不收敛！"<<endl;
                return false;
            }
        }
        // 判断是否达到精度
        if(fabs(R) <= e)
        {
            cout<<"迭代次数："<<k<<endl;
            return true;
        }
    }
    cout<<"迭代次数："<<max_iteration<<endl;
    return true;
}
int main(void)
{
    double x[N] = {0};

    if(SOR(a, b, x, 1e-5, 0.8))
    {
        //输出解
        for(int i = 0; i < N; i ++)
        {
            cout<<x[i]<<endl;
        }
    }
    return 0;
}