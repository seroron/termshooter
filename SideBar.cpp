#include "SideBar.h"

#include <string>

#include "TaskArgTS.h"
#include "NCursesManager.h"
#include "Field.h"

const int SIDEBAR_X_MIN = Field::FIELD_X_MAX+2;
const int SIDEBAR_X_MAX = Field::FIELD_X_MAX+25;

SideBar::SideBar()
{
}
	
SideBar::~SideBar()
{
}

void SideBar::move(taskarg_sptr arg)
{    
}
	
void SideBar::draw(taskarg_sptr arg)
{
    // 枠
    attrset(COLOR_PAIR(NCursesManager::CC_WHITE));
    for(int i=Field::FIELD_Y_MIN; i<=Field::FIELD_Y_MAX; i++){
        ::move(i, SIDEBAR_X_MAX+1);
        printw("|");
    }
		
    for(int i=Field::FIELD_X_MAX+1; i<=SIDEBAR_X_MAX; i++){
        ::move(Field::FIELD_Y_MIN-1, i);
        printw("-");
        ::move(Field::FIELD_Y_MAX+1, i);
        printw("-");
    }		


    
    int x = SIDEBAR_X_MIN;
    int y = 5;


    mvprintw(y++, x, " SCORE");
    mvprintw(y++, x, "   %020d", arg->score);
    y++;
    mvprintw(y++, x, " LIFE");
    std::string life_str("   ");
    for(int i=0; i<arg->ship->get_life(); i++) {
        life_str += "O";
    }
    mvprintw(y++, x, life_str.c_str());
    
    y=15;
    mvprintw(y++, x, "------------------------");
    mvprintw(y++, x, "       Character        ");
    mvprintw(y++, x, "------------------------");
    mvaddstr(y++, x, "   <+> : Your Ship");		
    mvaddstr(y++, x, "    T  : Your Bullet");		
    mvaddstr(y++, x, "   EEE : Enemy");		
    mvaddstr(y++, x, "    V  : Enemy's Bullet");    
    y++;
    y++;

    mvprintw(y++, x, "------------------------");
    mvprintw(y++, x, "          Key           ");
    mvprintw(y++, x, "------------------------");
    mvaddstr(y++, x, "      J : Move Left");		
    mvaddstr(y++, x, "      L : Move Right");
    mvaddstr(y++, x, "  Space : Shot");
    y++;
    mvaddstr(y++, x, "      R : Restart");
    mvaddstr(y++, x, "      Q : Exit Game");
}
