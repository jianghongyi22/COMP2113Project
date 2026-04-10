#include "apple.h"

Apple::Apple(int row, int col, AppleType type)
    : row(row), col(col), type(type), spawnTurn(0) {}

int Apple::getRow() const {
    return row;
}

int Apple::getCol() const {
    return col;
}

AppleType Apple::getType() const {
    return type;
}

int Apple::getPoints(int currentTurn) const {
    int turnPassed = currentTurn - spawnTurn;
    int point = 12 - turnPassed / 5 * 2;
    if (point > 0) return point;
    else return 0;
}

bool Apple::isExpired(int currentTurn) const {
    if (type == AppleType::NORMAL) return false;
    int turnPassed = currentTurn - spawnTurn;
    if (turnPassed < 30) return false;
    else return true;
}

void Apple::setSpawnTurn(int turn){
    spawnTurn = turn;
}

int Apple::getSpawnTurn() const {
    return spawnTurn;
}