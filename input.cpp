#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <iostream>

Input::Input() : rawModeEnabled(false), originalTermios(0), originalFlags(0){
    enableRawMode();
}

Input::~Input(){
    disableRawMode();
}

Key Input::getKeyPress(){
    char buf[3] = {0};
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    // Error handling
    if (n == -1){
        if (errno == EAGAIN || errno == EWOULDBLOCK){
            return Key::NONE;
        }
        return Key::NONE;
    }
    if (n <= 0) return Key::NONE;
    //Read arrow or quit
    if (buf[0] == '\x1b' && buf[1] == '['){
        switch (buf[2]){
            case 'A': return Key::UP;
            case 'B': return Key::DOWN;
            case 'C': return Key::RIGHT;
            case 'D': return Key::LEFT;
        }
    }
    else if (buf[0] == 'q' || buf[0] == 'Q'){
        return Key::QUIT;
    }
    return Key::NONE;
}

void Input::enableRawMode(){
    if (rawModeEnabled) return;
    //Change to raw mode
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    originalTermios = raw.c_lflag;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    //Start non-blocking mode
    originalFlags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, originalFlags | O_NONBLOCK);
    
    rawModeEnabled = true;
}

void Input::disableRawMode(){
    if (!rawModeEnabled) return;
    //Restore original configs
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag = originalTermios;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    fcntl(STDIN_FILENO, F_SETFL, originalFlags);

    rawModeEnabled = false;
}