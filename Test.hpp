#ifndef LABA2_2SEM_TEST_HPP
#define LABA2_2SEM_TEST_HPP
using namespace std;
#include <cassert>
#include "LinkedListSequence.hpp"
#include "DynamicArraySequence.hpp"


template <typename Sequence>
void TestAppend(Sequence &sequence);

template <typename Sequence>
void TestPrepend(Sequence &sequence);

template <typename Sequence, typename T>
void TestGetSubSequence(Sequence& sequence, T thing);

template <typename Sequence>
void TestInsertAt(Sequence& sequence);

template <typename Sequence>
void TestConcat(Sequence* sequence1, Sequence* sequence2);

template <typename Sequence>
void TestMap(Sequence& sequence);

void TEST();

#endif //LABA2_2SEM_TEST_HPP
