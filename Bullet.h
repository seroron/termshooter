#pragma once

#include <string>
#include "Object.h"

class Bullet : public Object
{
public:
    Bullet(int x, int y, int mx, int my, std::string aa);
    virtual ~Bullet();

    virtual void move(taskarg_sptr arg);
    virtual void draw(taskarg_sptr arg);
	
private:
    std::string aa_;
};
