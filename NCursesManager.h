#pragma once

#include <ncurses.h>

class NCursesManager {
public:
    static const int CC_RED     = 1;
    static const int CC_GREEN   = 2;
    static const int CC_YELLOW  = 3;
    static const int CC_BLUE    = 4;
    static const int CC_CYAN    = 5;
    static const int CC_MAGENTA = 6;
    static const int CC_WHITE   = 7;


    static NCursesManager& getInst();
    
    void flip() {
        redrawwin(win_);
        refresh();
    }
    
private:
    NCursesManager();
    ~NCursesManager();
    // NCursesManager(const NCursesManager&){}
    // NCursesManager &operator=(const NCursesManager&){}
    
    WINDOW* win_;
};
