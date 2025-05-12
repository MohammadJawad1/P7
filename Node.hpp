#pragma once

template <class T>
class Node {
private:
    T value_; // The value stored within the node
    Node* left_; // A pointer to this Node's left child
    Node* right_; // A pointer to this Node's right child

public:
    /**
     * @brief Parameterized Node Constructor
     *
     * @param value The value to store in this Node
     * @param left Pointer to the left child (nullptr by default)
     * @param right Pointer to the right child (nullptr by default)
     */
    Node(const T& value, Node* left = nullptr, Node* right = nullptr);

    /**
     * @brief Getter for this Node's `value_` member,
     * ie. returns the value stored by this Node
     */
    T getValue() const;

    /**
     * @brief Getter for this Node's `left_` member.
     * @return Returns a pointer to this Node's left child
     * or nullptr if none exists
     */
    Node* getLeftChild() const;

    /**
     * @brief Getter for this Node's `right_` member.
     * @return Returns a pointer to this Node's right child
     * or nullptr if none exists
     */
    Node* getRightChild() const;

    /**
     * @brief Setter for this Node's `left_` member.
     * @param newChild A pointer to a Node to become the new
     * left child of this Node
     */
    void setLeftChild(Node<T>* newChild);

    /**
     * @brief Setter for this Node's `right_` member.
     * @param newChild A pointer to a Node to become the new
     * right child of this Node
     */
    void setRightChild(Node<T>* newChild);

    /**
     * @brief Setter for this Node's `value_` member.
     * @param value The new value for this Node to contain
     */
    void setValue(const T& value);
};

#include "Node.cpp"