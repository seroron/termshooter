#include "Enemy.h"
#include "NCursesManager.h"
#include "Field.h"
#include "Bullet.h"
#include "TaskArgTS.h"
#include "RandomManager.h"

#include <algorithm>

Enemy::Enemy(int x, int y, int mx, int my) {
    x_  = x;
    mx_ = mx;
    y_  = y;
    my_ = my;
    sx_ = 3;
    sy_ = 1;
		
    shot_interval_ = RandomManager::getInst().getUniformInt(20, 40);;
    move_interval_ = 3;
}

Enemy::~Enemy() {
}

void Enemy::move(taskarg_sptr arg) {
    move_interval_--;
    if(move_interval_ <= 0) {
        x_ += mx_;
        if(x_ <= Field::FIELD_X_MIN || 
           Field::FIELD_X_MAX <= x_ + sx_) {
            
            mx_ *= -1;
            y_++;
        }
        move_interval_ = 3;
    }
		
    if(std::all_of(arg->enemies.begin(),
                   arg->enemies.end(),
                   [=](auto t){return y_>=t->y_;})) {
        
        shot_interval_--;
			
        if(shot_interval_ <= 0) {
            arg->bullets.push_task(std::make_shared<Bullet>(x_+1, y_+1, 0, 1, "V"));
            shot_interval_ = RandomManager::getInst().getUniformInt(20, 40);
        }
    }
		
    // if(y_ >= PLAYER_LINE) {
    //     argts->game_state = Task::Args::GS_GAMEOVER;
    // }
}

void Enemy::draw(taskarg_sptr arg) {
    
    attrset(COLOR_PAIR(NCursesManager::CC_MAGENTA));
    mvaddstr(y_, x_, "EEE");
}
