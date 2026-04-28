#ifndef APPLE_H
#define APPLE_H

enum class AppleType {NORMAL, GOLDEN}; //Two types of apple

class Apple{
    public:
        Apple(int row, int col, AppleType type = AppleType::NORMAL); //Constructor. Input: row, column, apple type. Output: None.

        int getRow() const; //Row getter. Input: None. Output: row.
        int getCol() const; //Column getter. Input: None. Output: column.
        AppleType getType() const; //Type getter. Input: None. Output: type.
        int getPoints(int currentTurn) const; //Calculate apple points. Input: current turn. Output: points.
        bool isExpired(int currentTurn) const; //Check if apple expired (normal apple included). Input: current turn. Output: True if expired, false otherwise.
        void setSpawnTurn(int turn); //Set turn as spawnTurn. Input: turn. Output: None.
        int getSpawnTurn() const; //Spawn turn getter. Input: None. Output: spawn turn.

    private:
        AppleType type;
        int row;
        int col;
        int spawnTurn;
};

#endif