#include "employee.h"

Employee::Employee(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName()
{
	return "Ա��";
}