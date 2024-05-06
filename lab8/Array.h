#ifndef ARRAY_H
#define ARRAY_H
#define MAX_SIZE 5

using namespace std;

#include <iostream>

class Array {
    friend ostream& operator<<(ostream&, const Array&);
    friend istream& operator>>(istream&, Array&);

public:
    Array(); 
    Array(int); 
    Array(const Array&); 
    ~Array(); 
    int getSize() const; 
    void setSize(int); 
    bool operator==(const Array&) const; 
    bool operator!=(const Array&) const; 
    int& operator[](int); 
    int operator[](int) const; 
    void operator()(int, int); 
    Array& operator++(); 
    Array operator++(int);

private:
    int list[MAX_SIZE];
    int size;
};

#endif