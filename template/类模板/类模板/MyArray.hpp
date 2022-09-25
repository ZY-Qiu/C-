#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity);

	MyArray(const MyArray& arr);

	MyArray& operator=(const MyArray& arr);

	void Push_Back(const T& val);

	void Pop_Back();

	T& operator[](int index);

	int getCapacity();

	int getSize();

	~MyArray();
private:

	T* paddr; // ָ��������ٵ�����

	int m_capacity;  // ����

	int m_size;  // �����С
};


template<class T>
MyArray<T>::MyArray(int capacity)
{
	cout << "�вι������" << endl;
	this->m_capacity = capacity;
	this->m_size = 0;
	this->paddr = new T[capacity];
}

// ��� ���캯��
template<class T>
MyArray<T>::MyArray(const MyArray& arr)
{
	cout << "�����������" << endl;
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->paddr = new T[arr.m_capacity];

	for (int i = 0; i < arr.m_size; i++)
	{
		this->paddr[i] = arr.paddr[i];
	}
}

// ��������� =
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr)
{
	cout << "operator=�ĵ���" << endl;
	if (this->paddr != NULL)
	{
		this->m_capacity = 0;
		this->m_size = 0;
		delete[] this->paddr;
		this->paddr = NULL;
	}

	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->paddr = new T(arr.m_capacity);

	for (int i = 0; i < arr.m_size; i++)
	{
		this->paddr[i] = arr.paddr[i];
	}
	return *this;
}

// β�巨
template<class T>
void MyArray<T>::Push_Back(const T& val)
{
	if (this->m_capacity == this->m_size)
	{
		cout << "�����������޷���ӣ�" << endl;
		return;
	}
	this->paddr[this->m_size] = val;
	this->m_size++;
}

// βɾ��
template<class T>
void MyArray<T>::Pop_Back()
{
	if (this->m_size == 0)
	{
		cout << "����Ϊ�գ��޷�ɾ��" << endl;
		return;
	}
	this->m_size--;
}


// ���������[]��ʹ�ÿ���ͨ���±��������
template<class T>
T& MyArray<T>::operator[](int index)
{
	if (index < 0 || index >= this->m_size)
	{
		cout << "Index out of range!" << endl;
		return this->paddr[0];
	}
	return this->paddr[index];
}

template<class T>
int MyArray<T>::getCapacity()
{
	return this->m_capacity;
}

template<class T>
int MyArray<T>::getSize()
{
	return this->m_size;
}

template<class T>
MyArray<T>::~MyArray()
{
	if (this->paddr != NULL)
	{
		cout << "������������" << endl;
		delete[] this->paddr;
		this->paddr = NULL;
	}
	
}