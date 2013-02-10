#include "Ship.h"
#include "Field.h"
#include "TaskArgTS.h"
#include "NCursesManager.h"

Ship::Ship() {
    x_  = 30;
    y_  = Field::PLAYER_LINE;
    sx_ = 3;
    shot_interval_ = 0;
}

Ship::~Ship() {
}

void Ship::move(taskarg_sptr arg) {
    std::shared_ptr<TaskArgTS>  argts = std::static_pointer_cast<TaskArgTS>(arg);
    
    switch(argts->key) {
    case 'j':
        if(x_>3) x_--;
        break;

    case 'l':
        if(x_<59) x_++;
        break;
	
    case ' ': 
        if(shot_interval_ <= 0) {
            argts->bullets.push_task(std::make_shared<Bullet>(x_, y_-1, 0, -1, "T"));
            argts->shot_cnt++;
            argts->score -= 10;
	  
            shot_interval_ = 5;
        }
        break;
    }
		
    shot_interval_--;
}

void Ship::draw(taskarg_sptr arg) {
    attrset(COLOR_PAIR(NCursesManager::CC_WHITE));
    mvprintw(y_, x_-1, "<+>");
}
