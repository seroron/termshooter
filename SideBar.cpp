#include "SideBar.h"

#include "TaskArgTS.h"
#include "NCursesManager.h"
#include "Field.h"

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
    std::shared_ptr<TaskArgTS>  argts = std::static_pointer_cast<TaskArgTS>(arg);

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

    
    int x = Field::FIELD_X_MAX + 5;
    int y = 5;
		
    mvprintw(y++, x, " shot : %d", argts->shot_cnt);
    mvprintw(y++, x, "score : %d", argts->score);
		
    y += 20;		

    mvaddstr(y++, x, "    J : Move Left");		
    mvaddstr(y++, x, "    L : Move Right");
    mvaddstr(y++, x, "Space : Shot");
		
    y += 1;
    mvaddstr(y++, x, "    R : Restart");
    mvaddstr(y++, x, "    Q : Exit Game");
}
