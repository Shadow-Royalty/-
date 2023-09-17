#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n, arrsize;

void cf(vector<unsigned long long>& a)//这里用&是因为我们要改变a的量！
{
	if (n > arrsize || n < 1 || arrsize <= 0) {
		cout << "输入错误" << endl;
		return;
	}

	unsigned long long sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
		if (sum * pow(2, i) > ULLONG_MAX)
		{
			cout << "出错" << endl;
			return;
		}

		/*cout << sum * (2 ^ i);*/
		/*没必要在这里先打印，存好在i中后直接输出a即可.*/
		//a[i - 1] = sum * 2^(i);  err
		//^在计算机中不是乘的意思，不要用我们人类的语言！
		a[i - 1] = sum * pow(2, i);
	}
}

int main()
{

	cin >> n >> arrsize;

	vector<unsigned long long>a(arrsize);

	cf(a);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}