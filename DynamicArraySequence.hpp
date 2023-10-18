#ifndef LABA2_2SEM_DYNAMICARRAYSEQUENCE_HPP
#define LABA2_2SEM_DYNAMICARRAYSEQUENCE_HPP

#pragma once
#include "DynamicArray.hpp"
#include "Sequence.hpp"

template <class T> class ArraySequence : public Sequence<T> {
    DynamicArray<T> *General;
public:
    ArraySequence() : General(new DynamicArray<T>()) {};
    ArraySequence(T *array, int number) : General(new DynamicArray<T>(array, number)) {};
    ArraySequence(const DynamicArray<T> &arr) : General(new DynamicArray<T>(arr)) {};
    ArraySequence(const ArraySequence<T> &arr) : General(new DynamicArray<T>(*arr.General)) {};
    ArraySequence(Sequence<T> *seq) : General(new DynamicArray<T>()) {
        for (int i = 0; i < seq->GetLength(); i++) {
            this->General->Append(seq->Get(i));
        }
    };

    T GetFirst() const override
    { return this->General->GetFirst(); }

    T GetLast() const override
    { return this->General->GetLast(); }

    T Get(int k) const override
    { return this->General->Get(k); }

    int GetLength() const override
    { return this->General->GetLength(); }

    void Prepend(T thing) override
    { this->General->Prepend(thing); }

    ArraySequence<T> *Prepend(T thing) const override {
        auto *copy = new ArraySequence<T>(*this);
        copy->Prepend(thing);
        return copy;
    }

    void Append(T thing) override
    { this->General->Append(thing); }

    ArraySequence<T> *Append(T thing) const override {
        auto *copy = new ArraySequence<T>(*this);
        copy->Append(thing);
        return copy;
    }

    void InsertAt(T thing, int k) override {
        this->General->InsertAt(thing, k);
    }

    ArraySequence<T> *InsertAt(T thing, int k) const override {
        auto *copy = new ArraySequence<T>(*this);
        copy->InsertAt(thing, k);
        return copy;
    }

    ArraySequence<T> *GetSubSequence(int First, int Last) const override {
        DynamicArray<T>* newArr = this->General->GetSubArray(First, Last);
        auto* res = new ArraySequence(*newArr);
        delete newArr;
        return res;
    }

    ArraySequence<T> *Concat(Sequence<T> *seq) const override {
        auto *res = new ArraySequence<T>(*this);
        for (int i = 0; i < seq->GetLength(); i++) {
            res->Append(seq->Get(i));
        }
        return res;
    }

    Sequence<T> *operator+(Sequence<T> *seq) const override
    { return this->Concat(seq); }


    void Where(bool(*func)(T)) override {
        auto *newArr = new DynamicArray<T>();
        for (int i = 0; i < this->GetLength(); i++) {
            if (func(this->General->Get(i)))
            { newArr->Append(this->General->Get(i)); }
        }
        delete this->General;
        this->General = newArr;
    }

    ArraySequence<T> *Where(bool(*func)(T)) const override {
        auto *copy = new ArraySequence<T>(*this);
        copy->Where(func);
        return copy;
    }

    void Map(T(*func)(T)) override {
        for (int i = 0; i < this->GetLength(); i++) {
            (*this->General)[i] = func(this->General->Get(i));
        }
    }

    ArraySequence<T> *Map(T(*func)(T)) const override {
        auto *copy = new ArraySequence<T>(*this);
        copy->Map(func);
        return copy;
    }

    T Reduce(T(*func)(T, T), T sym) const override {
        T res = sym;
        for (int i = 0; i < this->GetLength(); i++) {
            res = func(res, this->General->Get(i));
        }
        return res;
    }

    T Reduce(T(*func)(T, T)) const override {
        T res = this->General->Get(0);
        for (int i = 1; i < this->GetLength(); i++) {
            res = func(res, this->General->Get(i));
        }
        return res;
    }

    T& operator[](int k) override
    { return (*this->General)[k]; }

    T operator[](int k) const override
    { return (*this->General)[k]; }

    using Iterator = class DynamicArray<T>::Iterator;
    using ConstIterator = class DynamicArray<T>::ConstIterator;

    Iterator begin() { return this->General->begin(); }
    Iterator end() { return this->General->end(); }
    ConstIterator begin() const {
        return ((const DynamicArray<T>*)this->General)->begin(); }
    ConstIterator end() const {
        return ((const DynamicArray<T>*)this->General)->end();
    }

    ~ArraySequence()
    { delete this->General; }
};
#endif //LABA2_2SEM_DYNAMICARRAYSEQUENCE_HPP
