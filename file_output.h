#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H
#include <string>
#include <vector>

namespace utils {
    void updateHighestScores(const std::string& filename, int score);
    std::vector<int> readHighestScores(const std::string& filename);
}

#endif