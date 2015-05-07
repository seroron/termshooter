#include "Ship.h"
#include "Field.h"
#include "TaskArgTS.h"
#include "NCursesManager.h"

Ship::Ship() {
    x_  = 30;
    y_  = Field::PLAYER_LINE;
    sx_ = 3;
    sy_ = 1;
    shot_interval_ = 0;
}

Ship::~Ship() {
}

void Ship::move(taskarg_sptr arg) {

    switch(arg->key) {
    case 'j':
        if(x_>3) x_--;
        break;

    case 'l':
        if(x_<59) x_++;
        break;
	
    case ' ': 
        if(shot_interval_ <= 0) {
            arg->bullets.push_task(std::make_shared<Bullet>(x_+1, y_-2, 0, -1, "T"));
            arg->shot_cnt++;
            
            arg->score--;
            if(arg->score<0) {
                arg->score = 0;
            }
	  
            shot_interval_ = 5;
        }
        break;
    }
		
    shot_interval_--;
}

void Ship::draw(taskarg_sptr arg) {
    attrset(COLOR_PAIR(NCursesManager::CC_CYAN));
    mvprintw(y_, x_, "<+>");
}
