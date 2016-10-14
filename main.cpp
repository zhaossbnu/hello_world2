// @Author zhaossbnu
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

// 函数1
inline float func1(float x)
{
    return sqrt(4-sin(x) * sin(x));
}

// 函数2
inline float func2(float x)
{
    return x==0? 1 : sin(x) / x;
}

// 函数3
inline float func3(float x)
{
    return exp(x) / (4 + x * x);
}

// 函数4
inline float func4(float x)
{
    return log(1 + x) / (1 + x * x);
}

// 复化梯形公式
float Trapezium(float (*func)(float x), float a, float b, float n)
{
    // 计算步长
    float h = (b - a) / n;
    // 计算两个端点的值
    float F0 = func(a) + func(b);
    float F1 = 0;
    // 梯形公式
    for(int i = 1; i <= n - 1; i ++)
    {
        // 计算下一步
        float x = a + i * h;
        F1 += func(x);
    }
    return h * (F0 + 2 * F1) / 2;
}

// 复化Simpson公式
float Simpson(float (*func)(float x), float a, float b, float n)
{
    // 计算步长
    float h = (b - a) / (2 * n);
    // 计算两个端点的值
    float F0 = func(a) + func(b);
    float F1 = 0, F2 = 0;
    for(int i = 1 ; i <= 2 * n -1; i ++)
    {
        // 计算下一步
        float x = a + i * h;
        i % 2? F1 += func(x) : F2 += func(x);
    }
    return h *(F0 + 2 * F2 + 4 * F1) / 3;
}

int main(void)
{
    // 四个积分的准确值
    float I[4] = {0.4987111176, 0.9460830704, 0.3908118456, 0.2721982613};
    // 四个精度
    float e[4] = {0.001, 0.0001, 0.00001, 0.000001};
    // 研究积分方法与步长
    for(int i = 1; i <= 3; i ++)
    {
        int n = 10 * i;
        printf("步长为%d:\n\n", n);
        printf("       复化梯形公式\t复化Simpson公式\n");
        printf("函数1：%.10lf\t%.10lf\n", Trapezium(func1, 0, 0.25, n) - I[0], Simpson(func1, 0, 0.25, n) - I[0]);
        printf("函数2：%.10lf\t%.10lf\n", Trapezium(func2, 0, 1, n) - I[1], Simpson(func2, 0, 1, n) - I[1]);
        printf("函数3：%.10lf\t%.10lf\n", Trapezium(func3, 0, 1, n) - I[2], Simpson(func3, 0, 1, n) - I[2]);
        printf("函数4：%.10lf\t%.10lf\n", Trapezium(func4, 0, 1, n) - I[3], Simpson(func4, 0, 1, n) - I[3]);
        printf("\n");
    }
    // 研究精度
    for(int i = 0; i < 4; i ++)
    {
        cout<<"精度为："<<e[i]<<endl<<endl;
        printf("\t梯形\tSimpson\n");
        for(int j = 1; j < 1000; j ++)
        {
            int n = 10 * j;
            if(fabs(Trapezium(func1, 0, 0.25, n) - I[0]) < e[i])
            {
                printf("函数1：%6d\t", n);
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
                printf("函数2：%6d\t", n);
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
                printf("函数3：%6d\t", n);
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
                printf("函数4：%6d\t", n);
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

