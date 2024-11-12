#include "LinkedList.h"
#include <iostream>
#include "MyExeption.h"
#include "test.h"
#include <cassert>
#include <sstream>
#include "UniquePointers.h"
#include "SharedPointers.h"
#include "WeakPointers.h"
using namespace std;

void test_append() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.append(i);
		}
		for (int i = 0; i < 10; i++) {
			assert(list[i] == i);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]\n");
	}
	catch(EmptyPtr& e){
		cout << "тест test_append - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_append - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_append - пройден" << endl;
	return;
}

void test_prepend() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.prepend(i);
		}
		for (int i = 0; i < 10; i++) {
			assert(list[i] == 9-i);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_prepend - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_prepend - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_prepend - пройден" << endl;
	return;
}
void test_insertAt() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.prepend(i);
		}
		list.insertAt(4, 400);
		for (int i = 0; i < 4; i++) {
			assert(list[i] == 9 - i);
		}
		assert(list[4] == 400);
		for (int i = 5; i < 11; i++) {
			assert(list[i] == 9 - i + 1);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[9, 8, 7, 6, 400, 5, 4, 3, 2, 1, 0]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_insertAt - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_insertAt - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_insertAt - пройден" << endl;
	return;
}
void test_concat() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.append(i);
		}
		SharedPointer<LinkedList<int>> ptr(new LinkedList<int>);
		for (int i = 0; i < 10; i++) {
			ptr->append(i + 10);
		}
		list.concat(ptr);
		for (int i = 0; i < 20; i++) {
			assert(list[i] == i);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_concat - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_concat - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_concat - пройден" << endl;
	return;
}

void test_remove() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.append(i);
		}
		list.remove(5);
		for (int i = 0; i < 5; i++) {
			assert(list[i] == i);
		}
		for (int i = 5; i < 9; i++) {
			assert(list[i] == i+1);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[0, 1, 2, 3, 4, 6, 7, 8, 9]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_remove - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_remove - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_remove - пройден" << endl;
	return;
}

void test_popFirst() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.append(i);
		}
		list.popFirst();
		for (int i = 0; i < 9; i++) {
			assert(list[i] == i+1);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[1, 2, 3, 4, 5, 6, 7, 8, 9]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_popFirst - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_popFirst - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_popFirst - пройден" << endl;
	return;
}
void test_popLast() {
	try {
		LinkedList <int> list;
		for (int i = 0; i < 10; i++) {
			list.append(i);
		}
		list.popLast();
		for (int i = 0; i < 9; i++) {
			assert(list[i] == i);
		}
		stringstream ss;
		ss << list;
		assert(ss.str() == "[0, 1, 2, 3, 4, 5, 6, 7, 8]\n");
	}
	catch (EmptyPtr& e) {
		cout << "тест test_popLast - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_popLast - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_popLast - пройден" << endl;
	return;
}

void test_UniquePtr() {

	try {
		UniquePointer<int> ptr(new int(3));
		stringstream ss;
		ss << *ptr;
		assert(ss.str() == "3");

		UniquePointer<int> ptrnull;
		ptrnull.setPtr(new int(3));
		stringstream ss1;
		ss1 << *ptrnull;
		assert(ss1.str() == "3");

		UniquePointer<int> ptr2;
		ptr2 = std::move( ptr );
		stringstream ss2 ;
		ss2 << *ptr2 ;
		assert(ss2.str() == "3") ;

	}
	catch (EmptyPtr& e) {
		cout << "тест test_UniquePtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_UniquePtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_UniquePtr - пройден" << endl;
	return;
}
void test_SharedPtr() {

	try {
		SharedPointer<int> ptr(new int(3));
		stringstream ss;
		ss << *ptr;
		assert(ss.str() == "3");

		SharedPointer <int> ptrnull;
		ptrnull.reset(new int(3));
		stringstream ss1;
		ss1 << *ptrnull;
		assert(ss1.str() == "3");

		stringstream ss11;
		ss11 << ptrnull.GetCount();
		assert(ss11.str() == "1");

		SharedPointer <int> ptr2;
		ptr2 = std::move(ptr);
		stringstream ss2;
		ss2 << *ptr2;
		assert(ss2.str() == "3");

		SharedPointer <int> ptr3;
		ptr3 = ptr;
		stringstream ss3;
		ss3 << *ptr3;
		assert(ss3.str() == "3");

		stringstream ss33;
		ss33 << ptr3.GetCount();
		assert(ss33.str() == "2");

	}
	catch (EmptyPtr& e) {
		cout << "тест test_SharedPtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_SharedPtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_SharedPtr - пройден" << endl;
	return;
}
void test_WeakPtr() {
	try {
		WeakPointer<int> ptrweak;
		stringstream ss0;
		ss0 << ptrweak.expired();
		ss0 << ptrweak.use_count();
		assert(ss0.str() == "10");

		SharedPointer<int> ptr(new int(3));
		stringstream ss;
		ss << *ptr;
		assert(ss.str() == "3");

		SharedPointer <int> ptrnull;
		ptrnull.reset(new int(3));
		stringstream ss1;
		ss1 << *ptrnull;
		assert(ss1.str() == "3");

		WeakPointer<int> weak(ptrnull);
		SharedPointer <int> ptrX = weak.lock();
		
		stringstream ss11;
		ss11 << ptrnull.GetCount();
		assert(ss11.str() == "2");

		SharedPointer <int> ptr2;
		ptr2 = std::move(ptr);
		stringstream ss2;
		ss2 << *ptr2;
		assert(ss2.str() == "3");

		SharedPointer <int> ptr3;
		ptr3 = ptr;
		stringstream ss3;
		ss3 << *ptr3;
		assert(ss3.str() == "3");

		stringstream ss33;
		ss33 << ptr3.GetCount();
		assert(ss33.str() == "2");

	}
	catch (EmptyPtr& e) {
		cout << "тест test_WeakPtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	catch (std::exception& e) {
		cout << "тест test_WeakPtr - НЕ пройден - " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "тест test_WeakPtr - пройден" << endl;
	return;
}