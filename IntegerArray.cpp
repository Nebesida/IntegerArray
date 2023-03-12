#include "IntegerArray.h"
#include <iostream>

IntegerArray::IntegerArray() = default; //создает пустой массив

IntegerArray::IntegerArray(int lenght) : m_lenght{ lenght } //создает массив заданного размера
{
	if (lenght <= 0)
	{
		throw Bad_length();
	}

	if (lenght > 0)
		m_data = new int [lenght] {};
}

IntegerArray::IntegerArray(const IntegerArray& a) //конструктор копирования
{
	reallocate(a.getLenght()); //устанавливаем рамер нового массива
	for (int index{ 0 }; index < m_lenght; ++index) //копируем элементы
		m_data[index] = a.m_data[index];
}

IntegerArray::~IntegerArray() //деструктор, освобождающий любые динамически выделяемые данные
{
	delete[] m_data;
}

void IntegerArray::erase() //сотрет массив и установит длину в 0
{
	delete[] m_data;
	m_data = nullptr;
	m_lenght = 0;
}

void IntegerArray::reallocate(int newLenght) //быстро уничтожит все существующие элементы в массиве при изменении его размера
{
	erase();
	if (newLenght <= 0) return;

	m_data = new int[newLenght];
	m_lenght = newLenght;
}

void IntegerArray::resize(int newLendht) //сохранит все существующие элементы в массиве при изменении его размера, но медленно
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

void IntegerArray::insertBefore(int value, int index) //функция вставки
{
	if (index < 0 || index > m_lenght) //проверяем значение индекса
	{
		throw Bad_range();
	};

	int* data{ new int[m_lenght + 1] }; //создаем новый массив на один элемент больше, чем старый массив
	for (int before{ 0 }; before < index; ++before) //копируем все элементы до индекса
		data[before] = m_data[before];
	data[index] = value; //вставляем новый элемент в новый массив
	for (int after{ index }; after < m_lenght; ++after) //копируем все значения после вставленного элемента
		data[after + 1] = m_data[after];
	delete[] m_data; //удаляем старый массив, используем вместо него новый
	m_data = data;
	++m_lenght;
}

void IntegerArray::remove(int index) //функция удаления
{
	if (index < 0 || index > m_lenght) //проверяем значение индекса
	{
		throw Bad_range();
	}
	if (m_lenght == 1) //Если это последний оставшийся элемент в массиве, установите для массива значение empty и извлеките
	{
		erase();
		return;
	}

	int* data{ new int[m_lenght - 1] }; //Сначала создайте новый массив, на один элемент меньший, чем старый массив
	for (int before{ 0 }; before < index; ++before) //копируем все элементы до индекса
		data[before] = m_data[before];
	for (int after{ index + 1 }; after < m_lenght; ++after) //копируем все значения после удаленного элемента
		data[after - 1] = m_data[after];
	delete[] m_data; //удаляем старый массив, используем вместо него новый
	m_data = data;
	--m_lenght;
}

void IntegerArray::insertAtBeginnig(int value) { insertBefore(value, 0); } //вставка в начало

void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_lenght); } //вставка в конец

int IntegerArray::getLenght() const { return m_lenght; } //доступ для возврата длины массива

int IntegerArray::findValue(int value) //поиск значения в массиве
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