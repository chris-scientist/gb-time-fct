// author: chris-scientist
// created at: 03/02/2019

#include "TimerDisplay.h"


void paint(const int aMode, int aTimeInFrames, const int * aTime, const bool anActivateTimer) {
  switch(aMode) {
    case BASIC_MODE:
      paintBasicMode(aTimeInFrames, aTime, anActivateTimer);
    break;
    default:
      paintChronoMode(aTimeInFrames, aTime, anActivateTimer);
  }
}

void paintBasicMode(int aTimeInFrames, const int * aTime, const bool anActivateTimer) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateTimer) {
    gb.display.println("(A) Pause/Reprendre");
  } else {
    gb.display.println("|| Pause");
  }
  gb.display.setColor(WHITE);
  gb.display.println("");
  gb.display.printf("%s %d", "Jours   :", aTime[DAYS_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", "Heures  :", aTime[HOURS_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", "Minutes :", aTime[MINUTES_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", "Secondes:", aTime[SECONDS_NUMBER]);
  gb.display.println("");
  gb.display.println("");
  gb.display.printf("%lu", aTimeInFrames);
}

void paintChronoMode(int aTimeInFrames, const int * aTime, const bool anActivateTimer) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateTimer) {
    gb.display.println("(A) Pause/Reprendre");
  } else {
    gb.display.println("|| Pause");
  }
  gb.display.setColor(WHITE);
  gb.display.println("");
  // Afficher les jours (s'il y en a)
  int nbDays = aTime[DAYS_NUMBER];
  if(nbDays > 0) {
    gb.display.printf("%d d ", nbDays);
  }
  
  // Sur une nouvelle ligne afficher les heures / minutes et secondes
  int nbHours = aTime[HOURS_NUMBER];
  if(nbHours < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d h ", nbHours);
  int nbMinutes = aTime[MINUTES_NUMBER];
  if(nbMinutes < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d m ", nbMinutes);
  int nbSeconds = aTime[SECONDS_NUMBER];
  if(nbSeconds < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d s", nbSeconds);
}

void paintStartWindow() {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("(A) Pour demarrer");
}

void paintResetConfirmWindow() {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("Souhaitez-vous");
  gb.display.println("(A) reinitialiser");
  gb.display.println("ou (B) reprendre");
}
