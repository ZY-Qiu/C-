#include "manager.h"

Manager::Manager(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptName()
{
	return "����";
}