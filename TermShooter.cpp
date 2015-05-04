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

#include "TermShooter.h"
#include "Task.h"
#include "FPSManager.h"
#include "TaskContainer.h"

TermShooter::TermShooter() {
}

TermShooter::~TermShooter() {
}

void TermShooter::start() {

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

    arg->ships.push_task(std::make_shared<Ship>());

    arg->generals.push_task(std::make_shared<Field>());
    arg->generals.push_task(std::make_shared<SideBar>());
    
    arg->score       = 0;
    arg->shot_cnt    = 0;
    
    FPSManager<taskargts_sptr> fps_manager;
    fps_manager.start(
        std::bind(&TermShooter::move, this, _1),
        std::bind(&TermShooter::draw, this, _1, _2),
        arg);
}

bool TermShooter::move(taskarg_sptr arg) {
    std::shared_ptr<TaskArgTS>  argts = std::static_pointer_cast<TaskArgTS>(arg);

    // get keyboard key status
    int save_key = ERR;
    do {
        argts->key = save_key;
        save_key = getch();
    } while(save_key != ERR);

    // force exit?
    if(argts->key== 'q') {
        return false;
    }    
    
    // move objects
    argts->generals.move(arg);
    argts->ships.move(arg);
    argts->bullets.move(arg);
    argts->enemies.move(arg);
    argts->guards.move(arg);
    
    // 当たり判定
    for(auto bullet: argts->bullets) {
        for(auto enemy: argts->enemies) {
            if(enemy->get_x() - enemy->get_hsx() <= bullet->get_x() &&
               bullet->get_x() <= enemy->get_x() + enemy->get_hsx() &&
               enemy->get_y()==bullet->get_y()) {
                
                argts->score += 100;
                enemy->set_dead(true);
                bullet->set_dead(true);
            }
        }
			
        for(auto guard : argts->guards) {
            if(guard->get_x() == bullet->get_x() &&
               guard->get_y() == bullet->get_y()) {
                
                guard->set_dead(true);
                bullet->set_dead(true);
            }
        }

        for(auto ship: argts->ships) {
            if(ship->get_x() - ship->get_hsx() <= bullet->get_x() &&
               bullet->get_x() <= ship->get_x() + ship->get_hsx() &&
               bullet->get_y() == ship->get_y()) {
            
                //argts->game_state = TaskArgTS::GS_GAMEOVER;
                
            }
        }

        
    }

    return true;
}

bool TermShooter::draw(taskarg_sptr arg, float fps) {
    std::shared_ptr<TaskArgTS>  argts = std::static_pointer_cast<TaskArgTS>(arg);

    erase();
    
    argts->generals.draw(arg);
    argts->bullets.draw(arg);
    argts->enemies.draw(arg);
    argts->guards.draw(arg);
    argts->ships.draw(arg);
    argts->generals.draw(arg);

    NCursesManager::getInst().flip();   
    
    return true;
}
