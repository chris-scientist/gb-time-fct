// author: chris-scientist
// created at: 03/02/2019

#ifndef TIMER_DISPLAY
#define TIMER_DISPLAY

#include <Gamebuino-Meta.h>

#include "ConstantesTimer.h"

void paint(const int aMode, int aTimeInFrames, const int * aTime, const bool anActivateTimer);
void paintBasicMode(int aTimeInFrames, const int * aTime, const bool anActivateTimer);
void paintChronoMode(int aTimeInFrames, const int * aTime, const bool anActivateTimer);
void paintStartWindow();
void paintResetConfirmWindow();

#endif
