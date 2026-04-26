#ifndef INPUT_H
#define INPUT_H

enum class Key {UP, DOWN, LEFT, RIGHT, NONE, QUIT, PAUSE};

class Input{
    public:
        Input(); //Constructor
        ~Input(); //Destructor

        Key getKeyPress(); //Receive keyboard input
        void enableRawMode(); //Enable terminal raw mode
        void disableRawMode(); //Disable terminal raw mode

    private:
        bool rawModeEnabled;
        int originalTermios; //For restoration
        int originalFlags; //For restoration
};

#endif
