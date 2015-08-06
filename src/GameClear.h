#pragma once

#include "Task.h"

struct TaskArgTS;

class GameClear : public Task<TaskArgTS> {
public:
    GameClear(taskarg_sptr arg);
    virtual ~GameClear();
    
    virtual void move(taskarg_sptr arg);    
    virtual void draw(taskarg_sptr arg);
};

