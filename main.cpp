#include <ostream>

// bool game_main()
// {
//     Field       field;
//     GameOver    gameover;
//     StateWindow state_window;
	
//     Task::Args args;
//     field.init_args(&args);
//     args.key        = '\0';
//     args.game_state = Task::Args::GS_PLAY;
	
//     bool restart;
//     while(args.key != 'q' && args.key != 'r')
//     {
//         // 移動処理
//         switch(args.game_state) 
//         {
//             case Task::Args::GS_PLAY:
//                 field.move(&args);
//                 state_window.move(&args);
//                 break;
				
//             case Task::Args::GS_GAMEOVER:
//                 gameover.move(&args);
//                 break;
//         }

//         // 描画処理
//         // WINDOW *wEmpty = newpad(100, 100);
//         // wclear(wEmpty);
//         // overwrite(wEmpty, win);
//         // delwin(wEmpty);

//         switch(args.game_state) 
//         {
//             case Task::Args::GS_PLAY:
//                 field.draw(&args);
//                 state_window.draw(&args);
//                 break;
				
//             case Task::Args::GS_GAMEOVER:
//                 field.draw(&args);
//                 state_window.draw(&args);
//                 gameover.draw(&args);
//                 break;
//         }
//         //doupdate();
//         redrawwin(win);
//         refresh();
	
//     return restart;
// }

#include "TermShooter.h"
#include "NCursesManager.h"

int main()
{
    NCursesManager::getInst();
    
    TermShooter term_shooter;
    term_shooter.start();

    return 0;
}

