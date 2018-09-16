//
//  funcTimer.h
//  handylibs
//
//  Created by fast-algo on 16/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#ifndef funcTimer_h
#define funcTimer_h

#include <stdio.h>
#include <time.h>

#define NUM_FUNC_TIMERS 100

void startFuncTimer(int id);
void stopFuncTimer(int id);
double getFuncTime(int id);

#endif /* funcTimer_h */
