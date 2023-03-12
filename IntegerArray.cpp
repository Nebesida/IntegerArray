#include "IntegerArray.h"
#include <iostream>

IntegerArray::IntegerArray() = default; //������� ������ ������

IntegerArray::IntegerArray(int lenght) : m_lenght{ lenght } //������� ������ ��������� �������
{
	if (lenght <= 0)
	{
		throw Bad_length();
	}

	if (lenght > 0)
		m_data = new int [lenght] {};
}

IntegerArray::IntegerArray(const IntegerArray& a) //����������� �����������
{
	reallocate(a.getLenght()); //������������� ����� ������ �������
	for (int index{ 0 }; index < m_lenght; ++index) //�������� ��������
		m_data[index] = a.m_data[index];
}

IntegerArray::~IntegerArray() //����������, ������������� ����� ����������� ���������� ������
{
	delete[] m_data;
}

void IntegerArray::erase() //������ ������ � ��������� ����� � 0
{
	delete[] m_data;
	m_data = nullptr;
	m_lenght = 0;
}

void IntegerArray::reallocate(int newLenght) //������ ��������� ��� ������������ �������� � ������� ��� ��������� ��� �������
{
	erase();
	if (newLenght <= 0) return;

	m_data = new int[newLenght];
	m_lenght = newLenght;
}

void IntegerArray::resize(int newLendht) //�������� ��� ������������ �������� � ������� ��� ��������� ��� �������, �� ��������
{
	if (newLendht == m_lenght) return;

	if (newLendht <= 0)
	{
		throw Bad_length();
	}

	int* data{ new int[newLendht] };

	if (m_lenght > 0)
	{
		int elementsToCopy{ (newLendht > m_lenght) ? m_lenght : newLendht };
		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data;

	m_data = data;
	m_lenght = newLendht;
}

void IntegerArray::insertBefore(int value, int index) //������� �������
{
	if (index < 0 || index > m_lenght) //��������� �������� �������
	{
		throw Bad_range();
	};

	int* data{ new int[m_lenght + 1] }; //������� ����� ������ �� ���� ������� ������, ��� ������ ������
	for (int before{ 0 }; before < index; ++before) //�������� ��� �������� �� �������
		data[before] = m_data[before];
	data[index] = value; //��������� ����� ������� � ����� ������
	for (int after{ index }; after < m_lenght; ++after) //�������� ��� �������� ����� ������������ ��������
		data[after + 1] = m_data[after];
	delete[] m_data; //������� ������ ������, ���������� ������ ���� �����
	m_data = data;
	++m_lenght;
}

void IntegerArray::remove(int index) //������� ��������
{
	if (index < 0 || index > m_lenght) //��������� �������� �������
	{
		throw Bad_range();
	}
	if (m_lenght == 1) //���� ��� ��������� ���������� ������� � �������, ���������� ��� ������� �������� empty � ���������
	{
		erase();
		return;
	}

	int* data{ new int[m_lenght - 1] }; //������� �������� ����� ������, �� ���� ������� �������, ��� ������ ������
	for (int before{ 0 }; before < index; ++before) //�������� ��� �������� �� �������
		data[before] = m_data[before];
	for (int after{ index + 1 }; after < m_lenght; ++after) //�������� ��� �������� ����� ���������� ��������
		data[after - 1] = m_data[after];
	delete[] m_data; //������� ������ ������, ���������� ������ ���� �����
	m_data = data;
	--m_lenght;
}

void IntegerArray::insertAtBeginnig(int value) { insertBefore(value, 0); } //������� � ������

void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_lenght); } //������� � �����

int IntegerArray::getLenght() const { return m_lenght; } //������ ��� �������� ����� �������

int IntegerArray::findValue(int value) //����� �������� � �������
{
	int index = -1;
	for (int i = 0; i < m_lenght; ++i)
	{
		if (m_data[i] == value)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		std::cout << "index " << value << " = " << index << std::endl;
	}
	else throw Bad_value();

	return value;
}