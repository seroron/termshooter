#pragma once

#include <random>

class RandomManager {
public:

    static RandomManager& getInst();

    std::mt19937& getMT() {
        return mt_;
    }
    
    int getUniformInt(int s, int e) {
        return std::uniform_int_distribution<>(s, e)(mt_);
    }
    
private:
    RandomManager();
    ~RandomManager();

    std::mt19937 mt_;
};
