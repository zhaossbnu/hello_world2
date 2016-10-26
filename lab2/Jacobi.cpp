#include<iostream>
#include<math.h>
#include<float.h>
using namespace std;
const int N = 10;
//����������
const int max_iteration = 1000000;
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
bool Jacobi(double a[N][N], double b[N], double x[N], double e)
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
            // ����
            double sum = 0;
            for(int j = 0; j < N; j ++)
            {
                sum += a[i][j] * temp_x[j];
            }
            x[i] = temp_x[i] + (b[i] - sum) / a[i][i];
            if(fabs(x[i] - temp_x[i]) > R)
            {
                R = fabs(x[i] - temp_x[i]);
            }
            // �ж��Ƿ�ɢ
            if(_isnan(x[i])!=0)
            {
                cout<<"�㷨��������"<<endl;
                return false;
            }
        }
        //�ж��Ƿ�ﵽ����
        if(R <= e)
        {
            cout<<"����������"<<k<<endl;
            return true;
        }
        // ��¼���ε������
        for(int i = 0; i < N; i ++)
        {
            temp_x[i] = x[i];
        }
    }
    cout<<"����������"<<max_iteration<<endl;
    return true;
}

int main(void)
{
	//����Ϊ1e-3
    double x1[N] = {0};
    if(Jacobi(a, b, x1, 1e-3))
    {
        //�����
        for(int i = 0; i < N; i ++)
        {
            cout<<x1[i]<<endl;
        }
    }
    //����Ϊ1e-4
    double x2[N] = {0};
    if(Jacobi(a, b, x2, 1e-4))
    {
        //�����
        for(int i = 0; i < N; i ++)
        {
            cout<<x2[i]<<endl;
        }
    }
    //����Ϊ1e-5
    double x3[N] = {0};
    if(Jacobi(a, b, x3, 1e-5))
    {
        //�����
        for(int i = 0; i < N; i ++)
        {
            cout<<x3[i]<<endl;
        }

    }
    return 0;
}
