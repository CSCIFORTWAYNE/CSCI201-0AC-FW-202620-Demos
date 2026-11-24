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
void ArrayListType<t>::insert(const t &insertItem)
{
    if (length == maxSize)
        return;
    list[length++] = insertItem;
}

template <class t>
void ArrayListType<t>::remove(const t &removeItem)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == removeItem)
        {
            for (int j = i + 1; j < length; j++)
            {
                list[i] = list[j];
                i++;
            }
            length--;
        }
    }
}

template <class t>
t &ArrayListType<t>::operator[](int index)
{
    return list[index];
}

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

template <class t>
inline ArrayListType<t>::~ArrayListType()
{
    delete[] list;
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
template <class t>
int ArrayListType<t>::size() const
{
    return length;
}
#endif