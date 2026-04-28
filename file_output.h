#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H
#include <string>
#include <vector>

namespace utils {
    void updateHighestScores(const std::string& filename, int score); //Update highest scores in txt file. Input: file name, score. Output: None.
    std::vector<int> readHighestScores(const std::string& filename); //Read highest scores from txt file. Input: filename. Output: a vector of sorted highest scores.
}

#endif