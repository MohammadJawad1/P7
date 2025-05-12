#include "Node.hpp"

/**
 * @brief Parameterized Node Constructor
 *
 * @param value The value to store in this Node
 * @param left Pointer to the left child (nullptr by default)
 * @param right Pointer to the right child (nullptr by default)
 */
template <class T>
Node<T>::Node(const T& value, Node* left, Node* right)
    : value_(value)
    , left_(left)
    , right_(right)
{
}

/**
 * @brief Getter for the value_ member,
 * ie. returns the value stored by this Node
 */
template <class T>
T Node<T>::getValue() const
{
    return value_;
}

/**
 * @brief Getter for this Node's `left_` member.
 * @return Returns a pointer to this Node's left child
 * or nullptr if none exists
 */
template <class T>
Node<T>* Node<T>::getLeftChild() const
{
    return left_;
}

/**
 * @brief Getter for this Node's `right_` member.
 * @return Returns a pointer to this Node's right child
 * or nullptr if none exists
 */
template <class T>
Node<T>* Node<T>::getRightChild() const
{
    return right_;
}

/**
 * @brief Setter for this Node's `left_` member.
 * @param newChild A pointer to a Node to become the new
 * left child of this Node
 */
template <class T>
void Node<T>::setLeftChild(Node<T>* newChild)
{
    left_ = newChild;
}

/**
 * @brief Setter for this Node's `right_` member.
 * @param newChild A pointer to a Node to become the new
 * right child of this Node
 */
template <class T>
void Node<T>::setRightChild(Node<T>* newChild)
{
    right_ = newChild;
}

/**
 * @brief Setter for this Node's `value_` member.
 * @param value The new value for this Node to contain
 */
template <class T>
void Node<T>::setValue(const T& value)
{
    value_ = value;
}