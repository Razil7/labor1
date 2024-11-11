#pragma once

#include <iostream>
#include <stdexcept>
#include "SharedPointers.h"


template<typename ElmType>
class LinkedList
{
private:
	struct Element
	{
		ElmType _value;
		SharedPointer<Element> _next;
	};

	SharedPointer<Element> _head;
	int _size;

	const ElmType& get(int index) const
	{
		if ((index < 0) or (index >= _size))
			throw std::out_of_range("Index out of range");

		int i = 0;

		SharedPointer<Element> res(_head);

		while (i < index)
		{
			i++;
			res = res->_next;
		}

		return res->_value;
	}

    ElmType& get(int index) 
	{
		if ((index < 0) or (index >= _size))
			throw std::out_of_range("Index out of range");

		int i = 0;

		SharedPointer<Element> res(_head);

		while (i < index)
		{
			i++;
			res = res->_next;
		}

		return res->_value;
	}

public:

	LinkedList() : _size(0), _head(nullptr) {}

	LinkedList(int size, ElmType* source) :_size(0), _head(nullptr)
	{
		for (int i = 0; i < size; i++)
			append(source[i]);
	}

	LinkedList(const LinkedList<ElmType>& source)
	{
		for (int i = 0; i < source.getSize(); i++)
			append(source[i]);
	}
	~LinkedList() {}

	const ElmType& operator[](int index) const
	{
		return get(index);
	}

	ElmType& operator[](int index) 
	{
		return get(index);
	}

	int getSize() const
	{
		return _size;
	}

	void append(ElmType value)
	{
		if (_size == 0)
		{
			_head.reset(new Element{ value, nullptr });
			_size++;
			return;
		}

		SharedPointer<Element> temp(_head);

		for (int i = 0; i < _size - 1; i++) {
			temp = temp->_next;
		}


		temp->_next.reset(new Element{ value,nullptr });

		_size++;
	}

	void prepend(ElmType value)
	{
		if (_size == 0)
		{
			SharedPointer<Element> _head2(new Element{ value, nullptr });
			_head = _head2;
			_size++;
			return;
		}

		SharedPointer<Element> temp(_head);
		SharedPointer<Element> _head2(new Element{ value, nullptr });
		_head = _head2;
		_head->_next = temp;
		_size++;
	}

	void insertAt(int index, ElmType value)
	{
		if ((index >= _size) or (index < 0))
			throw std::out_of_range("Index out of range");

		if (index == 0)
		{
			prepend(value);
			return;
		}

		SharedPointer<Element> temp(_head);
		for (int i = 0; i < index - 1; i++)
			temp = temp->_next;



		SharedPointer<Element> ptr(temp->_next);


		SharedPointer<Element> temp2(new Element{ value, nullptr });
		temp->_next = temp2;
		temp->_next->_next = ptr;
		_size++;
	}

	void concat(const SharedPointer<LinkedList<ElmType>> source)
	{
		for (int i = 0; i < source->getSize(); i++)
			this->append((*source)[i]);
	}

	void remove(int index)
	{
		if ((index >= _size) or (index < 0))
			throw std::out_of_range("Index out of range");

		SharedPointer<Element> temp(_head);
		if (index == 0)
		{
			temp = temp->_next;

			_head = temp;
			_size--;
			return;
		}

		for (int i = 0; i < index - 1; i++)
			temp = temp->_next;


		SharedPointer<Element> ptr(temp->_next);
		temp->_next = ptr->_next;
		_size--;
	}

	void popFirst() {
		remove(0);
	}

	void popLast() {
		remove(_size-1);
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList<ElmType>& source)
	{
		os << "[";

		for (int i = 0; i < source._size - 1; i++)
			os << source[i] << ", ";

		if (source._size != 0)
			os << source[source._size - 1];
		os << "]\n";

		return os;
	}
	
};