#include "LinkedList.h"
#include "UniquePointers.h"
#include "SharedPointers.h"
#include "WeakPointers.h"
#include <string>
#include <iostream>
#include "test.h"
#include "MutableListSequence.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	test_append();
	test_prepend();
	test_insertAt();
	test_concat();
	test_remove();
	test_popFirst();
	test_popLast();
	int choise;
	bool listPrint = false;
	LinkedList<int> obj;

	do
	{
		try {
			if (listPrint) {
				std::cout << obj;
				listPrint = false;
			}
			std::cout << "\nВыберите действие:\n";
			std::cout << "0) Закрыть программу.\n";
			std::cout << "1) Добавить в начало.\n";
			std::cout << "2) Добавить в конец.\n";
			std::cout << "3) Добавить по индексу.\n";
			std::cout << "4) Удалить с конца.\n";
			std::cout << "5) Удалить с начала.\n";
			std::cout << "6) Удалить по индексу.\n";
			std::cout << "7) Вывести на экран.\n";
			std::cin >> choise;

			switch (choise)
			{
			case 1:
			{
				int num;
				std::cout << "Введите число: \n";
				std::cin >> num;
				obj.prepend(num);
				break;
			}
			case 2:
			{
				int num;
				std::cout << "Введите число: \n";
				std::cin >> num;
				obj.append(num);
				break;
			}
			case 3:
			{
				int i, num;
				std::cout << "Введите индекс и число через пробел: \n";
				std::cin >> i >> num;
				obj.insertAt(i, num);
				break;
			}
			case 4:
			{
				obj.popLast();
				break;
			}
			case 5:
			{
				obj.popFirst();
				break;
			}
			case 6:
			{
				int i;
				std::cout << "Введите индекс: \n";
				std::cin >> i;
				obj.remove(i);
				break;
			}
			case 7:
			{
				std::cout << obj;
				break;
			}
			default:
				break;
			}
		}
		catch (EmptyPtr& e) {
			cout << "операция не удалась, попробуйте заново" << endl;
			cout << "текущее значение List : ";
			listPrint = true;
		}
		catch (std::exception& e) {
			cout << "операция не удалась, попробуйте заново" << endl;
			cout << "текущее значение List : ";
			listPrint = true;
		}
	} while (choise);
	return 0;
}
