#include <iostream>

#include "bst.hpp"

using std::cout, std::endl;

int main() {
    BST<int> b;
    // BST<int>::print_separator = "\t\t";
    for(size_t i = 1; i <= 9; ++i)
        // b.insert((2*(i % 2)-1)*i);
        b.insert(rand() % 9 + 1);
    cout << b << endl;
}