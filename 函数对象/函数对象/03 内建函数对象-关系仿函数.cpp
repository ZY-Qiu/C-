#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);

	// ʹ��sort�㷨��������
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ʹ�ù�ϵ�º���greator<>()ʵ�ֽ���, sortĬ��ʹ��less<>()
	sort(v.begin(), v.end(), greater<int>());
	cout << "-----------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}