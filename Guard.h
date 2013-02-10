#pragma once

#include "Object.h"

class Guard : public Object
{
public:
    Guard(int x, int y);
    virtual ~Guard();
    
    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);

private:
};
