#include "file_output.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace utils {
    void updateHighestScores(const std::string& filename, int score) {
        std::vector<int> scores = readHighestScores(filename);
        scores.push_back(score);
        // sort in descending order
        std::sort(scores.begin(), scores.end(), std::greater<int>());
        // keep only top 5
        if (scores.size() > 5) {
            scores.resize(5);
        }

        std::ofstream file(filename);
        if (!file.is_open()) {
            return;
        }

        for (int s : scores) {
            file << s << std::endl;
        }
        file.close();
    }

    std::vector<int> readHighestScores(const std::string& filename) {
        std::vector<int> scores;
        std::ifstream file(filename);
        if (!file.is_open()) {
            return scores;
        }

        std::string line;
        int count = 0;
        while (std::getline(file, line) && count < 5) {
            try {
                int score = std::stoi(line);
                scores.push_back(score);
                ++count;
            } catch (const std::exception&) {
                // ignore invalid lines
            }
        }

        file.close();
        // sort in descending order
        std::sort(scores.begin(), scores.end(), std::greater<int>());
        return scores;
    }
}