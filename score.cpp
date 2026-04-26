#include "score.h"
#include <fstream>

Score::Score(const std::string& file) : num(0), best(0), fileName(file){
    load();
}

void Score::load(){
    std::ifstream in(fileName);
    if (in) in >> best;
    if (best < 0) best = 0;
}

void Score::add(int n){
    if (n > 0) num += n;
}

int Score::get() const{
    return num;
}

int Score::getBest() const{
    return best;
}

bool Score::saveBest(){
    if (num <= best) return false;
    best = num;
    std::ofstream out(fileName);
    if (out) out << best;
    return true;
}
