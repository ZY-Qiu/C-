#include "boss.h"

Boss::Boss(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��ѹե�ײ�" << endl;
}

string Boss::getDeptName()
{
	return "�ϰ�";
}