//#include <iostream>
//using namespace std;
//
//void func(int a, int b)
//{
//	cout << "������ͨ����" << endl;
//}
//
//template<typename T>
//void func(T a, T b)
//{
//	cout << "����ģ�庯��" << endl;
//}
//
//template<typename T>
//void func(T a, T b, T c)
//{
//	cout << "��������ģ�庯��" << endl;
//}
//
//void test()
//{
//	int a = 1;
//	int b = 3;
//	
//	func(a, b);  // ���ȵ�����ͨ����
//	func<>(a, b);  // ʹ�ÿ�ģ������б��ɵ���ģ�庯��
//	func(a, b, b); // ģ�庯������
//
//	char c = 'c';
//	char d = 'd';
//	func(c, d);  // ����ƥ��
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}