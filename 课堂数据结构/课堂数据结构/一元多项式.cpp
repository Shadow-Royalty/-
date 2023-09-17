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
    result += a[0] * 1//�Ȱ�i=0���������result��
        double tmp = x;//x^0
    for (int i = 1; i < n; i++)
    {
       
        double term = a[i] * tmp;
        result += term;
        tmp *= x;//����һֱ����
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



//��ϸ����
#define _CRT_SECURE_NO_WARNINGS



//ʹ�� const vector<double>& ��������ʽ�����ṩ�����ŵ㣺
//
//���ⲻ��Ҫ�����ݸ��ƣ�ͨ��ʹ�����ã�& ����������ֱ�Ӵ���һ���������������ں�������ʱ��������ϵ�������Ŀ����������Ч�ʡ�
//
//ȷ�����ݵĲ��ɱ��ԣ�ʹ�� const ���η�����ȷ�������ڲ������޸Ĵ��ݵ�ϵ������������������ߴ���Ŀɶ��Բ�Ԥ��Ǳ�ڵĴ���
//
//��ˣ�����������У�const vector<double>& ����ȷ�Ĳ���������ʽ��������������ܣ����ܱ�֤���ݵĲ��ɱ��ԡ�

#include <iostream>
#include <vector>

using namespace std;



//forѭ��ʵ���ۼ�
// ����һԪ����ʽ��ֵ P(x)
double calculatePolynomial(const vector<double>& coefficients, double x) {
    double result = 0.0;
    result += a[0] * 1//�Ȱ�i=0���������result��
        double tmp = x;//x^0
    for (int i = 1; i < n; i++)
    {

        double term = a[i] * tmp;
        result += term;
        tmp *= x;//����һֱ����
    }

    return result;

    //pow(x,i)�����Ż��������i=0�Ľ����Ȼ��ֱ�ӵó�

    return result;
}
 int n;
int main() {
   
    cout << "�������ʽ����ߴ���: ";
    cin >> n;

    vector<double> coefficients(n + 1);
    for (int i = 0; i <= n; i++) {
        cout << "����ϵ�� a[" << i << "]: ";
        cin >> coefficients[i];
    }

    double x;
    cout << "����Ҫ�����ֵ x: ";
    cin >> x;

    double result = calculatePolynomial(coefficients, x);

    cout << "P(" << x << ") = " << result << endl;

    return 0;
}
