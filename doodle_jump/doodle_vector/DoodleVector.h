#pragma once
#include <iostream>
#include "../exceptions/Exceptions.h"

template <typename T>
class DoodleVector {
private:
    T* arr;
    int capacity;
    int current;

public:
    DoodleVector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(const T& data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void pop() { current--; }

    T at(int index) { return arr[index]; }

    T& operator[](int index) {
        if (index < 0 || index >= current) {
            std::cout << "Array index out of bound, exiting";
            throw DoodleVectorInvalidIndexException();
        }
        return arr[index];
    }

    void clear() {
        delete[] arr;
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    int size() { return current; }

    ~DoodleVector() { delete[] arr; }
};