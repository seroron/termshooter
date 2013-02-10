#pragma once

#include <memory>
#include <list>

typedef std::list<Bullet> bullet_list_t;
typedef std::list<Enemy> enemy_list_t;
typedef std::list<Guard> guard_list_t;

struct TaskArg 
{
    enum GameState {
        GS_PLAY,
        GS_GAMEOVER,
    };
  
    bullet_list_t* bullet_list;
    enemy_list_t*  enemy_list;
    guard_list_t*  guard_list;
    Ship*          ship;
    int            shot_cnt;
    int            score;
		
    GameState      game_state;
    int            key;
};

