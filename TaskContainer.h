#pragma once

#include "Task.h"

#include <list>
#include <algorithm>
#include <functional>

template<class TaskType>
class TaskContainer : public Task<typename TaskType::arg_type> {
public:
    typedef typename TaskType::taskarg_sptr taskarg_sptr;
    
    typedef typename std::shared_ptr<TaskType> spec_task_sptr;
    typedef typename std::list<spec_task_sptr>::iterator spec_task_iterator;
    typedef typename std::list<spec_task_sptr>::const_iterator spec_task_const_iterator;
    
    TaskContainer() {
    }
    
    virtual ~TaskContainer() {
    }

    virtual void move(taskarg_sptr arg) override {
        std::for_each(task_list_.begin(),
                      task_list_.end(),
                      [&](auto &i) {
                          if(i->is_movable()) {
                              i->move(arg);
                          }
                      });
        
        // remove dead task
        auto it  = task_list_.begin();
        auto end = task_list_.end();
        for(; it!=end;) {
            if((*it)->is_dead()) {
                task_list_.erase(it++);
            }
            else {
                it++;
            }
        }
    }
    
    virtual void draw(taskarg_sptr arg) override {
         std::for_each(task_list_.begin(),
                       task_list_.end(),
                       [&](auto &i) {
                           if(i->is_drawable()) {
                               i->draw(arg);
                           }
                       });
    }

    void push_task(spec_task_sptr t) {
        task_list_.push_back(t);
    }

    spec_task_iterator begin() {
        return task_list_.begin();
    }

    spec_task_iterator end() {
        return task_list_.end();
    }

    spec_task_const_iterator begin() const {
        return task_list_.begin();
    }

    spec_task_const_iterator end() const {
        return task_list_.end();
    }
    
private:
    std::list<spec_task_sptr> task_list_;    
};
