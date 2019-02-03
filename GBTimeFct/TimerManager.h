// author: chris-scientist
// created at: 01/02/2019
// updated at: 03/02/2019

#ifndef TIMER_MANAGER
#define TIMER_MANAGER

#include <Gamebuino-Meta.h>

#include "Timer.h"
#include "TimerDisplay.h"

void manageCommandsOfTimer(Timer &aTimer);
void runTimer(Timer &aTimer);
void paint(Timer aTimer);

#endif
