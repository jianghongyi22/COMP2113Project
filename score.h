#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score{
    public:
        Score(const std::string& file = "record.txt");
        void add(int n);
        int get() const;
        int getBest() const;

    private:
        int num;
        int best;
        std::string fileName;
        void load();
};

#endif
