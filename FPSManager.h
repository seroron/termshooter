#pragma once

#include <memory>
#include <functional>
#include <chrono>
#include <ratio>
#include <unistd.h>

template<typename ARG>
class FPSManager {
public:
    typedef typename std::function<bool (ARG)> callback_move_func_t;
    typedef typename std::function<bool (ARG, float)> callback_draw_func_t;

    FPSManager() {
    }

    ~FPSManager() {
    }

    void test(callback_move_func_t move) {
    }

    void start(callback_move_func_t move, callback_draw_func_t draw, ARG& arg) {
        using namespace std::chrono;

        microseconds fps_time(50000);
        microseconds loop_time;

        auto prev_time = high_resolution_clock::now();
        for(;;) {
            loop_time = duration_cast<microseconds>(
                high_resolution_clock::now() - prev_time);
            float fps = 1000000.0f / loop_time.count();

            if(loop_time >= fps_time) {
                do {
                    loop_time -= fps_time;
                    if(!move(arg)) return;
                    prev_time += fps_time;
                } while(loop_time >= fps_time);

                if(!draw(arg, fps)) return;
            }
            else {
                usleep(1000);
            }
        } 
    }
};

