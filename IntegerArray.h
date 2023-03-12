#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> //for assert()

#include "BadLength.h"
#include "BadRange.h"
#include "BadValue.h"

class IntegerArray
{
private:
	int m_lenght{}; //������ �������
	int* m_data{}; //������ �������

public:
	IntegerArray();
	IntegerArray(int lenght);

	IntegerArray(const IntegerArray& a);

	~IntegerArray();

	void erase();

	int& operator[](int index) //���������� �������� [], ����� �� ����� �������� ������ � ��������� �������
	{
		if (index < 0 || index > m_lenght) //��������, ��� �������� index ����� ���������� ��������
		{
			throw Bad_range();
		}
		return m_data[index];
	}

	void reallocate(int newLenght);

	void resize(int newLendht);


	IntegerArray& operator = (const IntegerArray& a) //�������� ������������
	{
		if (&a == this) return *this; //�������� ��������������
		reallocate(a.getLenght()); //������������� ������ ������ �������
		for (int index{ 0 }; index < m_lenght; ++index) //�������� ��������
			m_data[index] = a.m_data[index];
		return *this;
	}

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtBeginnig(int value);
	void insertAtEnd(int value);

	int getLenght() const;

	int findValue(int value);

};

#endif
