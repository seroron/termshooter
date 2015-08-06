#include "NCursesManager.h"

NCursesManager::NCursesManager()
{
    win_ = initscr();
    noecho();
    cbreak();
    raw();
    leaveok(stdscr, TRUE);
    curs_set(0);
    nodelay(win_, TRUE);
    noqiflush();
    intrflush(win_, TRUE);
    wnoutrefresh(win_);
	
    if (has_colors()) 
    {
        start_color();
       
        init_pair(CC_RED,     COLOR_RED,     COLOR_BLACK);
        init_pair(CC_GREEN,   COLOR_GREEN,   COLOR_BLACK);
        init_pair(CC_YELLOW,  COLOR_YELLOW,  COLOR_BLACK);
        init_pair(CC_BLUE,    COLOR_BLUE,    COLOR_BLACK);
        init_pair(CC_CYAN,    COLOR_CYAN,    COLOR_BLACK);
        init_pair(CC_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(CC_WHITE,   COLOR_WHITE,   COLOR_BLACK);
    }
}

NCursesManager::~NCursesManager() {
    endwin();
}

NCursesManager& NCursesManager::getInst() {
    static NCursesManager inst;
    return inst;
}

