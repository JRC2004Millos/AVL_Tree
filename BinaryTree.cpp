#include "BinaryTree.hpp"

template <typename T>
bool BinaryTree<T>::addNodeAux(T const &data, BinaryNode<T> *&node)
{
    if (node == nullptr)
    {
        node = new BinaryNode<T>(data);
        return true;
    }
    else if (data < node->data)
    {
        return addNodeAux(data, node->leftChild);
    }
    else if (data > node->data)
    {
        return addNodeAux(data, node->rightChild);
    }

    // Se supone que un arbol binario no puede tener dos nodos con el mismo valor
    // por lo que si se llega a este punto, se retorna false.
    // Depende de la implementacion necesaria y el problema.
    return false;
}

template <typename T>
void BinaryTree<T>::preOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    list.push_back(node->data);
    preOrderAux(node->leftChild, list);
    preOrderAux(node->rightChild, list);
}

template <typename T>
void BinaryTree<T>::inOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrderAux(node->leftChild, list);
    list.push_back(node->data);
    inOrderAux(node->rightChild, list);
}

template <typename T>
void BinaryTree<T>::postOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    postOrderAux(node->leftChild, list);
    postOrderAux(node->rightChild, list);
    list.push_back(node->data);
}

template <typename T>
BinaryTree<T>::BinaryTree(T const &data)
{
    root = new BinaryNode<T>(data);
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
    root = nullptr;
}

template <typename T>
T BinaryTree<T>::getRoot() const
{
    return root->data;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
bool BinaryTree<T>::addNode(T const &data)
{
    if (isEmpty())
    {
        root = new BinaryNode<T>(data);
        return true;
    }

    return addNodeAux(data, root);
}

template <typename T>
list<T> BinaryTree<T>::preOrder() const
{
    // Creamos una lista vacia para almacenar los datos del arbol
    // en preorden.
    list<T> list;

    // Llamamos a la funcion auxiliar para recorrer el arbol en preorden.
    // Recibe por referencia la lista vacia para ir agregando los datos
    // del arbol.
    preOrderAux(root, list);

    return list;
}

template <typename T>
list<T> BinaryTree<T>::inOrder() const
{
    list<T> list;

    inOrderAux(root, list);

    return list;
}

template <typename T>
list<T> BinaryTree<T>::postOrder() const
{
    list<T> list;

    postOrderAux(root, list);

    return list;
}
