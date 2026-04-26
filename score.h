#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score{
    public:
        Score(const std::string& file = "highscore.txt");
        void add(int n);
        int get() const;
        int getBest() const;
        bool saveBest();

    private:
        int num;
        int best;
        std::string fileName;
        void load();
};

#endif
