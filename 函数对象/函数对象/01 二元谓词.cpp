//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Greater
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//
//void test()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(50);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(30);
//
//	// ʹ��sort�㷨��������
//	sort(v.begin(), v.end());
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	// ʹ�ö�Ԫν��Greater�º������ı�sort�㷨���ԣ�ʵ�ֽ�������
//	// Greater()Ϊ������������
//	sort(v.begin(), v.end(), Greater());
//	cout << "-----------------------------" << endl;
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}