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

	void deleteIfLast() {
		if (!refCounter) return;
		if (*refCounter > 0) (*refCounter)--;
		if(*refCounter == 0) {
			delete source;
			if (*weakCounter == 0) {
				delete weakCounter;
				delete refCounter;
			}
		}
	}
public:
	SharedPointer() : source(nullptr), refCounter(new int(1)), weakCounter(new int(0)) {};
	SharedPointer(Elm*&& elm) : source(elm), refCounter(new int(1)), weakCounter(new int(0)) {}
	SharedPointer(const SharedPointer& obj) : source(obj.source), refCounter(obj.refCounter), weakCounter(obj.weakCounter)
	{
		(*refCounter)++;
	}
	explicit SharedPointer(const WeakPointer<Elm>& weak) :source(weak.source), weakCounter(weak.weakCounter), refCounter(weak.refCounter) {
		(*refCounter)++;
	}

	SharedPointer& operator=(const SharedPointer& right_obj) {
		deleteIfLast();
		source = right_obj.source;
		refCounter = right_obj.refCounter;
		weakCounter = right_obj.weakCounter;
		(*refCounter)++;
		return *this;
	}
	SharedPointer(SharedPointer&& obj) : source(std::move(obj.sorce)),
		weakCounter(std::move(obj.weakCounter)), refCounter(std::move(obj.refCounter)) {}

	SharedPointer& operator=(SharedPointer&& right_obj) {
		deleteIfLast();
		source = std::move(right_obj.source);
		weakCounter = std::move(right_obj.weakCounter);
		refCounter = std::move(right_obj.refCounter);
	}
	~SharedPointer()
	{
		deleteIfLast();
	}

	void reset(Elm* obj)
	{
		deleteIfLast();
		source = obj;
		refCounter = new int(1);
		weakCounter = new int(0);
	}

	Elm& operator*()
	{
		if (!source) {
			throw EmptyPtr("указатель nullptr");
		}
		return *source;
	}
	const Elm& operator*() const
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

	const Elm* operator->() const {
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

