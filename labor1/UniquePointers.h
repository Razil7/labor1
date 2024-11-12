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

	UniquePointer(UniquePointer&& obj) : source(std::move(obj.source)){}

	UniquePointer<Elm>& operator=(UniquePointer<Elm>&& obj) {
		delete source ;
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
		source = std::move(newSource);
	}

private:
	Elm* source;
};