#pragma once

#include "Task.h"

class SideBar : public Task {
public:
    SideBar();
    virtual ~SideBar();

    virtual void move(taskarg_sptr  arg);
    virtual void draw(taskarg_sptr  arg);
};
