#include "Array.h"
#include <iostream>

Array::Array() : size(0) {}

Array::Array(int initSize) : size(initSize) {
    for (int i = 0; i < size; i++) {
        list[i] = 0;
    }
}

Array::Array(const Array& other) : size(other.size) {
    for (int i = 0; i < size; i++) {
        list[i] = other.list[i];
    }
}

Array::~Array() {}

int Array::getSize() const {
    return size;
}

void Array::setSize(int newSize) {
    size = newSize;
}

bool Array::operator==(const Array& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (list[i] != other.list[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return!(*this == other);
}

int& Array::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return list[index];
}

int Array::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return list[index];
}

void Array::operator()(int index, int value) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    list[index] = value;
}

Array& Array::operator++() {
    for (int i = 0; i < size; i++) {
        list[i]++;
    }
    return *this;
}

Array Array::operator++(int) {
    Array temp = *this;
    for (int i = 0; i < size; i++) {
        list[i]++;
    }
    return temp;
}

ostream& operator<<(ostream& os, const Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        os << arr.list[i];
        if (i < arr.size - 1) os << ", ";
    }
    return os;
}

istream& operator>>(istream& is, Array& arr) {
    int newSize;
    is >> newSize;
    if (newSize < 0 || newSize > MAX_SIZE) {
        throw out_of_range("Invalid size");
    }
    arr.setSize(newSize);
    for (int i = 0; i < newSize; i++) {
        is >> arr.list[i];
    }
    return is;
}