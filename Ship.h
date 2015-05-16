#pragma once

#include "Object.h"

class Ship : public Object
{
public:
    Ship();
    virtual ~Ship();
    
    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);

    int get_life() const {
        return life_;
    }
    
    void damage();
    
private:
    int shot_interval_;
    int life_;
    int damaged_cnt_;
};
