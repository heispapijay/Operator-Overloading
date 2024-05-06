#include "Array.h"
#include <iostream>

int main() {
    Array list1;
    list1.setSize(5);
    list1(0, 1);
    list1(1, 2);
    list1(2, 3);
    list1(3, 4);
    list1(4, 5);

    cout << "list1: " << list1 << endl;

    Array list2(list1);
    cout << "list2: " << list2 << endl;
    cout << endl;

    if (list1 == list2) {
        cout << "list1 and list2 are equal" << endl;
        cout << endl;
    }
    else {
        cout << "list1 and list2 are not equal" << endl;
        cout << endl;
    }

    list1[0] = 10;
    cout << "list1: " << list1 << endl;

    if (list1 == list2) {
        cout << "list1 and list2 are equal" << endl;
        cout << endl;
    }
    else {
        cout << "list1 and list2 are not equal" << endl;
        cout << endl;
    }

    list1++;
    cout << "list1 after increment: " << list1 << endl;

    Array list3 = list1++;
    cout << "list1 after post-increment: " << list1 << endl;
    cout << endl;

    cout << "Enter the size of the Array (max " << MAX_SIZE << "): ";
    int size;
    cin >> size;
    if (size < 0 || size > MAX_SIZE) {
        cerr << "Invalid size. Exiting." << endl;
        return 1;
    }
    list1.setSize(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> list1[i];
    }
    cout << "list1 after input: " << list1 << endl;

    return 0;
}