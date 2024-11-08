#pragma once
#include <iostream> 
#include "SharedPointers.h"
using namespace std;



template <typename Elm>
class UniquePointer
{
public:
	UniquePointer() : source(nullptr) {};

	UniquePointer(Elm*&& elm) : source(elm) { }

	UniquePointer(const UniquePointer& obj) = delete;

	UniquePointer<Elm>& operator=(const UniquePointer<Elm>& obj) = delete;

	UniquePointer(UniquePointer&& obj) : source(obj.source) {
		obj.source = nullptr;
	}

	UniquePointer<Elm>& operator=(UniquePointer<Elm>&& obj) {
		delete source;
		source = obj.source;
		obj.source = nullptr;
		return *this;
	}

	~UniquePointer()
	{
		delete source;
	}

	Elm& operator*()
	{
		return *source;
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

	void setPtr(Elm*&& newSource) {
		if (!source) {
			source = newSource;
			return;
		}
		throw EmptyPtr("setPtr - Unique не nullptr");
	}

private:
	Elm* source;
};