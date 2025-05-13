//Mohammad Jawad
//may 13
//The header for the helper functions and the main functions

#pragma once
#include "ChessPlayer.hpp"
#include "Node.hpp"

#include <string>
#include <vector>
#include <cmath>

enum TraversalType {
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};

/**
 * @brief The interface for a PlayerBST,
 * describing a BST ordered by the names
 * of ChessPlayer objects
 */
class PlayerBST {
protected:
    Node<ChessPlayer>* root_;
    int size_;

private:
    /**
     * @brief Helper function to delete node recursively.
     *
     * @param node Current subroot
     * @param value The name of the Player to delete
     * @return Updated node pointer
     */
    Node<ChessPlayer>* removeHelper(Node<ChessPlayer>* node, const std::string& name);

    /**
     * Deletes all nodes in the tree recursively.
     * @param node Current node to delete
     */
    void destroyTree(Node<ChessPlayer>* node);

public:



    /**
     * @brief Destructor to clean up all nodes.
     */
    ~PlayerBST();




    /**
     * @brief Removes a Player from the PlayerBST
     * if a player with their name exists.
     *
     * @param value A const reference a string representing
     * the name of the Player to be removed.
     * @returns True if the player was successfully removed. False otherwise.
     * @post Decrements `size_` if the player was removed.
     */
    bool remove(const std::string& name);

    // Define your function signatures below ========
    /**
     * @brief Default constructor; constructs an empty BST
     * @post The `root_` is set to nullptr & `size_` to 0.
     */
    PlayerBST();

    /**
     * @brief Getter for the `root_` member
     * @returns The a pointer to the root of the PlayerBST, 
     * or nullptr if the tree is empty.
     */
    Node<ChessPlayer>* getRoot() const;

    /**
     * @brief Getter for the `size_` member
     * @returns The number of Players (ie. nodes) 
     * in the PlayerBST as an integer
     */
    int size() const;

    /**
     * @brief Searches for a Player in the PlayerBST
     * with the specified name.
     *
     * @param value A const reference to a STRING representing
     * the name of the Player to search for.
     * @returns True if the player exists in the BST. False otherwise.
     */
    bool contains(const std::string& value);

    /**
     * @brief Inserts a Player into the PlayerBST
     * if a player with their name does NOT already exist.
     *
     * @param value A const. reference to the ChessPlayer to insert
     * @returns True if the player was sucessfully inserted. False otherwise.
     * @post Increments the BST's size if the value was succesfully inserted
     */
    bool insert(const ChessPlayer& value);

    /**
     * @brief Calculates the average number of wins
     * across all Players in the PlayerBST, rounded
     * to at second decimal place (eg. 1.00, 2.50, 3.14 etc.)
     *
     * @returns The average number of wins or 0.0
     * if the BST is empty, as a double
     */
    double averageWins();
    /**
     * @brief Recursively calculates the number of wins in the subtree
     * 
     * @param node Pointer to the current node in the tree.
     * @return Total wins gathered from the current subtree.
     */
    int averageWinsHelper(Node<ChessPlayer>* node);

    /**
    * @brief Counts the number of Players in the BST with
    * greater than or equal to the specified minimum number of wins.
    *
    * @param min_wins A const reference to an integer
    * denoting the minimum number of wins to check against
    * @returns The count of players with wins >= min_wins
    * as an integer
    */
    int countAboveWins(const int& min_wins);

    /**
     * @brief Recursively counts the number of players with wins 
     * 
     * @param node Pointer to the current node in the BST.
     * @param min_wins A const reference to an integer  denoting the minimum number of wins required to be counted.
     * @return Number of players in the subtree with wins >= min_wins.
     */
    int countAboveWinsHelper(Node<ChessPlayer>* node, const int& min_wins);

    /**
     * @brief Creates a vector of all ChessPlayers in the BST
     * using the specified traversal order.
     *
     * @param traversal A const reference to the traversal type
     * (ie. IN_ORDER, PRE_ORDER, POST_ORDER)
     * @returns A vector containing all ChessPlayers in the PlayerBST 
     * read in the specified traversal order.
     */
    std::vector<ChessPlayer> toVector(const TraversalType& traversal);

    /**
     * @brief Performs in-order traversal of the BST and stores players in a vector.
     * @param node a pointer to the current node being visited.
     * @param vec a reference to a vector to store ChessPlayer objects in in-order sequence.
     * @details In-order traversal visits left subtree, current node, then right subtree.
     */
    void toVectorInOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec);

    /**
     * @brief Performs pre-order traversal of the BST and stores players in a vector.
     * 
     * @param node a pointer to current node being visited.
     * @param vec a reference to a vector to store ChessPlayer objects in pre-order sequence.
     * @details Pre-order traversal visits current node, then left and right subtrees.
     */
    void toVectorPreOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec);

    /**
     * @brief Performs post-order traversal of the BST and stores players in a vector.
     * 
     * @param node a pointer to node being visited.
     * @param vec a reference to a vector to store ChessPlayer objects in post-order sequence.
     * @details Post-order traversal visits left and right subtrees, then the current node.
     */
    void toVectorPostOrder(Node<ChessPlayer>* node, std::vector<ChessPlayer>& vec);



};