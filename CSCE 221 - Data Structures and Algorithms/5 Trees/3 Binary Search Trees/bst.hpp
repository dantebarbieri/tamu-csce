#ifndef _BST_HPP_
#define _BST_HPP_

#include "../1 Binary Trees/binary_tree.hpp"

template <typename T>
class BST
{
public:
    struct Node
    {
        T obj;
        Node *left, *right;
        Node(T object = T{}, Node *leftChild = nullptr, Node *rightChild = nullptr);
    };

private:
    size_t len;
    Node *root;
    void copy(Node *their);
    void destroy(Node *n);
    void reset();
    void print(std::ostream &os, const Node *n, size_t depth = 0) const;
    void preorder_helper(Node *n, void (*func)(Node *));
    void inorder_helper(Node *n, void (*func)(Node *));
    void postorder_helper(Node *n, void (*func)(Node *));
    void euler_traversal_helper(Node *n, void (*preorder)(Node *), void (*inorder)(Node *), void (*postorder)(Node *));

public:
    static std::string print_separator;
    BST();
    BST(const BST<T> &bst);
    BST(BST<T> &&bst);
    ~BST();
    BST<T> &operator=(const BST<T> &bst);
    BST<T> &operator=(BST<T> &&bst);

    bool empty() const;
    size_t size() const;
    size_t length() const;

    const Node *search(const T &data) const;
    Node *search(const T &data);

    Node &insert(const T &data);

    // Remove 1 node containing the data
    T remove(const T &data);

    void clear();

    void preorder(void (*func)(Node *));
    void inorder(void (*func)(Node *));
    void postorder(void (*func)(Node *));
    void euler_traversal(void (*preorder)(Node *), void (*inorder)(Node *), void (*postorder)(Node *));

    template <typename IT>
    friend std::ostream &operator<<(std::ostream &os, const BST<IT> &bst);
};

#include "bst.cc"

#endif