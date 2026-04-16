#include "board.h"
#include <iostream>
#include <string>

Board::Board(int width, int height) : width(width), height(height) {}

void Board::render(const Snake& snake, const Apple* normalApple, const Apple* goldenApple) const {
    std::cout << "\033[2J\033[H"; //Screen cleaning
    
    //Print board top
    std::cout << "+"; 
    for (int i = 0; i < width; i++) std::cout << "--";
    std::cout << "+\n";

    //Print middle rows
    for (int i = 0; i < height; i++){
        std::cout << "|";
        for (int j = 0; j < width; j++){
            if (snake.containsPosition(i, j)){
                std::pair<int, int> head = snake.getHeadPosition();
                if (head.first == i && head.second == j) std::cout << " @"; //Print head
                else std::cout << " o"; //Print body
            }
            else if (normalApple != nullptr && normalApple->getRow() == i && normalApple->getCol() == j) std::cout << " *"; //Print * as normal apple
            else if (goldenApple != nullptr && goldenApple->getRow() == i && goldenApple->getCol() == j) std::cout << " #"; //Print # as golden apple
            else std::cout << "  "; //Print empty cell
        }
        std::cout << "|\n";
    }

    //Print board bottom
    std::cout << "+";
    for (int i = 0; i < width; i++) std::cout << "--";
    std::cout << "+\n";
}

bool Board::isInside(int row, int col) const {
    return row >= 0 && row < height && col >= 0 && col < width;
}

int Board::getWidth(){
    return width;
}

int Board::getHeight(){
    return height;
}