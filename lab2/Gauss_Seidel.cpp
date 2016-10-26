#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
const int N = 8;
//最大迭代次数
const int max_iteration = 1000000;
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

bool Gauss_Seidel(double a[N][N], double b[N], double x[N], double e)
{
	double temp_x[N] = {0};
    for(int k = 1; k <= max_iteration; k ++)
    {
        double R = 0;
        for(int i = 0; i < N; i ++)
        {
            if(a[i][i] == 0)
            {
                cout<<"Divided by zero!"<<endl;
                return false;
            }
			//迭代计算解
            double sum = 0;
            for(int j = 0; j < N; j ++)
            {
				//不加自己
				if(j == i)
				{
					continue;
				}
                sum += a[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
            if(fabs(x[i] - temp_x[i]) > R)
            {
                R = fabs(x[i] - temp_x[i]);
            }
            // 判断是否发散
            if(_isnan(x[i])!=0)
            {
                cout<<"算法不收敛！"<<endl;
                return false;
            }
        }
		// 判断是否达到精度
        if(R <= e)
        {
            cout<<"迭代次数："<<k<<endl;
            return true;
        }
		//将上一次计算的结果放置到临时x中，为下次迭代做准备
        for(int i = 0; i < N; i ++)
        {
            temp_x[i] = x[i];
        }
    }
    cout<<"迭代次数："<<max_iteration<<endl;
    return true;
}

int main(void)
{
    //精度为1e-3
	double x1[N] = {0};
    if(Gauss_Seidel(a, b, x1, 1e-3))
    {
        //输出解
        for(int i = 0; i < N; i ++)
        {
            cout<<x1[i]<<endl;
        }
    }
    //精度为1e-4
	double x2[N] = {0};
    if(Gauss_Seidel(a, b, x2, 1e-4))
    {
        //输出解
        for(int i = 0; i < N; i ++)
        {
            cout<<x2[i]<<endl;
        }
    }
    //精度为1e-5
	double x3[N] = {0};
    if(Gauss_Seidel(a, b, x3, 1e-5))
    {
        //输出解
        for(int i = 0; i < N; i ++)
        {
            cout<<x3[i]<<endl;
        }
    }
    return 0;
}