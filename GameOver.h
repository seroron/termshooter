#pragma once

#include "Task.h"

class GameOver : public Task {
public:
    GameOver();
    virtual ~GameOver();
    
    virtual void move(taskarg_sptr arg);    
    virtual void draw(taskarg_sptr arg);
};

