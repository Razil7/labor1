template<class ElmType>
class MutableSequence 
{
public:
    virtual ElmType getFirst() const = 0;

    virtual ElmType getLast() const = 0;

    virtual ElmType get(int) const = 0;

    virtual ElmType operator[](int index) const
    {
        return get(index);
    }

    virtual int getSize() const = 0;

    virtual void append(ElmType) = 0;

    virtual void prepend(ElmType) = 0;

    virtual void insertAt(int, ElmType) = 0;

    virtual void concat(const SharedPointer<MutableSequence<ElmType>> ) = 0;

    virtual void remove(int) = 0;

    virtual void print() = 0;
};

