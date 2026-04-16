#ifndef BOARD_H
#define BOARD_H

#include "snake.h"
#include "apple.h"

class Board{
    public:
        Board(int width, int height);
        void render(const Snake& snake, const Apple* normalApple, const Apple* goldenApple) const;
        bool isInside(int row, int col) const;
        int getWidth();
        int getHeight();
    private:
        int width;
        int height;
};

#endif