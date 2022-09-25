#include "workerManager.h"

WorkerManager::WorkerManager()
{
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	this->m_FileIsEmpty = 1;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "��ְ���ļ�" << endl;
		ifs.close();
	}
	else 
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//cout << "�ļ�Ϊ�գ�" << endl;
			ifs.close();
		}
		else
		{
			this->m_FileIsEmpty = 0;
			this->getEmpNum();

			this->m_EmpArray = new Worker * [this->m_EmpNum];
			this->init_Emp();
		}
	}
}

void WorkerManager::ShowMenu()
{
	cout << "***********************************************" << endl;
	cout << "*********** ��ӭʹ��ְ������ϵͳ�� ************" << endl;
	cout << "*************** 0.�˳�������� ****************" << endl;
	cout << "*************** 1.����ְ����Ϣ ****************" << endl;
	cout << "*************** 2.��ʾְ����Ϣ ****************" << endl;
	cout << "*************** 3.ɾ����ְְ�� ****************" << endl;
	cout << "*************** 4.�޸�ְ����Ϣ ****************" << endl;
	cout << "*************** 5.����ְ����Ϣ ****************" << endl;
	cout << "*************** 6.���ձ������ ****************" << endl;
	cout << "*************** 7.��������ĵ� ****************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::AddEmp()
{
	cout << "��������ӵ�ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		// ����ԭ����
		if (this->m_EmpNum != 0)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			int dep;
			string name;

			while (1)
			{
				cout << "�������" << i+1 << "����ְ���ı��" << endl;
				cin >> id;
				int index = this->isExist(id);
				if (index == -1)
				{
					break;
				}
				else
				{
					cout << "��ְ������Ѵ��ڣ����������룡" << endl;
				}
			}
			cout << "�������" << i+1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i+1 << "����ְ���Ĳ���" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dep;
			
			Worker* w = NULL;
			switch (dep)
			{
			case 1:
				w = new Employee(id, dep, name);
				break;
			case 2:
				w = new Manager(id, dep, name);
				break;
			case 3:
				w = new Boss(id, dep, name);
				break;
			default:
				break;
			}
			
			newSpace[m_EmpNum + i] = w;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "������������" << endl;
		system("cls");
	}
	system("pause");
	system("cls");
}

void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ְ����Ϣ�ļ���Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::trunc);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
	this->m_FileIsEmpty = false;
}

void WorkerManager::getEmpNum()
{
	int id;
	int did;
	string name;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		this->m_EmpNum++;
	}
	//cout << "ְ������Ϊ��" << this->m_EmpNum << endl;
	
}

void WorkerManager::init_Emp()
{
	int id;
	int did;
	string name;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	Worker* worker = NULL;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		switch(did)
		{
		case 1:
			worker = new Employee(id, did, name);
			break;
		case 2:
			worker = new Manager(id, did, name);
			break;
		case 3:
			worker = new Boss(id, did, name);
			break;
		default:
			break;
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ְ����Ϣ" << endl;
	}
	else
	{
		cout << "������ɾ��ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
	
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ���ְ����Ų����ڣ�" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ְ����Ϣ" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			int nid;
			string name;
			int did;
			
			cout << "�鵽" << id << "��ְ������������ְ�����" << endl;
			cin >> nid;
			cout << "ԭְ������" << this->m_EmpArray[index]->m_name << "����������ְ������" << endl;
			cin >> name;
			cout << "ԭְ�����ţ�" << this->m_EmpArray[index]->m_DeptID << "����������ְ������" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> did;

			delete this->m_EmpArray[index];
			Worker* w = NULL;
			
			switch (did)
			{
			case 1:
				w = new Employee(nid, did, name);
				break;
			case 2:
				w = new Manager(nid, did, name);
				break;
			case 3:
				w = new Boss(nid, did, name);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = w;

			this->save();

			cout << "ְ����ţ�" << id << " �޸ĳɹ���" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ���ְ����Ų����ڣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ְ����Ϣ" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;

		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "��������ҵ�ְ����ţ�" << endl;
			int id;
			cin >> id;

			int index = this->isExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "��������ҵ�ְ��������" << endl;
			string name;
			cin >> name;
			bool flag = false;

			for(int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "���ҳɹ���ְ�����Ϊ" << this->m_EmpArray[i]->m_ID
						<< "�ŵ���Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if(!flag)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "ѡ����ҷ�ʽ����" << endl;
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ְ����Ϣ" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if(select == 1)
				{
					if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[MinOrMax]->m_ID)
					{
						MinOrMax = j;  // Here is min
					}
				}
				else if (select == 2)
				{
					if (this->m_EmpArray[j]->m_ID > this->m_EmpArray[MinOrMax]->m_ID)
					{
						MinOrMax = j;  // Here is max
					}
				}
			}
			Worker* w = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
			this->m_EmpArray[MinOrMax] = w;
		}
		
		if(select != 1 && select != 2)
		{
			cout << "ѡ������ʽ����" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			this->save();
			cout << "����ɹ����������Ϊ��" << endl;
			this->ShowEmp();
		}
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int sel;
	cin >> sel;

	if (sel == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}
		delete [] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}