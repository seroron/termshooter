#pragma once

#include <memory>

struct TaskArg {
};

typedef std::shared_ptr<TaskArg> taskarg_sptr;

class Task {
public:
    // Task(int priority) : 
    //     dead_(false), priority_(priority) {
    // }

    Task() : 
        dead_(false), movable_(true), drawable_(true) {
    }
  
    virtual ~Task() {
    }
	
    virtual void move(taskarg_sptr arg) {
    }
	
    virtual void draw(taskarg_sptr arg) {
    }
	
    bool is_dead() const {
        return dead_;
    }

    void set_dead(bool d) {
        dead_ = d;
    }

    bool is_movable() const {
        return movable_;
    }

    void set_movable(bool b) {
        movable_ = b;
    }

    bool is_drawable() const {
        return drawable_;
    }

    void set_drawable(bool b) {
        drawable_ = b;
    }

    
    // int get_priority() const {
    //     return priority_;
    // }

private:
    bool dead_;
    bool movable_;
    bool drawable_;
    // int  priority_;
};

typedef std::shared_ptr<Task> task_sptr;
