#pragma once

#include "Task.h"

struct TaskArgTS;

class GameOver : public Task<TaskArgTS> {
public:
    GameOver(taskarg_sptr arg);
    virtual ~GameOver();
    
    virtual void move(taskarg_sptr arg);    
    virtual void draw(taskarg_sptr arg);
};

