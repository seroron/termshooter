#pragma once

#include "TaskArgTS.h"

class TermShooter {
public:
    TermShooter();
    ~TermShooter();

    void start();
    
    bool is_reset() const {
        return reset_;
    }
    
private:
    void setup_game();
    
    bool move(taskargts_sptr arg);
    bool draw(taskargts_sptr arg, float fps);

    bool reset_;
};
