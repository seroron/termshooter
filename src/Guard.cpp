#include "Guard.h"
#include "NCursesManager.h"

Guard::Guard(int x, int y) {
    x_ = x;
    y_ = y;
    sx_ = 1.0f;
    sy_ = 1.0f;
}

Guard::~Guard() {
}

void Guard::move(taskarg_sptr arg) {

}

void Guard::draw(taskarg_sptr arg) {
    attrset(COLOR_PAIR(NCursesManager::CC_GREEN));
    mvaddstr(y_, x_, "G");	
}
