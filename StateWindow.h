#pragma once

class StateWindow : public Task
{
public:
    StateWindow()
    {
    }
	
    virtual ~StateWindow()
    {}

    virtual void move(Task::Args* args)
    {
		
    }
	
    virtual void draw(Task::Args* args)
    {
        int x = FIELD_X_MAX + 5;
        int y = 5;
		
        mvprintw(y++, x, " shot : %d", args->shot_cnt);
        mvprintw(y++, x, "score : %d", args->score);
		
        y += 10;		

        mvaddstr(y++, x, "    J : Left");		
        mvaddstr(y++, x, "    L : Right");
        mvaddstr(y++, x, "Space : Shot");
		
        y += 1;
        mvaddstr(y++, x, "    R : Restart");
        mvaddstr(y++, x, "    Q : Exit Game");
    }
};
