#include <exception>
#include <iostream>
#include <string>
#include "printarray.h"
#include "quicksort.h"

using std::string;

template <typename T>
bool sorted(T arr[N]) {
    for(size_t i = 1; i < N; ++i) {
        if(arr[i - 1] > arr[i]) return false;
    }
    return true;
}

template <typename T>
bool set_equiv(T expected[N], T actual[N]) {
    for(size_t i = 0; i < N; ++i) {
        size_t occurences = 0, expected_occurences = 0;
        for(size_t j = 0; j < N; ++j) {
            if(expected[i] == actual[j]) ++occurences;
        }
        for(size_t j = 0; j < N; ++j) {
            if(expected[i] == expected[j]) ++expected_occurences;
        }
        if(occurences != expected_occurences) return false;
    }
    return true;
}

template <typename T>
void test(T arr[N]) {
    T copy[N];
    for(size_t i = 0; i < N; ++i) copy[i] = arr[i];
    quicksort(copy, N);
    if(!sorted(copy) or !set_equiv(arr, copy)) throw std::runtime_error("Either not sorted or missing/duplicated values.");
}

int main() {
    int increasing[N];
    int decreasing[N];
    int random[N];
    for(int i = 0; i < N; ++i) {
        increasing[i] = i;
        decreasing[i] = N - i - 1;
        random[i] = rand() % (N*N);
    }
    std::cout << increasing << std::endl;
    std::cout << decreasing << std::endl;
    std::cout << random << std::endl;
    test(increasing);
    test(decreasing);
    test(random);
    quicksort(increasing, N);
    quicksort(decreasing, N);
    quicksort(random, N);
    std::cout << increasing << std::endl;
    std::cout << decreasing << std::endl;
    std::cout << random << std::endl;
    string phrase[N];
    phrase[0] = "Hello";
    phrase[1] = "there";
    phrase[2] = "my";
    phrase[3] = "name";
    phrase[4] = "is";
    phrase[5] = "Dante";
    // phrase[6] = "\0";
    // phrase[7] = "\0";
    // phrase[8] = "\0";
    // phrase[9] = "\0";
    std::cout << phrase << std::endl;
    test(phrase);
    quicksort(phrase, N);
    std::cout << phrase << std::endl;
}

