#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "snake.h"
#include "apple.h"
#include "input.h"
#include "score.h"
#include <random>

enum class Difficulty {EASY, MEDIUM, HARD, INSANE, INVALID};

class Game{
    public:
        Game(int w, int h, Difficulty selectdifficulty);
        ~Game();
        void run();

    private:
        Board board;
        Snake snake;
        Input input;
        Score score;
        Apple* apple;
        Apple* gold;
        Difficulty difficulty;
        int turn;
        int eaten;
        bool stop;
        bool pause;
        bool win;
        bool quit;
        std::mt19937 rng;

        void keyWork(Key k);
        void step();
        void draw() const;
        void newApple(AppleType type);
        bool same(int r, int c, const Apple* a) const;
        bool freeCell(int r, int c) const;
        int delay() const;
        const char* difficultyName() const;
        void endText();
};

#endif
