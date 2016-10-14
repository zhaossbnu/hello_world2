// @Author zhaossbnu
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

// ����1
inline float func1(float x)
{
    return sqrt(4-sin(x) * sin(x));
}

// ����2
inline float func2(float x)
{
    return x==0? 1 : sin(x) / x;
}

// ����3
inline float func3(float x)
{
    return exp(x) / (4 + x * x);
}

// ����4
inline float func4(float x)
{
    return log(1 + x) / (1 + x * x);
}

// �������ι�ʽ
float Trapezium(float (*func)(float x), float a, float b, float n)
{
    // ���㲽��
    float h = (b - a) / n;
    // ���������˵��ֵ
    float F0 = func(a) + func(b);
    float F1 = 0;
    // ���ι�ʽ
    for(int i = 1; i <= n - 1; i ++)
    {
        // ������һ��
        float x = a + i * h;
        F1 += func(x);
    }
    return h * (F0 + 2 * F1) / 2;
}

// ����Simpson��ʽ
float Simpson(float (*func)(float x), float a, float b, float n)
{
    // ���㲽��
    float h = (b - a) / (2 * n);
    // ���������˵��ֵ
    float F0 = func(a) + func(b);
    float F1 = 0, F2 = 0;
    for(int i = 1 ; i <= 2 * n -1; i ++)
    {
        // ������һ��
        float x = a + i * h;
        i % 2? F1 += func(x) : F2 += func(x);
    }
    return h *(F0 + 2 * F2 + 4 * F1) / 3;
}

int main(void)
{
    // �ĸ����ֵ�׼ȷֵ
    float I[4] = {0.4987111176, 0.9460830704, 0.3908118456, 0.2721982613};
    // �ĸ�����
    float e[4] = {0.001, 0.0001, 0.00001, 0.000001};
    // �о����ַ����벽��
    for(int i = 1; i <= 3; i ++)
    {
        int n = 10 * i;
        printf("����Ϊ%d:\n\n", n);
        printf("       �������ι�ʽ\t����Simpson��ʽ\n");
        printf("����1��%.10lf\t%.10lf\n", Trapezium(func1, 0, 0.25, n) - I[0], Simpson(func1, 0, 0.25, n) - I[0]);
        printf("����2��%.10lf\t%.10lf\n", Trapezium(func2, 0, 1, n) - I[1], Simpson(func2, 0, 1, n) - I[1]);
        printf("����3��%.10lf\t%.10lf\n", Trapezium(func3, 0, 1, n) - I[2], Simpson(func3, 0, 1, n) - I[2]);
        printf("����4��%.10lf\t%.10lf\n", Trapezium(func4, 0, 1, n) - I[3], Simpson(func4, 0, 1, n) - I[3]);
        printf("\n");
    }
    // �о�����
    for(int i = 0; i < 4; i ++)
    {
        cout<<"����Ϊ��"<<e[i]<<endl<<endl;
        printf("\t����\tSimpson\n");
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Trapezium(func1, 0, 0.25, n) - I[0]) < e[i])
            {
                printf("����1��%6d\t", n);
                break;
            }
        }
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Simpson(func1, 0, 0.25, n) - I[0]) < e[i])
            {
                printf("%6d\n", n);
                break;
            }
        }

        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Trapezium(func2, 0, 1, n) - I[1]) < e[i])
            {
                printf("����2��%6d\t", n);
                break;
            }
        }
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Simpson(func2, 0, 1, n) - I[1]) < e[i])
            {
                printf("%6d\n", n);
                break;
            }
        }

        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Trapezium(func3, 0, 1, n) - I[2]) < e[i])
            {
                printf("����3��%6d\t", n);
                break;
            }
        }
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Simpson(func3, 0, 1, n) - I[2]) < e[i])
            {
                printf("%6d\n", n);
                break;
            }
        }

        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Trapezium(func4, 0, 1, n) - I[3]) < e[i])
            {
                printf("����4��%6d\t", n);
                break;
            }
        }
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Simpson(func4, 0, 1, n) - I[3]) < e[i])
            {
                printf("%6d\n", n);
                break;
            }
        }
    }

    return 0;
}

