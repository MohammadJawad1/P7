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

/**
 * @brief Default constructor; constructs an empty BST
 * @post The `root_` is set to nullptr & `size_` to 0.
 */

PlayerBST::PlayerBST() : root_(nullptr), size_(0) {}

/**
 * @brief Getter for the `root_` member
 * @returns The a pointer to the root of the PlayerBST, 
 * or nullptr if the tree is empty.
 */

Node<ChessPlayer>* PlayerBST::getRoot() const
{
    return root_;
}

/**
 * @brief Getter for the `size_` member
 * @returns The number of Players (ie. nodes) 
 * in the PlayerBST as an integer
 */

int PlayerBST::size() const
{
    return size_;
}
/**
 * @brief Searches for a Player in the PlayerBST
 * with the specified name.
 *
 * @param value A const reference to a STRING representing
 * the name of the Player to search for.
 * @returns True if the player exists in the BST. False otherwise.
 */

bool PlayerBST::contains(const std::string& name)
{
    // Start with the root and traverse down
    Node<ChessPlayer>* current = root_;
    while (current != nullptr) {
        // If the player is found, return true
        if (name == current->getValue().name_) {
            return true;
        }

        // If the name is smaller, go left
        if (name < current->getValue().name_) {
            current = current->getLeftChild();
        } 
        // If the name is larger, go right
        else {
            current = current->getRightChild();
        }
    }

    // Player not found, return false
    return false;
}



bool PlayerBST::insert(const ChessPlayer& value)
{
    // If the tree is empty, create the root
    if (root_ == nullptr) {
        root_ = new Node<ChessPlayer>(value);
        size_++;
        return true;
    }

    // Start with the root and traverse down
    Node<ChessPlayer>* current = root_;
    while (current != nullptr) {
        // If the player already exists, return false
        if (value.name_ == current->getValue().name_) {
            return false;
        }

        // If the value is smaller, go left
        if (value.name_ < current->getValue().name_) {
            if (current->getLeftChild() == nullptr) {
                current->setLeftChild(new Node<ChessPlayer>(value));
                size_++;
                return true;
            } else {
                current = current->getLeftChild();
            }
        } 
        // If the value is larger, go right
        else {
            if (current->getRightChild() == nullptr) {
                current->setRightChild(new Node<ChessPlayer>(value));
                size_++;
                return true;
            } else {
                current = current->getRightChild();
            }
        }
    }

    return false;  // This line should never be reached
}

/**
 * @brief Calculates the average number of wins
 * across all Players in the PlayerBST, rounded
 * to at second decimal place (eg. 1.00, 2.50, 3.14 etc.)
 *
 * @returns The average number of wins or 0.0
 * if the BST is empty, as a double
 */
double PlayerBST::averageWins()
{
    if (size_ == 0) {
        return 0.0;
    }

    int totalWins = averageWinsHelper(root_);
    double average = static_cast<double>(totalWins) / size_;

    // Round to 2 decimal places
    return std::round(average * 100.0) / 100.0;
}


int PlayerBST::averageWinsHelper(Node<ChessPlayer>* node)
{
    if (!node) {
        return 0;
    }

    int leftSum = averageWinsHelper(node->getLeftChild());
    int rightSum = averageWinsHelper(node->getRightChild());

    return leftSum + rightSum + node->getValue().wins_;
}

int PlayerBST::countAboveWins(const int& min_wins)
{
    return countAboveWinsHelper(root_, min_wins);
}

int PlayerBST::countAboveWinsHelper(Node<ChessPlayer>* node, const int& min_wins)
{
    if (!node) {
        return 0;
    }

    int count = 0;
    if (node->getValue().wins_ >= min_wins) {
        count = 1;
    }

    return count + countAboveWinsHelper(node->getLeftChild(), min_wins) + countAboveWinsHelper(node->getRightChild(), min_wins);
}

std::vector<ChessPlayer> PlayerBST::toVector(const TraversalType& traversal)
{
    std::vector<ChessPlayer> result;

    switch (traversal) {
        case IN_ORDER:
            toVectorInOrder(root_, result);
            break;
        case PRE_ORDER:
            toVectorPreOrder(root_, result);
            break;
        case POST_ORDER:
            toVectorPostOrder(root_, result);
            break;
    }

    return result;
}

void PlayerBST::toVectorInOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec)
{
    if (!node) return;

    toVectorInOrder(node->getLeftChild(), vec);
    vec.push_back(node->getValue());
    toVectorInOrder(node->getRightChild(), vec);
}

void PlayerBST::toVectorPreOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec)
{
    if (!node) return;

    vec.push_back(node->getValue());
    toVectorPreOrder(node->getLeftChild(), vec);
    toVectorPreOrder(node->getRightChild(), vec);
}

void PlayerBST::toVectorPostOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec)
{
    if (!node) return;

    toVectorPostOrder(node->getLeftChild(), vec);
    toVectorPostOrder(node->getRightChild(), vec);
    vec.push_back(node->getValue());
}