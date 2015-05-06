#pragma once

#include "Task.h"

struct TaskArgTS;

class SideBar : public Task<TaskArgTS> {
public:
    SideBar();
    virtual ~SideBar();

    virtual void move(taskarg_sptr  arg);
    virtual void draw(taskarg_sptr  arg);
};
