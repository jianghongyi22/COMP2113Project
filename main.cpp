#include "game.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

/*int readinput(const std::string& prompt, int minvalue, int maxvalue){
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
} */

bool seekDifficulty(const std::string& text, Difficulty& difficulty){
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
        std::cout << "Invalid difficulty. Please choose easy, medium, hard, or insane.\n";
    }
}

bool readConfig(const std::string& fileName, int& width, int& height, Difficulty& difficulty){
    std::ifstream in(fileName);
    if (!in){
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
    if (!parseDifficulty(difficultyText, difficulty)){
        std::cout << "Invalid difficulty. Please use easy, medium, hard, or insane.\n";
        return false;
    }

int main(int argc, char* argv[]){
    int width = 20;
    int height = 20;
    
    /*std::cout << "Do u want to use default board size 20*20? [Y/N]: ";
    std::string Usedefault;
    std::getline(std::cin,Usedefault);   */

    /*if (Usedefault == "N"){
        width = readinput("Then enter your preferred width (10-30): ", 10, 30);
        height = readinput("And what about your preferred height (10-30): ", 10, 30);
    }
    Difficulty difficulty = readdifficulty();    */

    if (argc < 2){
        std::cout << "Usage: ./snake_game <config_number>\n";
        return 1;
    }

    std::string configFile = std::string(argv[1]) + ".txt";
    if (!readConfig(configFile, width, height, difficulty)){
        return 1;
    }
    
    Game game(width, height, difficulty);
    game.run();
    
    return 0;
}
