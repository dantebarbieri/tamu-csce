#include <iostream>

#include "bst.hpp"

using std::cout, std::endl;

// template <typename T>
// void print(typename BST<T>::Node* n) {
//     if(n) {
//         cout << n->obj << endl;
//     }
// }

void print(typename BST<int>::Node* n) {
    if(n) {
        cout << n->obj << ' ';
    }
}

int main() {
    BST<int> b;
    // BST<int>::print_separator = "\t\t";
    for(size_t i = 1; i <= 9; ++i)
        // b.insert((2*(i % 2)-1)*i);
        b.insert(rand() % 99 + 1);
    cout << b << endl;
    cout << "Pre Order: " << endl;
    b.preorder(print);
    cout << endl << "In Order: " << endl;
    b.inorder(print);
    cout << endl << "Post Order: " << endl;
    b.postorder(print);
    cout << endl;
}