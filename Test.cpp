#include <iostream>
#include "Test.hpp"
using namespace std;

int sum(int a, int b) { return a + b; }
bool is_even(int n) { return n % 2 == 0; }
int Pow(int a) { return a * a; }



template <typename Sequence>
void TestPrepend(Sequence& sequence) {
    cout << "Testing of Prepend is ";
    for (int i = 0; i < 5; i++) {
        sequence.Prepend(i);
        assert(sequence.Get(0) == i);
    }
    cout << "successful." << endl;
}


template <typename Sequence>
void TestAppend(Sequence& sequence) {
    cout << "Testing of Append is ";
    for (int i = 0; i < 5; i++) {
        sequence.Append(i);
        assert(sequence.Get(i) == i);
    }
    cout << "successful." << endl;
}

template <typename Sequence, typename T>
void TestGetSubSequence(Sequence& sequence, T thing) {
    cout << "Testing of GetSubSequence is ";
    for (int i = 0; i < 10; i++) {
        sequence.Append(thing);
    }
    Sequence* subSequence = sequence.GetSubSequence(2, 6);
    assert(subSequence->GetLength() == 5);
    for (auto i : *subSequence) {
        assert(i == thing);
    }
    delete subSequence;
    cout << "successful." << endl;
}


template <typename Sequence>
void TestInsertAt(Sequence& sequence) {
    cout << "Testing of InsertAt is ";
    for (int i = 4; i < 7; i++) {
        sequence.Append(i);
    }
    for (int i = 3; i > 0; i--) {
        sequence.InsertAt(i, 0);
    }
    for (int i = 0; i < sequence.GetLength(); i++) {
        assert(sequence.Get(i) == i + 1);
    }
    cout << "successful." << endl;
}

template <typename Sequence>
void TestConcat(Sequence* sequence1, Sequence* sequence2) {
    cout << "Testing of Concat is ";
    for (int i = 0; i < 5; i++) {
        sequence1->Append(i);
        sequence2->Append(i+5);
    }
    Sequence* concatenatedSequence = sequence1->Concat(sequence2);
    assert(concatenatedSequence->GetLength() == sequence1->GetLength() + sequence2->GetLength());
    for (int i = 0; i < 10; i++) {
        assert(concatenatedSequence->Get(i) == i);
    }
    delete concatenatedSequence;
    cout << "successful." << endl;
}

template <typename Sequence>
void TestMap(Sequence& sequence) {
    cout << "Testing of Map is ";
    for (int i = 0; i < 5; i++) {
        sequence.Append(i);
    }
    sequence.Map(Pow);
    for (int i = 0; i < 5; i++) {
        assert(sequence.Get(i) == Pow(i));
    }
    cout << "successful." << endl;
}

void TEST(){
    ArraySequence<int> *array = nullptr;
    LinkedListSequence<int> *list = nullptr;

    array = new ArraySequence<int>();
    list = new LinkedListSequence<int>();
    TestPrepend(*list);
    TestPrepend(*array);
    delete array;
    delete list;

    array = new ArraySequence<int>();
    list = new LinkedListSequence<int>();
    TestAppend(*list);
    TestAppend(*array);
    delete array;
    delete list;

    array = new ArraySequence<int>();
    list = new LinkedListSequence<int>();
    TestGetSubSequence(*list, 5);
    TestGetSubSequence(*array, 6);
    delete array;
    delete list;

    array = new ArraySequence<int>();
    list = new LinkedListSequence<int>();
    TestInsertAt(*list);
    TestInsertAt(*array);
    delete array;
    delete list;

    array = new ArraySequence<int>();
    list = new LinkedListSequence<int>();
    TestMap(*list);
    TestMap(*array);
    delete array;
    delete list;
    cout << "That's all!" << endl;
}

