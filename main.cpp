#include "game.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>



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
