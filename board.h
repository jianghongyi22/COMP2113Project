#ifndef BOARD_H
#define BOARD_H

#include "snake.h"
#include "apple.h"

class Board{
    public:
        Board(int width, int height); //Constructor. Input: width, height. Output: None.
        void render(const Snake& snake, const Apple* normalApple, const Apple* goldenApple) const; //Draw the board. Input: snake, apples(pointers). Output: None.
        bool isInside(int row, int col) const; //Check if the position is inside the board. Input: row, column. Output: True if inside, false otherwise.
        int getWidth() const; //Width getter. Input: None. Output: width.
        int getHeight() const; //Height getter. Input: None. Output: height.
    private:
        int width;
        int height;
};

#endif