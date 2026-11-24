#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class t>
class ArrayListType
{
public:
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int maxListSize() const;
    void insert(const t &insertItem);
    void remove(const t &removeItem);
    t &operator[](int index);
    void clearList();
    ArrayListType(int = 100);
    ArrayListType(const ArrayListType &arrayToCopy);
    const ArrayListType &operator=(const ArrayListType &arrayToCopy);
    ~ArrayListType();

protected:
    t *list;
    int length;
    int maxSize;
    void copyArray(const ArrayListType &arrayToCopy);
};

template <class t>
ArrayListType<t>::ArrayListType(int maxSize)
{
    if (maxSize <= 0)
    {
        maxSize = 100;
    }
    this->maxSize = maxSize;
    this->length = 0;
    list = new t[this->maxSize];
}

template <class Type>
bool ArrayListType<Type>::isEmpty() const
{
    return length == 0;
}

template <class t>
bool ArrayListType<t>::isFull() const
{
    return length == maxListSize;
}
#endif