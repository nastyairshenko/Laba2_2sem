#ifndef LABA2_2SEM_BASICCLASS_HPP
#define LABA2_2SEM_BASICCLASS_HPP
#pragma once

template <typename T> class BasicClass {
public:
    virtual T Get(int) const = 0;
    virtual int GetLength() const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
};
#endif //LABA2_2SEM_BASICCLASS_HPP
