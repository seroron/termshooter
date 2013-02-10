#pragma once

#include "Task.h"

class Field : public Task {
public:
    static const int FIELD_X_MIN       = 2;
    static const int FIELD_X_MAX       = 60;
    static const int FIELD_Y_MIN       = 2;
    static const int FIELD_Y_MAX       = 33;

    static const int GUARD_LINE_MIN = 27;
    static const int GUARD_LINE_MAX = 28;

    static const int PLAYER_LINE = 30;

    Field();
    virtual ~Field();
    
    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);
};
