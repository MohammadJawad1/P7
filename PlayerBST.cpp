#include "PlayerBST.hpp"

/**
 * @brief Destructor to clean up all nodes.
 */
PlayerBST::~PlayerBST()
{
    destroyTree(root_);
}

void PlayerBST::destroyTree(Node<ChessPlayer>* node)
{
    if (!node) {
        return;
    }

    destroyTree(node->getLeftChild());
    destroyTree(node->getRightChild());
    delete node;
    node = nullptr;
}

Node<ChessPlayer>* PlayerBST::removeHelper(Node<ChessPlayer>* node, const std::string& name)
{
    if (!node) {
        return nullptr;
    }

    // Traverse the tree to find the node to delete
    if (name < node->getValue().name_) {
        node->setLeftChild(removeHelper(node->getLeftChild(), name));
        return node;
    } else if (name > node->getValue().name_) {
        node->setRightChild(removeHelper(node->getRightChild(), name));
        return node;
    }
    // Node found, handle deletion

    // Case 1: Node with no children (leaf node)
    if (!node->getLeftChild() && !node->getRightChild()) {
        delete node;
        size_--;
        return nullptr;
    }
    // Case 2: Node with only one child
    else if (!node->getLeftChild()) {
        Node<ChessPlayer>* temp = node->getRightChild();
        delete node;
        size_--;
        return temp;
    } else if (node->getRightChild() == nullptr) {
        Node<ChessPlayer>* temp = node->getLeftChild();
        delete node;
        size_--;
        return temp;
    }

    // Case 3: Node with two children
    // Find the inorder successor (smallest node in right subtree)
    Node<ChessPlayer>* successor = node->getRightChild();
    while (successor->getLeftChild() != nullptr) {
        successor = successor->getLeftChild();
    }

    // Copy the successor's value to this node
    node->setValue(successor->getValue());

    // Delete the now-duplicate successor
    node->setRightChild(removeHelper(node->getRightChild(), successor->getValue().name_));

    return node;
}

bool PlayerBST::remove(const std::string& name)
{
    int oldSize = size_;
    root_ = removeHelper(root_, name);
    // If size changed, removal was successful
    return oldSize > size_;
}

// ====== Your code below ======

PlayerBST::PlayerBST() : root_(nullptr), size_(0){}

Node<ChessPlayer>* PlayerBST::getRoot() const
{
    return root_;
}

int PlayerBST::size() const
{
    return size_;
}

bool PlayerBST::contains(const std::string& name)
{
    return false;
}

bool PlayerBST::insert(const ChessPlayer& insert)
{
    return false;
}

int PlayerBST::countAboveWins(const int& wins)
{
    return 0;
}

std::vector<ChessPlayer> PlayerBST::toVector(const TraversalType& order)
{
    std::vector<ChessPlayer> tree;
    return tree;
}