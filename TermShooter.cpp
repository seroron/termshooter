#include <ostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <list>
#include <string>
#include <functional>

#include <sys/time.h>
#include <time.h>

#include "NCursesManager.h"
#include "Field.h"
#include "SideBar.h"
#include "GameOver.h"
#include "TermShooter.h"
#include "Task.h"
#include "FPSManager.h"
#include "TaskContainer.h"

TermShooter::TermShooter() {
}

TermShooter::~TermShooter() {
}

void TermShooter::setup_game() {
    
    using namespace std::placeholders;

    taskargts_sptr arg(std::make_shared<TaskArgTS>());

    for(int x=5; x<55; x+=5) {
        for(int y=2; y<20; y+=3) {
            arg->enemies.push_task(std::make_shared<Enemy>(x, y, -1, 0));
        }
    }
		
    for(int x1=Field::FIELD_X_MIN+2; x1<Field::FIELD_X_MAX-5; x1+=10) {
        for(int x2=0; x2<5; x2++) {
            for(int y=Field::GUARD_LINE_MIN; y<=Field::GUARD_LINE_MAX; y++) {
                arg->guards.push_task(std::make_shared<Guard>(x1+x2, y));
            }
        }
    }

    arg->ship = std::make_shared<Ship>();

    arg->generals.push_task(std::make_shared<Field>());
    arg->generals.push_task(std::make_shared<SideBar>());
    
    arg->score       = 0;
    arg->shot_cnt    = 0;
    
    reset_ = false;
    
    FPSManager<taskargts_sptr> fps_manager;
    fps_manager.start(
        std::bind(&TermShooter::move, this, _1),
        std::bind(&TermShooter::draw, this, _1, _2),
        arg);
}

void TermShooter::start() {
    do {
        setup_game();
    } while(reset_);
}

bool TermShooter::move(taskargts_sptr arg) {

    // get keyboard key status
    int save_key = ERR;
    do {
        arg->key = save_key;
        save_key = getch();
    } while(save_key != ERR);

    // reset?
    if(arg->key== 'r') {
        reset_ = true;
        return false;
    }
    
    // force exit?
    if(arg->key== 'q') {
        return false;
    }    
    
    // move objects
    arg->generals.move(arg);
    arg->ship->move(arg);
    arg->bullets.move(arg);
    arg->enemies.move(arg);
    arg->guards.move(arg);
    
    // 当たり判定
    for(auto bullet: arg->bullets) {
        for(auto enemy: arg->enemies) {
            if(bullet->check_collision(*enemy)) {
                arg->score += 100;
                enemy->set_dead(true);
                bullet->set_dead(true);
            }
        }
			
        for(auto guard : arg->guards) {
            if(bullet->check_collision(*guard)) {
                guard->set_dead(true);
                bullet->set_dead(true);
            }
        }

        for(auto bullet2 : arg->bullets) {
            if(bullet != bullet2 &&
               bullet->check_collision(*bullet2)) {
                bullet->set_dead(true);
                bullet2->set_dead(true);
            }
        }

        if(bullet->check_collision(*arg->ship)) {
            bullet->set_dead(true);
            arg->ship->damage();

        }
    }

    if(arg->ship->is_dead()) {
        arg->generals.push_task(std::make_shared<GameOver>(arg));
    }
    
    return true;
}

bool TermShooter::draw(taskargts_sptr arg, float fps) {
    
    erase();
    
    arg->ship->draw(arg);
    arg->enemies.draw(arg);
    arg->guards.draw(arg);
    arg->bullets.draw(arg);
    arg->generals.draw(arg);

    NCursesManager::getInst().flip();   
    
    return true;
}
