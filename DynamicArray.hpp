#ifndef LABA2_2SEM_DYNAMICARRAY_HPP
#define LABA2_2SEM_DYNAMICARRAY_HPP

#pragma once
#include <iostream>
#include "BasicClass.hpp"
using namespace std;

template <class T> class DynamicArray : public BasicClass<T> {
    T *Array;
    int Size = 0;
    int MaxSize = 0;

public:
    DynamicArray(T *array, int number) : Size(number), MaxSize(number * 2) {
        this->Array = new T[this->MaxSize];
        for (int i = 0; i < number; i++) {
            this->Array[i] = array[i];
        }
    };

    DynamicArray() : DynamicArray(0) {};

    DynamicArray(int size) : Size(0), MaxSize(size * 2){
        this->Array = new T[this->MaxSize];
    };

    DynamicArray(const DynamicArray<T> &array) : DynamicArray(array.Array, array.Size) {};

    int GetLength() const override
    { return this->Size; }

    T Get(int k) const override {
        if (k < 0 || k >= this->Size ) 
        { throw std::out_of_range("Index out of range"); }
        return this->Array[k];
    }
    
    T GetFirst() const override 
    { return this->Array[0]; }

    T GetLast() const override 
    { return this->Array[this->Size - 1]; }

    void Set(int k, T thing) {
        if (k < 0 || k >= this->Size ) 
        { throw std::out_of_range("Index out of range"); }
        this->Array[k] = thing;
    }

    DynamicArray<T> *Set(int k, T thing) const {
        auto *copy = new DynamicArray<T>(*this);
        copy->Set(k, thing);
        return copy;
    }

    DynamicArray<T> *GetSubArray(int first, int last) const {
        if (first < 0 || first >= this->Size)
        { throw std::out_of_range("First index out of range"); }
        if (last < 0 || last >= this->Size)
        { throw std::out_of_range("Last index out of range"); }
        if (first > last)
        { throw std::invalid_argument("First index mustn't be more than last index"); }
        auto *result = new DynamicArray<T>(last - first + 1);
        for (int i = first; i <= last; i++){
            result->Append(this->Array[i]);
        }
        return result;
    }

    void Resize(int NewSize) {
        if (NewSize < 0) 
        { throw std::invalid_argument("New size must be above zero"); }
        if (NewSize > MaxSize) {
            MaxSize = NewSize * 2;
            T *thing = new T[MaxSize];
            for (int i = 0; i < Size; i++) {
                thing[i] = Array[i];
            }
            delete[] Array;
            Array = thing;
        }
        Size = NewSize;
    }

    DynamicArray<T> *Resize(int NewSize) const {
        auto *copy = new DynamicArray<T>(*this);
        copy->Resize(NewSize);
        return copy;
    }

    void Prepend(T thing) {
        if (this->Size * 2 >= MaxSize) {
            MaxSize *= 2;
            T *newArr = new T[MaxSize];
            for (int i = 0; i < Size; i++) {
                newArr[i] = Array[i];
            }
            delete[] Array;
            Array = newArr;
        }
        for (int i = Size; i > 0; i--) {
            Array[i] = Array[i - 1];
        }
        Array[0] = thing;
        this->Size++;
    }

    DynamicArray<T> *Prepend(T thing) const {
        auto *copy = new DynamicArray<T>(*this);
        copy->Prepend(thing);
        return copy;
    }
    
    void Append(T thing) {
        if (this->Size * 2 >= MaxSize) {
            MaxSize = (MaxSize == 0) ? 2 : MaxSize * 2;
            T *newArr = new T[MaxSize];
            for (int i = 0; i < Size; i++) {
                newArr[i] = Array[i];
            }
            delete[] Array;
            Array = newArr;
        }
        Array[Size] = thing;
        this->Size++;
    }

    DynamicArray<T> *Append(T thing) const {
        auto *copy = new DynamicArray<T>(*this);
        copy->Append(thing);
        return copy;
    }

    void InsertAt(T thing, int k) {
        if (k < 0 || k >= this->Size) 
        { throw std::out_of_range("Index out of range"); }
        if (this->Size * 2 >= MaxSize) {
            MaxSize *= 2;
            T *newArr = new T[MaxSize];
            for (int i = 0; i < Size; i++) {
                newArr[i] = Array[i];
            }
            delete[] Array;
            Array = newArr;
        }
        for (int i = Size; i > k; i--) {
            Array[i] = Array[i - 1];
        }
        Array[k] = thing;
        this->Size++;
    }

    DynamicArray<T> *InsertAt(T thing, int k) const {
        auto *copy = new DynamicArray<T>(*this);
        copy->InsertAt(thing, k);
        return copy;
    }


    T& operator[](int k) {
        if (k < 0 || k >= this->Size)
        {throw std::out_of_range("Index out of range"); }
        return this->Array[k];
    }

    const T operator[](int k) const {
        return Get(k);
    }

    ~DynamicArray()
    { delete[] Array; }

    class Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = value_type&;
        pointer ptr;
    public:
        Iterator(pointer ptr)
        { this->ptr = ptr; }

        Iterator &operator++() {
            this->ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator thing = *this;
            this->ptr++;
            return thing;
        }

        bool operator!=(const Iterator &other) const
        { return this->ptr != other.ptr; }

        bool operator==(const Iterator &other) const
        { return this->ptr == other.ptr; }

        reference operator*()
        { return *ptr; }

        pointer operator->()
        { return ptr; }
    };

    class ConstIterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = value_type&;
        pointer ptr;
    public:
        ConstIterator(pointer ptr)
        { this->ptr = ptr; }

        ConstIterator &operator++() {
            this->ptr++;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator thing = *this;
            this->ptr++;
            return thing;
        }

        bool operator==(const ConstIterator &other) const
        { return this->ptr == other.ptr; }

        bool operator!=(const ConstIterator &other) const
        { return this->ptr != other.ptr; }

        const T operator*()
        { return *ptr; }

        const T* operator->()
         { return ptr; }
    };


    Iterator begin()
    { return Iterator(&this->FirstVal()); }

    Iterator end()
    { return Iterator(&this->LastVal() + 1); }

    ConstIterator begin() const
    { return ConstIterator(&this->FirstVal()); }

    ConstIterator end() const
    { return ConstIterator(&this->LastVal() + 1); }

private:
    T& FirstVal()
    { return this->Array[0]; }

    T& LastVal()
    { return this->Array[this->Size - 1]; }
};
#endif //LABA2_2SEM_DYNAMICARRAY_HPP
