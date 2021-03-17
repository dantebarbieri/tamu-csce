#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include <iostream>

template <typename T>
class BinaryTree
{
protected:
    struct Node
    {
        T obj;
        Node *left, *right;

        Node(T object = T{}, Node* leftChild = nullptr, Node* rightChild = nullptr) : obj{object}, left{leftChild}, right{rightChild} {}
    };
    size_t len;
    Node* root;
    void copy(Node* our_node, Node* their_node);
    void destroy(Node* node);
    void reset();
    const Node* search(const Node* n, const T& obj) const;
    Node* search(Node* n, const T& obj);
    // Node* search(Node* n, T obj);
    void print(std::ostream& os, const Node* n, size_t level = 0) const;
    Node* findWithChild(Node* n, const T& obj);
public:
    explicit BinaryTree(const T& rootObject);
    BinaryTree(const BinaryTree<T>& bt);
    BinaryTree(BinaryTree<T>&& bt);
    virtual ~BinaryTree();
    BinaryTree<T>& operator=(const BinaryTree<T>& bt);
    BinaryTree<T>& operator=(BinaryTree<T>&& bt);

    bool empty() const;
    size_t size() const;
    size_t length() const;

    const Node* search(const T& data) const;
    Node* search(const T& data);
    // Node* search(T data);

    Node& insertLeft(Node& n, const T& object);
    Node& insertRight(Node& n, const T& object);

    void remove(const T& object);
    T removeLeft(Node& n);
    T removeRight(Node& n);
    
    template <typename IT>
    friend std::ostream& operator<<(std::ostream& os, const BinaryTree<IT>& bt);
};

// Allows templates to be defined in a separate file
#include "binary_tree.cc"

#endif