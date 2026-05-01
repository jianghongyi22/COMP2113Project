#include "game.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Difficulty seekDifficulty(const std::string& choice){
        if (choice == "easy"){
             return Difficulty::EASY;
        }
        if (choice == "medium"){
             return Difficulty::MEDIUM;
        }
        if (choice == "hard"){
             return Difficulty::HARD;
        }
        if (choice == "insane"){
             return Difficulty::INSANE;
        }
        else return Difficulty::INVALID;
    }


bool readConfig(const std::string& fileName, int& width, int& height, Difficulty &difficulty){
    std::ifstream in;
    in.open(fileName);
    if (in.fail()){
          std::cout << "Cannot open config file: " << fileName << "\n";
        return false;
    }

    std::string difficultyText;
    if (!(in >> width >> height)){
        std::cout << "Invalid config file. First line should be: width height\n";
        return false;
    }
    if (!(in >> difficultyText)){
        std::cout << "Invalid config file. Second line should be difficulty.\n";
        return false;
    }
    if (width < 10 || width > 30 || height < 10 || height > 30){
        std::cout << "Invalid board size. Width and height should be from 10 to 30.\n";
        return false;
    }
    if (seekDifficulty(difficultyText) == Difficulty::INVALID){
        std::cout << "Invalid difficulty. Please use easy, medium, hard, or insane.\n";
        return false;
    }
    difficulty = seekDifficulty(difficultyText);
    in.close();
    return true;
}

int main(){
    int width = 20;
    int height = 20;
    Difficulty difficulty;
    
    if (!readConfig("input.txt", width, height, difficulty)){
        return 1;
    }
    Game game(width, height, difficulty);
    game.run();
    
    return 0;
}
