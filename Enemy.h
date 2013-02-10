#pragma once

#include "Object.h"

class Enemy : public Object
{
public:
    Enemy(int x, int y, int mx, int my);
    virtual ~Enemy();

    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);

private:
    int shot_interval_;
    int move_interval_;
};
