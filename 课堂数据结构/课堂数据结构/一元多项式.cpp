#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;

double cP(const vector<double>& a, double x)
{
    double result = 0.0;
    result += a[0] * 1//先把i=0的情况算入result中
        double tmp = x;//x^0
    for (int i = 1; i < n; i++)
    {
       
        double term = a[i] * tmp;
        result += term;
        tmp *= x;//自身一直自增
    }

    return result;
}

int main()
{
    double x;
    cin >> n;

    vector<double>a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> x;

    double P = cP(a, x);

    cout << P;


    return 0;
}



//详细解析
#define _CRT_SECURE_NO_WARNINGS



//使用 const vector<double>& 的声明方式可以提供以下优点：
//
//避免不必要的数据复制：通过使用引用（& ），而不是直接传递一个副本，避免了在函数调用时复制整个系数向量的开销，提高了效率。
//
//确保数据的不可变性：使用 const 修饰符可以确保函数内部不会修改传递的系数向量，这有助于提高代码的可读性并预防潜在的错误。
//
//因此，在这个例子中，const vector<double>& 是正确的参数声明方式，它既能提高性能，又能保证数据的不可变性。

#include <iostream>
#include <vector>

using namespace std;



//for循环实现累加
// 计算一元多项式的值 P(x)
double calculatePolynomial(const vector<double>& coefficients, double x) {
    double result = 0.0;
    result += a[0] * 1//先把i=0的情况算入result中
        double tmp = x;//x^0
    for (int i = 1; i < n; i++)
    {

        double term = a[i] * tmp;
        result += term;
        tmp *= x;//自身一直自增
    }

    return result;

    //pow(x,i)可以优化，先求出i=0的结果，然后直接得出

    return result;
}
 int n;
int main() {
   
    cout << "输入多项式的最高次数: ";
    cin >> n;

    vector<double> coefficients(n + 1);
    for (int i = 0; i <= n; i++) {
        cout << "输入系数 a[" << i << "]: ";
        cin >> coefficients[i];
    }

    double x;
    cout << "输入要计算的值 x: ";
    cin >> x;

    double result = calculatePolynomial(coefficients, x);

    cout << "P(" << x << ") = " << result << endl;

    return 0;
}
