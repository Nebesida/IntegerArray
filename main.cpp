#include <iostream>
#include "IntegerArray.h"
#include "BadLength.h"
#include "BadRange.h"
#include "BadValue.h"


int main()
{	
	try
	{
		IntegerArray array(10); //Объявите массив из 10 элементов

		//Заполните массив числами от 1 до 10
		try
		{
			for (int i{ 0 }; i < 10; ++i)
				array[i] = i + 1;
		}
		catch (Exception& e)
		{
			e.Show();
		}

		//Измените размер массива до 8 элементов
		try
		{
			array.resize(8);
		}
		catch (Exception& e)
		{
			e.Show();
		}

		//Вставьте число 20 перед элементом с индексом 5
		try
		{
			array.insertBefore(20, 5);
		}
		catch (Exception& e)
		{
			e.Show();
		}

		//Удалите элемент с индексом 3
		try
		{
			array.remove(3);
		}
		catch (Exception& e)
		{
			e.Show();
		}

		array.insertAtEnd(30); //Добавьте 30 к концу
		array.insertAtBeginnig(40); //Добавьте 40 к началу

		//Поиск по значению
		try
		{
			array.findValue(5);
		}
		catch (Exception& e)
		{
			e.Show();
		}

		for (int i{ 0 }; i < array.getLenght(); ++i) //вывод на экран
			std::cout << array[i] << ' ';
		std::cout << '\n';
	}
	catch (Bad_length &e)
	{
		e.Show();
	}

	return 0;
}