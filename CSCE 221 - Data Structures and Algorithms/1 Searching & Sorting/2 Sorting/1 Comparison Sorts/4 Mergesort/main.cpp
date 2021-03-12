#include <exception>
#include <iostream>
#include <string>
#include "mergesort.h"

using std::string;

template <typename T>
void printVector(const vector<T>&);

template <typename T>
bool vector_sorted(const vector<T>& v) {
    for(size_t i = 1; i < v.size(); ++i) {
        if(v.at(i-1) > v.at(i)) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool vector_contains_same(const vector<T>& expected, const vector<T>& actual) {
    for(auto const& e : actual) {
        bool found_it = false;
        for(auto const& ee: expected) {
            if(e == ee) {
                found_it = true;
            }
        }
        if(!found_it) {
            return false;
        }
    }

    for(auto const& e : expected) {
        bool found_it = false;
        for(auto const& ee: actual) {
            if(e == ee) {
                found_it = true;
            }
        }
        if(!found_it) {
            return false;
        }
    }
    return true;
}

template <typename T>
void testVector(const vector<T>& v) {
    vector<T> v_copy(v);
    merge_sort(v_copy);
    if(!vector_sorted(v_copy) or !vector_contains_same(v, v_copy)) {
        throw std::runtime_error("Vector is not sorted or does not contain same values.");
    }
}

int main() {
    vector<int> empty;
    vector<int> in_order{0, 2, 4, 8, 16};
    vector<int> in_order2{1, 3, 5, 7, 15};
    vector<int> in_reverse_order{16, 8, 4, 2, 0};
    vector<int> random;
    for(int i = 0; i < 10; ++i) {
        random.push_back(rand() % 100);
    }
    std::cout << "Pre-Sorting:" << std::endl;
    printVector(empty);
    printVector(in_order);
    printVector(in_reverse_order);
    printVector(random);

    // printVector(merge(in_order, in_order2));

    testVector(empty);
    testVector(in_order);
    testVector(in_reverse_order);
    testVector(random);

    merge_sort(empty);
    merge_sort(in_order);
    merge_sort(in_reverse_order);
    merge_sort(random);

    std::cout << "Post-Sorting:" << std::endl;
    printVector(empty);
    printVector(in_order);
    printVector(in_reverse_order);
    printVector(random);

    vector<string> string_vec{"Hello", "there", "my", "name", "is", "Dante"};
    printVector(string_vec);
    testVector(string_vec);
    merge_sort(string_vec);
    printVector(string_vec);

}

template <typename T>
void printVector(const vector<T>& v) {
    std::cout << "[";
    for(auto const& e : v) {
        std::cout << e;
        if(&e != &v.back()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}