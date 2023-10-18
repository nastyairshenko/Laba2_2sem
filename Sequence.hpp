#ifndef LABA2_2SEM_SEQUENCE_HPP
#define LABA2_2SEM_SEQUENCE_HPP

#pragma once
#include <tuple>
#include "BasicClass.hpp"

template <typename T> class Sequence : public BasicClass<T> {
public:
    virtual void Prepend(T) = 0;
    virtual Sequence<T>* Prepend(T) const = 0;
    virtual void Append(T) = 0;
    virtual Sequence<T>* Append(T) const = 0;
    virtual void InsertAt(T, int) = 0;
    virtual Sequence<T>* InsertAt(T, int) const = 0;
    virtual Sequence<T>* GetSubSequence(int, int) const = 0;
    virtual Sequence<T>* Concat(Sequence<T>*) const = 0;
    virtual Sequence<T> *operator+(Sequence<T>*) const = 0;
    virtual void Where(bool(*func)(T)) = 0;
    virtual Sequence<T>* Where(bool(*func)(T)) const = 0;
    virtual void Map(T(*func)(T)) = 0;
    virtual Sequence<T>* Map(T(*func)(T)) const = 0;
    virtual T Reduce(T(*func)(T, T), T) const = 0;
    virtual T Reduce(T(*func)(T, T)) const = 0;
    virtual T& operator[](int) = 0;
    virtual T operator[](int) const = 0;
    virtual ~Sequence() {};
};
#endif //LABA2_2SEM_SEQUENCE_HPP
