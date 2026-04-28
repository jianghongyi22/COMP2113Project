#ifndef INPUT_H
#define INPUT_H

enum class Key {UP, DOWN, LEFT, RIGHT, NONE, QUIT, PAUSE};

class Input{
    public:
        Input(); //Constructor
        ~Input(); //Destructor

        Key getKeyPress(); //Receive keyboard input. Input: None. Output: the key pressed.
        void enableRawMode(); //Enable terminal raw mode. Input: None. Output: None.
        void disableRawMode(); //Disable terminal raw mode. Input: None. Output: None.

    private:
        bool rawModeEnabled; //Flag.
        int originalTermios; //For restoration.
        int originalFlags; //For restoration.
};

#endif
