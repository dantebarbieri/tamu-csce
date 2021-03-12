#ifndef _PRINTARRAY_H_
#define _PRINTARRAY_H_

#include <iostream>

#define N 10

template <typename T>
std::ostream& operator<<(std::ostream&, const T*&);

template <typename T>
std::ostream& operator<<(std::ostream&, const T (&)[N]);

template <typename T>
std::ostream& operator<<(std::ostream& os, const T*& arr) {
    size_t size = sizeof(arr) / sizeof(T);
    os << '[';
    for(size_t i = 0; i < size; ++i) {
        os << arr[i];
        if(i + 1 != size) {
            os << ", ";
        }
    }
    return os << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const T (&arr)[N]) {
    size_t size = sizeof(arr) / sizeof(T);
    os << '[';
    for(size_t i = 0; i < size; ++i) {
        os << arr[i];
        if(i + 1 != size) {
            os << ", ";
        }
    }
    return os << ']';
}


#endif