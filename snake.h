#ifndef SNAKE_H
#define SNAKE_H

#include <vector>;

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Snake{
    public:
        Snake(int startRow, int startCol, Direction startDir = Direction::RIGHT); //Constructor

        void move(); //Move 1 unit
        void grow(); //Set pendingGrowth to true if apple eaten
        void changeDirection(Direction newDir); //Avoid 180 degrees turn
        bool collidesWithSelf() const;
        bool containsPosition(int row, int col) const;
        std::pair<int, int> getHeadPosition() const;
        const std::vector<std::pair<int, int>>& getSegments() const;
        Direction getDirection() const;
        int getLength() const;

    private:
        Direction direction;
        bool pendingGrowth;
        std::vector<std::pair<int, int>> segments;
};






#endif