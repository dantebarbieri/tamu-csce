#include <iostream>
#include <string>

#include "binary_tree.hpp"

using std::cout, std::endl;

int main()
{
    BinaryTree<int> bt(5);
    auto &root = *bt.search(5);
    auto &root_left = bt.insertLeft(root, 3);
    auto &root_right = bt.insertRight(root, 10);
    cout << &root << endl
         << &root_left << endl
         << &root_right << endl;
    if (&root != bt.search(5))
    {
        cout << "Error root not found" << endl;
    }
    else
    {
        cout << "Found root" << endl;
    }
    if (&root_left != bt.search(3))
    {
        cout << "Error left child not found" << endl;
    }
    else
    {
        cout << "Found left child" << endl;
    }
    if (&root_right != bt.search(10))
    {
        cout << "Error right child not found" << endl;
    }
    else
    {
        cout << "Found right child" << endl;
    }
    bt.insertLeft(root_left, 1);
    bt.insertRight(root_left, 4);
    bt.insertLeft(root_right, 7);
    bt.insertRight(root_right, 17);
    cout << bt.search(1) << endl
         << bt.search(4) << endl
         << bt.search(7) << endl
         << bt.search(17) << endl;
    bt.insertRight(root, 6);
    cout << bt.search(6) << endl
         << bt.search(7) << endl
         << bt.search(17) << endl;
    cout << bt << endl;
    cout << bt.size() << endl;
    bt.remove(5);
    cout << bt << endl;
    cout << bt.size() << endl;
    BinaryTree<std::string> btsentence("Sentence");
    auto& sentence = *btsentence.search("Sentence");
    btsentence.insertLeft(sentence, "Subject");
    btsentence.insertRight(sentence, "Predicate");
    cout << btsentence << endl;
}
