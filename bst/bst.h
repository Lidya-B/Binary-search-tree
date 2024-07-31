//*****************************************************************************************************
//
//		File:					bst.h
//
//		This program will impliment and test a array list  class.
//	
//		Other files required: 
//         1. searchtree.h
//			
//*****************************************************************************************************

#ifndef BST_H
#define BST_H

//*****************************************************************************************************

#include"searchtree.h"
#include<iostream>

//*****************************************************************************************************

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void destroy();
    void insert(const T& item);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    T* search(const T& item) const;
    int height() const;

private:
    Node<T>* root;
    void destroy(Node<T>*& node); 
    void insert(Node<T>*& node, const T& item); 
    void inorder(const Node<T>* node) const;
    void preorder(const Node<T>* node) const;
    void postorder(const Node<T>* node) const;
    Node<T>* search(Node<T>* node, const T& item) const; 
    int height(const Node<T>* node) const;
};

//*****************************************************************************************************

#endif 

//*****************************************************************************************************

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

//*****************************************************************************************************

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
    destroy(root);
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::destroy()
{
    destroy(root);
    root = nullptr;
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::insert(const T& item)
{
    insert(root, item);
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::inorder() const 
{
    inorder(root);
    std::cout << std::endl;
}
//*****************************************************************************************************

template<typename T>

void BinarySearchTree<T>::preorder() const 
{
    preorder(root);
    std::cout << std::endl;
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::postorder() const
{
    postorder(root);
    std::cout << std::endl;
}
//*****************************************************************************************************

template<typename T>
T* BinarySearchTree<T>::search(const T& item) const
{
    Node<T>* foundNode = search(root, item);
    if (foundNode != nullptr)
    {
        return &(foundNode->data);
    }
    else
    {
        return nullptr;
    }
}
//*****************************************************************************************************

template<typename T>
int BinarySearchTree<T>::height() const 
{
    return height(root);
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::destroy(Node<T>*& node)
{
    if (node != nullptr) 
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::insert(Node<T>*& node, const T& item) 
{
    if (node == nullptr) 
    {
        node = new Node<T>(item);
    }
    else if (item < node->data) 
    {
        insert(node->left, item);
    }
    else {
        insert(node->right, item);
    }
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::inorder(const Node<T>* node) const
{
    if (node != nullptr) 
    {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}
//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::preorder(const Node<T>* node) const
{

    if (node != nullptr) 
    {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::postorder(const Node<T>* node) const
{
    if (node != nullptr) 
    {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

//*****************************************************************************************************

template<typename T>
Node<T>* BinarySearchTree<T>::search(Node<T>* node, const T& item) const
{
    if (node == nullptr) 
    {
        return nullptr;
    }
    else if (item == node->data)
    {
        return node;
    }
    else if (item < node->data) 
    {
        return search(node->left, item);
    }
    else 
    {
        return search(node->right, item);
    }
}

//*****************************************************************************************************

template<typename T>
int BinarySearchTree<T>::height(const Node<T>* node) const
{
    if (node == nullptr) 
    {
        return -1;
    }
    else 
    {
        int left_height = height(node->left);
        int right_height = height(node->right);
        return 1 + std::max(left_height, right_height);
    }
}

//*****************************************************************************************************
