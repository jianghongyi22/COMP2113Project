#include "snake.h"
#include <algorithm>

Snake::Snake(int startRow, int startCol, Direction startDir)
    :direction(startDir), pendingGrowth(false){
    segments.push_back({startRow, startCol});
    if (startDir == Direction::UP){
        segments.push_back({startRow + 1, startCol});
        segments.push_back({startRow + 2, startCol});
    }
    else if (startDir == Direction::DOWN){
        segments.push_back({startRow - 1, startCol});
        segments.push_back({startRow - 2, startCol});
    }
    else if (startDir == Direction::RIGHT){
        segments.push_back({startRow, startCol - 1});
        segments.push_back({startRow, startCol - 2});
    }
    else{
        segments.push_back({startRow, startCol + 1});
        segments.push_back({startRow, startCol + 2});
    }
}

void Snake::move(){
    std::pair<int, int> head = segments.front();
    int newRow = head.first;
    int newCol = head.second;
    switch (direction){
        case Direction::UP: newRow--; break;
        case Direction::DOWN: newRow++; break;
        case Direction::LEFT: newCol--; break;
        case Direction::RIGHT: newCol++; break;
    }
    segments.insert(segments.begin(),{newRow, newCol});
    if (pendingGrowth == false) segments.pop_back();
    else pendingGrowth = false;
}

void Snake::grow(){
    pendingGrowth = true;
}

void Snake::changeDirection(Direction newDir){
    if ((direction == Direction::UP && newDir == Direction::DOWN) ||
        (direction == Direction::DOWN && newDir == Direction::UP) ||
        (direction == Direction::LEFT && newDir == Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDir == Direction::LEFT)) return; //No 180 degrees turn
    direction = newDir;
}

bool Snake::collidesWithSelf() const {
    std::pair<int, int> head = segments.front();
    return std::find(segments.begin() + 1, segments.end(), head) != segments.end();
}

bool Snake::containsPosition(int row, int col) const {
    std::pair<int, int> pos = {row, col};
    return std::find(segments.begin(), segments.end(), pos) != segments.end();
}

std::pair<int, int> Snake::getHeadPosition() const {
    return segments.front();
}

const std::vector<std::pair<int, int>>& Snake::getSegments() const {
    return segments;
}

Direction Snake::getDirection() const {
    return direction;
}

int Snake::getLength() const {
    return segments.size();
}