#include "Task.h"
#include "TaskContainer.h"

#include "Bullet.h"
#include "Enemy.h"
#include "Guard.h"
#include "Ship.h"

struct TaskArgTS : public TaskArg {
    
    enum GameState {
        GS_PLAY,
        GS_GAMEOVER,
    };

    TaskContainer<Bullet> bullets;
    TaskContainer<Enemy> enemies;
    TaskContainer<Guard> guards;
    TaskContainer<Ship> ships;
    TaskContainer<Task> generals;
    
    int            shot_cnt;
    int            score;		
    GameState      game_state;
    int            key;
};

typedef std::shared_ptr<TaskArgTS> taskargts_sptr;

