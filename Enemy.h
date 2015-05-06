#pragma once

#include "Object.h"

class Enemy : public Object
{
public:
    typedef typename Task<TaskArgTS>::taskarg_sptr taskarg_sptr;
    
    Enemy(int x, int y, int mx, int my);
    virtual ~Enemy();

    virtual void move(taskarg_sptr arg) override;
    virtual void draw(taskarg_sptr arg) override;

private:
    int shot_interval_;
    int move_interval_;
};
