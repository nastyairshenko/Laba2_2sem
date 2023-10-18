#ifndef LABA2_2SEM_MENU_HPP
#define LABA2_2SEM_MENU_HPP
#include "MENU.hpp"
#include "LinkedListSequence.hpp"
#include "DynamicArraySequence.hpp"
using namespace std;

template<typename T>
void Print(Sequence<T> *seq) {
    cout << " ";
    for (int i = 0; i !=  seq->GetLength(); i++) {
        cout << seq->Get(i) << " ";
    }
    cout << endl;
}

template <typename T>
void MENU() {
    Sequence<T> *sequence;
    Sequence<T> *subSequence = nullptr;
    Sequence<T> *sequence2 = nullptr;
    Sequence<T> *ConcatSeq = nullptr;
    int k, key;
    T thing;
    cout << ".........Types........." << endl;
    cout << "1. DynamicArraySequence." << endl;
    cout << "2. LinkedListSequence." << endl;
    cout << "......................." << endl << " - ";
    cin >> key;

    switch (key) {
        case 1:
            sequence = new ArraySequence<T>();
            break;
        case 2:
            sequence = new LinkedListSequence<T>();
            break;
        default:
            cout << "Incorrect key." << endl;
            return;
    }

    while (true) {
        cout << endl <<  "..............MENU.............." << endl;
        cout << " 1. Prepend." << endl;
        cout << " 2. Append." << endl;
        cout << " 3. Insert at." << endl;
        cout << " 4. Concatation." << endl;
        cout << " 5. Get subsequence." << endl;
        cout << " 6. Where." << endl;
        cout << " 7. Reduce." << endl;
        cout << " 8. Map." << endl;
        cout << " 9. Print current sequence." << endl;
        cout << " 10. Exit." << endl;
        cout << "................................" << endl << endl;
        cin >> key;

        switch (key) {
            case 1:
                cout << "Input value : " ;
                cin >> thing;
                sequence->Prepend(thing);
                cout << "Result : ";
                Print(sequence);
                break;
            case 2:
                cout << "Input value : ";
                cin >> thing;
                sequence->Append(thing);
                cout << "Result : ";
                Print(sequence);
                break;
            case 3:
                try {
                    cout << "Input  index : ";
                    cin >> k;
                    cout << endl << "Input value : ";
                    cin >> thing;
                    sequence->InsertAt(thing, k);
                    cout << "Result : ";
                    Print(sequence);
                    break;
                } catch (...) {
                    cout << " Try again." << endl;
                    break;
                }
            case 4:
                try {
                    cout << "Choose sequence type to concatenate with:" << endl;
                    cout << "1. ArraySequence." << endl;
                    cout << "2. LinkedListSequence." << endl;
                    cin >> key;
                    switch (key) {
                        case 1:
                            sequence2 = new ArraySequence<T>();
                            break;
                        case 2:
                            sequence2 = new LinkedListSequence<T>();
                            break;
                        default:
                            cout << "Incorrect key." << endl;
                            break;
                    }
                    cout << "Input values to append to sequence2 (input -2 to stop):" << endl;
                    while (true) {
                        cin >> thing;
                        if (thing == -2) {
                            break;
                        }
                        sequence2->Append(thing);
                    }
                    ConcatSeq = sequence->Concat(sequence2);
                    cout << "Result: ";
                    Print(ConcatSeq);
                    delete ConcatSeq;
                    delete sequence2;
                    break;
                } catch (...) {
                    cout << "Try again." << endl;
                    break;
                }
            case 5:
                try {
                    cout << "Input first index: ";
                    cin >> k;
                    cout << "Input last index: ";
                    cin >> thing;
                    subSequence = sequence->GetSubSequence(k, thing);
                    cout << "Subsequence: ";
                    Print(subSequence);
                    delete subSequence;
                    break;
                } catch (...) {
                    cout << "Try again." << endl;
                    break;
                }
            case 6:
                sequence->Where([](T value) { return value % 3 == 0; });
                cout << "Result: ";
                Print(sequence);
                break;
            case 7:
                thing = sequence->Reduce([](T a, T b) { return a * b; });
                cout << "Result: " << thing << "" << endl;
                break;
            case 8:
                sequence->Map([](T value) { return value - 1; });
                cout << "Result: ";
                Print(sequence);
                break;
            case 9:
                cout << "Array now : ";
                Print(sequence);
                break;
            case 10:
                delete sequence;
                return;
            default:
                cout << "Incorrect key." << endl;
                break;
        }
    }
}
#endif //LABA2_2SEM_MENU_HPP
