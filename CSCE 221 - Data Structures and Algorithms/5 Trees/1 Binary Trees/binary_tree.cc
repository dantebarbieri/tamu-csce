#ifndef _BINARY_TREE_TPP_
#define _BINARY_TREE_TPP_

#include "binary_tree.hpp"

template <typename T>
void BinaryTree<T>::copy(Node *our_node, Node *their_node)
{
    if (their_node)
    {
        if (their_node->left)
        {
            insertLeft(*our_node, their_node->left->obj);
            copy(our_node->left, their_node->left);
        }
        if (their_node->right)
        {
            insertRight(*our_node, their_node->right->obj);
            copy(our_node->right, their_node->right);
        }
    }
}

template <typename T>
void BinaryTree<T>::destroy(Node *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <typename T>
void BinaryTree<T>::reset()
{
    root = nullptr;
    len = 0;
}

template <typename T>
const typename BinaryTree<T>::Node *BinaryTree<T>::search(const Node *n, const T &obj) const
{
    const Node *found = nullptr;
    if (n)
    {
        if (n->obj == obj)
        {
            found = n;
        }
        if (!found && n->left)
        {
            found = search(n->left, obj);
        }
        if (!found && n->right)
        {
            found = search(n->right, obj);
        }
    }
    return found;
}

template <typename T>
typename BinaryTree<T>::Node *BinaryTree<T>::search(Node *n, const T &obj)
{
    Node *found = nullptr;
    if (n)
    {
        if (n->obj == obj)
        {
            found = n;
        }
        if (!found && n->left)
        {
            found = search(n->left, obj);
        }
        if (!found && n->right)
        {
            found = search(n->right, obj);
        }
    }
    return found;
}

// template <typename T>
// typename BinaryTree<T>::Node *BinaryTree<T>::search(Node* n, T obj){
//     Node *found = nullptr;
//     if (n)
//     {
//         if (n->obj == obj)
//         {
//             found = n;
//         }
//         if (!found && n->left)
//         {
//             found = search(n->left, obj);
//         }
//         if (!found && n->right)
//         {
//             found = search(n->right, obj);
//         }
//     }
//     return found;
// }

template <typename T>
void BinaryTree<T>::print(std::ostream &os, const Node *n, size_t level) const
{
    constexpr char spaces[] = "    ";
    if (n)
    {
        // Preorder -- unused
        print(os, n->right, level + 1);
        // Inorder
        for (size_t i = 0; i < level; ++i)
        {
            os << spaces;
        }
        os << n->obj << '\n';
        print(os, n->left, level + 1);
        // Postoder -- unused
    }
}

template <typename T>
typename BinaryTree<T>::Node *BinaryTree<T>::findWithChild(Node *n, const T &obj)
{
    if (n)
    {
        if (n->left)
        {
            if (n->left->obj == obj)
            {
                return n;
            }
            findWithChild(n->left, obj);
        }
        if (n->right)
        {
            if (n->right->obj == obj)
            {
                return n;
            }
            findWithChild(n->right, obj);
        }
    }
    return nullptr;
}


template <typename T>
bool BinaryTree<T>::empty() const
{
    return size() == 0;
}

template <typename T>
size_t BinaryTree<T>::size() const
{
    return len;
}

template <typename T>
size_t BinaryTree<T>::length() const
{
    return size();
}

template <typename T>
BinaryTree<T>::BinaryTree(const T &rootObject) : len{1}, root{new Node(rootObject)} {}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &bt) : len{1}, root{new Node(bt.root->obj)}
{
    copy(root, bt.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &&bt) : len{bt.len}, root{bt.root}
{
    bt.reset();
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    destroy(root);
    reset();
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &bt)
{
    if (this == &bt)
    {
        return *this;
    }
    destroy(root);
    len = 1;
    root = new Node(bt.root->obj);
    copy(root, bt.root);
    return *this;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(BinaryTree<T> &&bt)
{
    if (this == &bt)
    {
        return *this;
    }
    destroy(root);
    len = bt.len;
    root = bt.root;
    bt.reset();
    return *this;
}

template <typename T>
const typename BinaryTree<T>::Node *BinaryTree<T>::search(const T &data) const
{
    return search(root, data);
}

template <typename T>
typename BinaryTree<T>::Node *BinaryTree<T>::search(const T &data)
{
    return search(root, data);
}


// template <typename T>
// typename BinaryTree<T>::Node *BinaryTree<T>::search(T data)
// {
//     return search(root, data);
// }

template <typename T>
typename BinaryTree<T>::Node &BinaryTree<T>::insertLeft(Node &n, const T &object)
{
    Node *n_left = n.left;
    n.left = new Node(object);
    n.left->left = n_left;
    ++len;
    return *n.left;
}

template <typename T>
typename BinaryTree<T>::Node &BinaryTree<T>::insertRight(Node &n, const T &object)
{
    Node *n_right = n.right;
    n.right = new Node(object);
    n.right->right = n_right;
    ++len;
    return *n.right;
}

template <typename T>
void BinaryTree<T>::remove(const T &object)
{
    if (root)
    {
        if (root->obj == object)
        {
            if (root->left)
            {
                root->obj = root->left->obj;
                removeLeft(*root);
            }
            else if (root->right)
            {
                root->obj = root->right->obj;
                removeRight(*root);
            }
            else
            {
                delete root;
                reset();
            }
        }
    }
    Node *n;
    do
    {
        n = findWithChild(root, object);
        if (n)
        {
            if (n->left && n->left->obj == object)
            {
                removeLeft(*n);
            }
            if (n->right && n->right->obj == object)
            {
                removeRight(*n);
            }
        }
    } while (n);
}

template <typename T>
T BinaryTree<T>::removeLeft(Node &n)
{
    if (n.left)
    {
        T data = n.left->obj;
        if (n.left->left)
        {
            n.left->obj = n.left->left->obj;
            removeLeft(*n.left);
        }
        else if (n.left->right)
        {
            n.left->obj = n.left->right->obj;
            removeRight(*n.left);
        }
        else
        {
            delete n.left;
            n.left = nullptr;
        }
        --len;
        return data;
    }
    return T{};
}

template <typename T>
T BinaryTree<T>::removeRight(Node &n)
{
    if (n.right)
    {
        T data = n.right->obj;
        if (n.right->right)
        {
            n.right->obj = n.right->right->obj;
            removeRight(*n.right);
        }
        else if (n.right->left)
        {
            n.right->obj = n.right->left->obj;
            removeLeft(*n.right);
        }
        else
        {
            delete n.right;
            n.right = nullptr;
        }
        --len;
        return data;
    }
    return T{};
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
{
    bt.print(os, bt.root);
    return os;
}

#endif