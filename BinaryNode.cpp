#include "BinaryNode.hpp"

template <typename T>
BinaryNode<T>::BinaryNode(T data)
{
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <typename T>
BinaryNode<T>::BinaryNode(T data, BinaryNode<T> *left, BinaryNode<T> *right)
{
    this->data = data;
    this->leftChild = left;
    this->rightChild = right;
}

template <typename T>
BinaryNode<T>::~BinaryNode()
{
    delete leftChild;
    leftChild = nullptr;
    delete rightChild;
    rightChild = nullptr;
}

template <typename T>
T BinaryNode<T>::getData() const
{
    return data;
}

template <typename T>
void BinaryNode<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
BinaryNode<T> *BinaryNode<T>::getLeft() const
{
    return leftChild;
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T> *left)
{
    this->leftChild = left;
}

template <typename T>
BinaryNode<T> *BinaryNode<T>::getRight() const
{
    return rightChild;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T> *right)
{
    this->rightChild = right;
}

template <typename T>
bool BinaryNode<T>::operator==(const BinaryNode<T> &otherBinaryNode) const
{
    return data == otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::operator!=(const BinaryNode<T> &otherBinaryNode) const
{
    return !(otherBinaryNode == *this);
}

template <typename T>
bool BinaryNode<T>::operator<(const BinaryNode<T> &otherBinaryNode) const
{
    return data < otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::operator>(const BinaryNode &otherBinaryNode) const
{
    return data > otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::isLeaf() const
{
    return leftChild == nullptr && rightChild == nullptr;
}

template <typename U>
ostream &operator<<(ostream &os, const BinaryNode<U> &binaryNode)
{
    os << "data: " << binaryNode.data;
    return os;
}

template <typename T>
int getHeight()
{
    if (this->BinaryNode<T> == nullptr)
    {
        return 0; // Altura de un árbol vacío es 0.
    }

    // Calcula la altura de los subárboles izquierdo y derecho.
    int leftHeight = getHeight(root->getLeft());
    int rightHeight = getHeight(root->getRight());

    // La altura del árbol es el máximo entre las alturas de los subárboles izquierdo y derecho,
    // más 1 para contar el nodo actual.
    return 1 + std::max(leftHeight, rightHeight);
}
template <class T>
int BinaryNode<T>::getHeight()
{
    int Height;

    if (this->nodo->esHoja())
    {
        Height = 0;
    }
    else
    {
        int Height_izq = -1;
        int Height_der = -1;

        if (this->nodo->getLeft() != NULL)
            Height_izq = this->altura(this->nodo->getLeft());
        if (this->nodo->getRight() != NULL)
            Height_der = this->altura(this->nodo->getRight());
        if (Height_izq > Height_der)
            Height = Height_izq + 1;
        else
            Height = Height_der + 1;
    }

    return Height;
}
template <class T>
int BinaryNode<T>::getBalance()
{

    return (this->rightChild->getHeight() - this->leftChild->getHeight());
}
template <class T>
void BinaryNode<T>::rotateRight(BinaryNode<T> *n2)
{
    if (n2->getLeft()->getBalance() < 0)
        rotateLeft(n2->getLeft());
    BinaryNode<T> *n1 = n2->getLeft();
    BinaryNode<T> *n_father = n2->getLeft();
    n2->setLeft(n1->getRight());
    n1->setLeft(n2);
}
template <class T>
void BinaryNode<T>::rotateLeft(BinaryNode<T> *n1)
{
    if (n1->getRight()->getBalance() > 0)
        rotateRight(n1->getRight());
    BinaryNode<T> *n2 = n1->getRight();
    BinaryNode<T> *n_father = n1->getRight();
    n1->setRigh(n2->getLeft());
    n2->setRigh(n1);
}