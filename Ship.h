#pragma once

#include "Object.h"

class Ship : public Object
{
public:
    Ship();
    virtual ~Ship();
    
    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);

private:
    int shot_interval_;
};
