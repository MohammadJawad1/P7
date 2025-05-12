#pragma once

#include <string>
struct ChessPlayer {
    /**
     * @brief The name of the Chess player
     */
    std::string name_;

    /**
     * @brief The number of wins this player has
     * @pre Must be non-negative (ie. >= 0)
     */
    int wins_;
};