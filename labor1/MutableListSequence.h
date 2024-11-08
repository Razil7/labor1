#pragma once

#include "MutableSequence.h"
#include "LinkedList.h"

template<class ElmType>
class MutableListSequence : public MutableSequence<ElmType>
{
private:
    LinkedList<ElmType> _inner;
public:
    MutableListSequence() {}

    MutableListSequence(ElmType* source, int size) : _inner(size, source) {}

    MutableListSequence(const LinkedList<ElmType>& source) : _inner(source) {}

    ElmType getFirst() const override
    {
        return _inner[0];
    };

    ElmType getLast() const override
    {
        return _inner[_inner.getSize() - 1];
    }

    ElmType get(int index) const override
    {
        return _inner[index];
    }

    MutableListSequence<ElmType>* getSubsequence(int start, int end) override
    {
        LinkedList<ElmType>* res_inner = _inner.getSublist(start, end);
        MutableListSequence* res = new MutableListSequence(*res_inner);
        delete res_inner;

        return res;
    }

    int getSize() const override
    {
        return _inner.getSize();
    }

    void concat(const MutableSequence<ElmType>& source) override
    {
        for (int i = 0; i < source.getSize(); i++)
            _inner.append(source.get(i));
    }


    void append(ElmType value) override
    {
        _inner.append(value);
    }

    void prepend(ElmType value) override
    {
        _inner.prepend(value);
    }

    void insertAt(int index, ElmType value) override
    {
        _inner.insertAt(index, value);
    }

    void remove(int index)
    {
        _inner.remove(index);
    }

    void print() override
    {
        std::cout << _inner;
    }
};
