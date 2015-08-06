#include "GameClear.h"

#include "Field.h"
#include "NCursesManager.h"
#include "TaskArgTS.h"

GameClear::GameClear(taskarg_sptr arg) {

    // pause game objects
    for(auto& i : arg->enemies) {
        i->set_movable(false);
    }
    
    for(auto& i : arg->bullets) {
        i->set_movable(false);
    }
    
    for(auto& i : arg->guards) {
        i->set_movable(false);
    }

    arg->ship->set_movable(false);
}
	
GameClear::~GameClear() {
}

void GameClear::move(taskarg_sptr arg) {
}
	
void GameClear::draw(taskarg_sptr arg) {
    
    attrset(COLOR_PAIR(NCursesManager::CC_CYAN));
    
    int x = Field::FIELD_X_MIN + 7;
    int y = Field::FIELD_Y_MIN + 5;

    mvaddstr(y++, x, R"(   _____                             )");
    mvaddstr(y++, x, R"(  / ____|                            )");
    mvaddstr(y++, x, R"( | |  __    __ _   _ __ ___     ___  )");
    mvaddstr(y++, x, R"( | | |_ |  / _` | | '_ ` _ \   / _ \ )");
    mvaddstr(y++, x, R"( | |__| | | (_| | | | | | | | |  __/ )");
    mvaddstr(y++, x, R"(  \_____|  \__,_| |_| |_| |_|  \___| )");
    y++;
    mvaddstr(y++, x, R"(              _____   _                        )");
    mvaddstr(y++, x, R"(             / ____| | |                       )");
    mvaddstr(y++, x, R"(            | |      | |   ___    __ _   _ __  )");
    mvaddstr(y++, x, R"(            | |      | |  / _ \  / _` | | '__| )");
    mvaddstr(y++, x, R"(            | |____  | | |  __/ | (_| | | |    )");
    mvaddstr(y++, x, R"(             \_____| |_|  \___|  \__,_| |_|    )");
    
    y++;
    y++;
    mvaddstr(y++, x, R"(         Press 'R' to retry game.         )");
}
