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
      dead_(false) {
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

    // int get_priority() const {
    //     return priority_;
    // }

private:
    bool dead_;
    // int  priority_;
};

typedef std::shared_ptr<Task> task_sptr;
