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
//void test()
//{
//	//Person p1("Jerry", 23);
//	Person<string, int> p1("Jerry", 2);  // ��ģ���޷��Զ������Ƶ���������ʽָ��
//	p1.ShowPerson();
//
//	Person<string> p2("Tom", 3);  // ��Ĭ��ģ�����������ָֻ��һ��
//	p2.ShowPerson();
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}