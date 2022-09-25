#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(int age, string name)
	{
		m_age = age;
		m_name = name;
	}


	// ����ʹ�����������
	bool operator==(Person& p)
	{
		if (m_age == p.m_age && m_name == p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int m_age;
	string m_name;
};

template<typename T>
bool cmp(T a, T b)
{
	return a == b;  // ����ʹ���Զ�����������
}

// ����ʹ�þ��廯Person��ģ�壬����ʱ���ȵ���
template<> bool cmp(Person a, Person b) // ����ɾ�� template<> ��д��һ����ͨ�ĺ������أ������ȵ���
{
	if (a.m_age == b.m_age && a.m_name == b.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test()
{
	Person p1(10, "Tom");
	Person p2(11, "Tom");

	//bool at = cmp(p1, p2);
	bool at = p1 == p2;
	cout << "�ԱȽ��Ϊ��" << at << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}