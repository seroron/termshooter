#pragma once

#include "TaskArgTS.h"

class TermShooter {
public:
    TermShooter();
    ~TermShooter();

    void start();

private:
    bool move(taskarg_sptr arg);
    bool draw(taskarg_sptr arg, float fps);
};
