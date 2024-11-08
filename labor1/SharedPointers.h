#pragma once
#include <iostream> 
#include "MyExeption.h"
#include "WeakPointers.h"
using namespace std;


template <class Elm>
class WeakPointer;

template <class Elm>
class SharedPointer
{
public:
	SharedPointer() : source(nullptr), refCounter(new int(0)), weakCounter(new int(0)) {};
	SharedPointer(Elm*&& elm) : source(elm), refCounter(new int(1)), weakCounter(new int(0)) {}
	SharedPointer(const SharedPointer& obj) : source(obj.source), refCounter(obj.refCounter), weakCounter(obj.weakCounter)
	{
		(*refCounter)++;
	}
	explicit SharedPointer(const WeakPointer<Elm>& weak):source(weak.source), weakCounter(weak.weakCounter), refCounter(weak.refCounter) {
		(*refCounter)++;
	}

	SharedPointer& operator=(const SharedPointer& right_obj) {

		if (*refCounter == 1) {
			delete source;
			delete refCounter;
		}
		else {
			(*refCounter)--;
		}
		source = right_obj.source;
		refCounter = right_obj.refCounter;
		(*refCounter)++;
		return *this;
	}

	~SharedPointer()
	{
		if (*refCounter > 1)
		{
			(*refCounter)--;
			return;
		}

		delete source;
		if (*weakCounter == 0) {
			delete refCounter;
			delete weakCounter;
		}
		
	}


	void reset(Elm* obj)
	{
		delete source;
		source = obj;
		obj = nullptr;
	}

	Elm& operator*()
	{
		if (!source) {
			throw EmptyPtr("указатель nullptr");
		}
		return *source;
	}

	int GetCount()
	{
		return *refCounter;
	}

	Elm* operator->() {
		if (!source) {
			throw EmptyPtr("указатель nullptr");
		}
		return source;
	}

	Elm* operator->() const {
		if (!source) {
			throw EmptyPtr("указатель nullptr");
		}
		return source;
	}
	template <typename Elm>
	friend class WeakPointer;
private:
	Elm* source;
	int* refCounter;
	int* weakCounter;
};

