#pragma once
#include <iostream> 
#include "SharedPointers.h"
using namespace std;



template <typename Elm>
class UniquePointer
{
public:
	UniquePointer() : source(nullptr) {};

	UniquePointer(Elm*&& elm) : source(elm) {}

	UniquePointer(const UniquePointer& obj) = delete;

	UniquePointer<Elm>& operator=(const UniquePointer<Elm>& obj) = delete;

	UniquePointer(UniquePointer&& obj) : source(std::move(obj.sorce)){}

	UniquePointer<Elm>& operator=(UniquePointer<Elm>&& obj) {
		source = std::move(obj.sorce);
		return *this;
	}

	~UniquePointer()
	{
		delete source;
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

	void setPtr(Elm*&& newSource) {
		if (source) throw EmptyPtr("setPtr - Unique не nullptr");
		source = newSource;
	}

private:
	Elm* source;
};