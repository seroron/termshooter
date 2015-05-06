#include "Bullet.h"
#include "NCursesManager.h"
#include "Field.h"

Bullet::Bullet(int x, int y, int mx, int my, std::string aa) {
    x_  = x;
    mx_ = mx;
    y_  = y;
    my_ = my;
    sx_ = 1;
    sy_ = 2;
    aa_ = aa;
}

Bullet::~Bullet() {
}

void Bullet::move(taskarg_sptr arg) {
    x_ += mx_;
    y_ += my_;

    if(x_ < Field::FIELD_X_MIN || 
       x_ > Field::FIELD_X_MAX ||
       y_ < Field::FIELD_Y_MIN ||
       y_ > Field::FIELD_Y_MAX) {
        
        set_dead(true);
    }
}

void Bullet::draw(taskarg_sptr arg) {
    attrset(COLOR_PAIR(NCursesManager::CC_WHITE));
    mvprintw(y_,   x_, aa_.c_str());
    mvprintw(y_+1, x_, aa_.c_str());
}
