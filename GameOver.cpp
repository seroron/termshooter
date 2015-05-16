#include "GameOver.h"

#include "Field.h"
#include "NCursesManager.h"
#include "TaskArgTS.h"

GameOver::GameOver(taskarg_sptr arg) {

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
	
GameOver::~GameOver() {
}

void GameOver::move(taskarg_sptr arg) {
}
	
void GameOver::draw(taskarg_sptr arg) {
    
    attrset(COLOR_PAIR(NCursesManager::CC_RED));
    
    int x = Field::FIELD_X_MIN + 7;
    int y = Field::FIELD_Y_MIN + 5;

    mvaddstr(y++, x, R"(   _____                             )");
    mvaddstr(y++, x, R"(  / ____|                            )");
    mvaddstr(y++, x, R"( | |  __    __ _   _ __ ___     ___  )");
    mvaddstr(y++, x, R"( | | |_ |  / _` | | '_ ` _ \   / _ \ )");
    mvaddstr(y++, x, R"( | |__| | | (_| | | | | | | | |  __/ )");
    mvaddstr(y++, x, R"(  \_____|  \__,_| |_| |_| |_|  \___| )");
    y++;
    mvaddstr(y++, x, R"(             ____                         )");
    mvaddstr(y++, x, R"(            / __ \                        )");
    mvaddstr(y++, x, R"(           | |  | | __   __   ___   _ __  )");
    mvaddstr(y++, x, R"(           | |  | | \ \ / /  / _ \ | '__| )");
    mvaddstr(y++, x, R"(           | |__| |  \ V /  |  __/ | |    )");
    mvaddstr(y++, x, R"(            \____/    \_/    \___| |_|    )");    

    y++;
    y++;
    mvaddstr(y++, x, R"(         Press 'R' to retry game.         )");    

}
