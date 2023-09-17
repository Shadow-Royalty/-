#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n, arrsize;

void cf(vector<unsigned long long>& a)//������&����Ϊ����Ҫ�ı�a������
{
	if (n > arrsize || n < 1 || arrsize <= 0) {
		cout << "�������" << endl;
		return;
	}

	unsigned long long sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
		if (sum * pow(2, i) > ULLONG_MAX)
		{
			cout << "����" << endl;
			return;
		}

		/*cout << sum * (2 ^ i);*/
		/*û��Ҫ�������ȴ�ӡ�������i�к�ֱ�����a����.*/
		//a[i - 1] = sum * 2^(i);  err
		//^�ڼ�����в��ǳ˵���˼����Ҫ��������������ԣ�
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