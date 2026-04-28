#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Snake{
    public:
        Snake(int startRow, int startCol, Direction startDir = Direction::RIGHT); //Constructor. Input: row, column, direction. Output: None.

        void move(); //Move 1 unit. Input: None. Output: None.
        void grow(); //Set pendingGrowth to true if apple eaten. Input: None. Output: None.
        void changeDirection(Direction newDir); //Change the direction, avoid 180 degrees turn. Input: new direction. Output: None.
        bool collidesWithSelf() const; //Check if collide with the snake itself. Input: None. Output: True if collide with self, false otherwise.
        bool containsPosition(int row, int col) const; //Check if the snake contains a certain position. Input: row, column. Output: true if contained, false otherwise.
        std::pair<int, int> getHeadPosition() const; //Head getter. Input: None. Output: paired integers representing head position.
        const std::vector<std::pair<int, int>>& getSegments() const; //Segments getter. Input: None. Output: a vector containing positions of the snake body.
        Direction getDirection() const; //Direction getter. Input: None. Output: direction.
        int getLength() const; //Length getter. Input: None. Output: snake length.

    private:
        Direction direction;
        bool pendingGrowth;
        std::vector<std::pair<int, int>> segments;
};

#endif