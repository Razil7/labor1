#pragma once
#include "SharedPointers.h"
using namespace std;
template <typename T>
class SharedPointer;

template <typename T>
class WeakPointer
{
private:
    T* source;
    int* weakCounter;
    int* refCounter;

    void deleteIfLast()
    {
        if (weakCounter == nullptr) {
            return;
        }
        if (*weakCounter)
        {
            (*weakCounter)--;
        }

        if (*weakCounter == 0 and *refCounter == 0)
        {
            delete weakCounter;
            delete refCounter;
        }
    }

public:
    WeakPointer() : source(nullptr), weakCounter(nullptr), refCounter(nullptr) {}

    WeakPointer(const SharedPointer<T>& other) : source(other.source), weakCounter(other.weakCounter), refCounter(other.refCounter)
    {
        if (weakCounter)
        {
            (*weakCounter)++;
        }
    }

    WeakPointer(const WeakPointer<T>& other) : source(other.source), weakCounter(other.weakCounter), refCounter(other.refCounter)
    {
        if (weakCounter)
        {
            (*weakCounter)++;
        }
    }

    WeakPointer(WeakPointer<T>&& other) noexcept : source(other.source), weakCounter(other.weakCounter), refCounter(other.refCounter)
    {
        other.source = nullptr;
        other.weakCounter = nullptr;
        other.refCounter = nullptr;
    }

    WeakPointer<T>& operator=(const WeakPointer<T>& other)
    {
        if (this != &other)
        {
            if (weakCounter)
            {
                deleteIfLast();
            }

            source = other.source;
            weakCounter = other.weakCounter;
            refCounter = other.refCounter;

            if (weakCounter)
            {
                (*weakCounter)++;
            }
        }
        return *this;
    }

    WeakPointer<T>& operator=(WeakPointer<T>&& other) noexcept
    {
        if (this != &other)
        {
            if (weakCounter)
            {
                deleteIfLast();
            }

            source = std::move(other.source);
            weakCounter = std::move(other.weakCounter);
            refCounter = std::move(other.refCounter);

            if (weakCounter)
            {
                (*weakCounter)++;
            }
        }
        return *this;
    }

    ~WeakPointer()
    {
        deleteIfLast();
    }

    int use_count() const
    {
        return *refCounter;        
    }

    bool expired() const
    {
        return use_count() == 0;
    }

    SharedPointer<T> lock() const
    {
        return expired() ? SharedPointer<T>() : SharedPointer<T>(*this);
    }
    template <typename T>
    friend class SharedPointer;
};