//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ������������ģ�����
//template<class NameType, class AgeType = int> // ��ģ���п�����Ĭ�ϲ���
//class Person
//{
//public:
//
//	Person(NameType name, AgeType age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//
//	void ShowPerson()
//	{
//		cout << "Name = " << this->m_name << ", age = " << this->m_age << endl;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//// 1.ָ����������
//void Print1(Person<string, int> &p)
//{
//	cout << "Name = " << p.m_name << "\tage = " << p.m_age << endl;
//}
//
//// 2.����ģ�廯�������ú���ģ����Զ������Ƶ�
//template<class T1, class T2>
//void Print2(Person<T1, T2>& p)
//{
//	cout << "Name type = " << typeid(T1).name() << endl;
//	cout << "age type = " << typeid(T2).name() << endl;
//}
//
//// 3.��������ģ�廯
//template<class T>
//void Print3(T& p)
//{
//	cout << "Name = " << p.m_name << "\tage = " << p.m_age << endl;
//}
//
//void test()
//{
//	//Person p1("Jerry", 23);
//	Person<string, int> p1("Jerry", 2);  // ��ģ���޷��Զ������Ƶ���������ʽָ��
//	Print1(p1);
//
//	Person<string> p2("Tom", 3);  // ��Ĭ��ģ�����������ָֻ��һ��
//	Print2(p2);
//
//	Person<string, int> p3("Jack", 4);
//	Print3(p3);
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}