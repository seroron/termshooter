#pragma once

#include "Task.h"
//#include "TaskArgTS.h"

struct TaskArgTS;

class Object : public Task<TaskArgTS> {
public:
    Object()
    {}
	
    virtual ~Object()
    {}

    int get_x() const {
        return x_;
    }

    int get_y() const {
        return y_;
    }
	
    int get_sx() const {
        return sx_;
    }

    int get_sy() const {
        return sy_;
    }

    bool check_collision(const Object& rhs) const {
        return
            x_       < rhs.x_ + rhs.sx_ &&
            x_ + sx_ > rhs.x_ &&
            y_       < rhs.y_ + rhs.sy_ &&
            y_ + sy_ > rhs.y_;
    }

protected:
    int x_;
    int y_;
    int mx_;
    int my_;
    int sx_;
    int sy_;
};
