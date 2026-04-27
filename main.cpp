#include "game.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int readinput(const std::string& prompt, int minvalue, int maxvalue){
    while (true){
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        int value;
        char extra;

        if (ss >> value && !(ss >> extra) && value >= minvalue && value <= maxvalue){
            return value;
        }

        std::cout << "Please enter an integer from "
                  << minvalue << " to " << maxvalue << ".\n";
    }
}

Difficulty readdifficulty(){
    while (true){
        std::cout << "Choose difficulty [easy / medium / hard / insane] ";
        std::string choice;
        std::getline(std::cin, choice);
        if (choice == "medium"){
             return Difficulty::MEDIUM;
        }
        if (choice == "hard"){
             return Difficulty::MEDIUM;
        }
        if (choice == "insane"){
             return Difficulty::INSANE;
        }
        std::cout << "Invalid difficulty. Please choose easy, medium, hard, or insane.\n";
    }
}


int main(){
    int width = 20;
    int height = 20;
    std::cout << "Do u want to use default board size 20*20? [Y/N]: ";
    std::Usedefault;
    std::getline(std::cin,Usedefault);

    if (Usedefault == "N"){
        width = readinput("Then enter your preferred width (10-30): ", 10, 30);
        height = readinput("And what about your preferred height (10-30): ", 10, 30);
    }
    Difficulty difficulty = readdifficulty();
    
    Game game(width, height, difficulty);
    game.run();
    
    return 0;
}
