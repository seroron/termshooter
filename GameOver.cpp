#include "GameOver.h"

#include "Field.h"
#include "NCursesManager.h"

GameOver::GameOver() {
}
	
GameOver::~GameOver() {
}

void GameOver::move(taskarg_sptr arg) {
}
	
void GameOver::draw(taskarg_sptr arg) {
    
    int x = Field::FIELD_X_MIN + 20;
    int y = Field::FIELD_Y_MAX / 2;
    mvaddstr(y++, x, "                   ");
    mvaddstr(y++, x, " ----------------- ");
    mvaddstr(y++, x, " |   GAME OVER   | ");
    mvaddstr(y++, x, " ----------------- ");
    mvaddstr(y++, x, "                   ");
}
