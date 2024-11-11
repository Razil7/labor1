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
			std::cout << "\n�������� ��������:\n";
			std::cout << "0) ������� ���������.\n";
			std::cout << "1) �������� � ������.\n";
			std::cout << "2) �������� � �����.\n";
			std::cout << "3) �������� �� �������.\n";
			std::cout << "4) ������� � �����.\n";
			std::cout << "5) ������� � ������.\n";
			std::cout << "6) ������� �� �������.\n";
			std::cout << "7) ������� �� �����.\n";
			std::cin >> choise;

			switch (choise)
			{
			case 1:
			{
				int num;
				std::cout << "������� �����: \n";
				std::cin >> num;
				obj.prepend(num);
				break;
			}
			case 2:
			{
				int num;
				std::cout << "������� �����: \n";
				std::cin >> num;
				obj.append(num);
				break;
			}
			case 3:
			{
				int i, num;
				std::cout << "������� ������ � ����� ����� ������: \n";
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
				std::cout << "������� ������: \n";
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
			cout << "�������� �� �������, ���������� ������" << endl;
			cout << "������� �������� List : ";
			listPrint = true;
		}
		catch (std::exception& e) {
			cout << "�������� �� �������, ���������� ������" << endl;
			cout << "������� �������� List : ";
			listPrint = true;
		}
	} while (choise);
	return 0;
}
