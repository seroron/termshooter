#include "Enemy.h"
#include "NCursesManager.h"
#include "Field.h"
#include "Bullet.h"
#include "TaskArgTS.h"

#include <algorithm>

Enemy::Enemy(int x, int y, int mx, int my) {
    x_  = x;
    mx_ = mx;
    y_  = y;
    my_ = my;
    sx_ = 3;
		
    shot_interval_ = 100;
    move_interval_ = 3;
}

Enemy::~Enemy() {
}

void Enemy::move(taskarg_sptr arg) {
    std::shared_ptr<TaskArgTS>  argts = std::static_pointer_cast<TaskArgTS>(arg);
    
    move_interval_--;
    if(move_interval_ <= 0) {
        x_ += mx_;
        if(x_ - get_hsx() <= Field::FIELD_X_MIN || 
           Field::FIELD_X_MAX <= x_ + get_hsx()) {
            
            mx_ *= -1;
            y_++;
        }
        move_interval_ = 3;
    }
		
    //int owny = y_;
    if(std::all_of(argts->enemies.begin(),
                   argts->enemies.end(),
                   [=](auto t){return y_>=t->y_;})) {
        
        shot_interval_--;
			
        if(shot_interval_ <= 0) {
            argts->bullets.push_task(std::make_shared<Bullet>(x_, y_+1, 0, 1, "V"));
            shot_interval_ = rand() % 10 + 15; //TODO
        }
    }
		
    // if(y_ >= PLAYER_LINE) {
    //     argts->game_state = Task::Args::GS_GAMEOVER;
    // }
}

void Enemy::draw(taskarg_sptr arg) {
    
    attrset(COLOR_PAIR(NCursesManager::CC_MAGENTA));
    mvaddstr(y_, x_ - sx_/2, "EEE");
}
