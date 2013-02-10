#pragma once

#include "Task.h"

class Object : public Task 
{
public:
    Object()
    {}
	
    virtual ~Object()
    {}

    int get_x() const
    {
        return x_;
    }

    int get_y() const
    {
        return y_;
    }
	
    int get_sx() const
    {
        return sx_;
    }

    int get_hsx() const
    {
        return sx_/2;
    }

    int get_sy() const
    {
        return sy_;
    }

    int get_hsy() const
    {
        return sy_/2;
    }

protected:
    int x_;
    int y_;
    int mx_;
    int my_;
    int sx_;
    int sy_;
};
