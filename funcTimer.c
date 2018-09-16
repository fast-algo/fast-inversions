//
//  funcTimer.c
//  handylibs
//
//  Created by fast-algo on 16/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include "funcTimer.h"

clock_t func_start[NUM_FUNC_TIMERS] = {0};
clock_t func_end[NUM_FUNC_TIMERS] = {0};

void startFuncTimer(int id)
{
    func_start[id] = clock();
}

void stopFuncTimer(int id)
{
    func_end[id] = clock();
}

double getFuncTime(int id)
{
    return (((double) (func_end[id] - func_start[id])) / CLOCKS_PER_SEC);
}
