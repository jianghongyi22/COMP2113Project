#ifndef APPLE_H
#define APPLE_H

enum class AppleType {NORMAL, GOLDEN}; //Two types of apple

class Apple{
    public:
        Apple(int row, int col, AppleType type, int spawnTurn); //Constructor

        int getRow() const;
        int getCol() const;
        AppleType getType() const;
        int getPoints(int currentTurn) const; //Calculate golden apple points
        bool isExpired(int currentTurn) const; //Check if apple expired (normal apple included)
        void setSpawnTurn(int turn); //Set turn as spawnTurn 
        int getSpawnTurn() const;

    private:
        AppleType type;
        int row;
        int col;
        int spawnTurn;
};

#endif