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
	int m_lenght{}; //размер массива
	int* m_data{}; //данные массива

public:
	IntegerArray();
	IntegerArray(int lenght);

	IntegerArray(const IntegerArray& a);

	~IntegerArray();

	void erase();

	int& operator[](int index) //перегрузим оператор [], чтобы мы могли получить доступ к элементам массива
	{
		if (index < 0 || index > m_lenght) //убедимся, что параметр index имеет допустимое значение
		{
			throw Bad_range();
		}
		return m_data[index];
	}

	void reallocate(int newLenght);

	void resize(int newLendht);


	IntegerArray& operator = (const IntegerArray& a) //оператор присваивания
	{
		if (&a == this) return *this; //проверка самоназначения
		reallocate(a.getLenght()); //устанавливаем размер нового массива
		for (int index{ 0 }; index < m_lenght; ++index) //копируем элементы
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
