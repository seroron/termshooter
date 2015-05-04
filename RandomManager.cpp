#include "RandomManager.h"

RandomManager::RandomManager() {
    
    std::random_device rnd;
    mt_.seed(rnd());
}

RandomManager::~RandomManager() {
}

RandomManager& RandomManager::getInst() {
    static RandomManager inst;
    return inst;
}

