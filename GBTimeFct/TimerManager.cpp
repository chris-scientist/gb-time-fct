// author: chris-scientist
// created at: 03/02/2019

#include "TimerManager.h"

// Gestion des commandes
void manageCommandsOfTimer(Timer &aTimer) {

  if(aTimer.resetTimer) {
    // Si le chronomètre est prêt à être réinitialiser alors...

    // 1. une pression sur A réintialise le compteur
    if(gb.buttons.pressed(BUTTON_A)) {
      resetTimer(aTimer);
      aTimer.resetTimer = false;
    }

    // 2. une pression sur B annule la réinitialisation
    if(gb.buttons.pressed(BUTTON_B)) {
      aTimer.resetTimer = false;
    }
    
  } else {
    // Si le chronomètre est en cours ou en pause alors...

    // 1. une pression sur A modifie l'état (pause/en cours)
    if(gb.buttons.pressed(BUTTON_A)) {
      aTimer.activateTimer = !aTimer.activateTimer;
    }

    // 2. une pression sur B enclenche l'action 'reset'
    if(gb.buttons.pressed(BUTTON_B)) {
      aTimer.activateTimer = false;
      aTimer.resetTimer = true;
    }
    
  }
  
}

// Gestion du chronomètre
void runTimer(Timer &aTimer) {
  if(aTimer.activateTimer) {
    if(aTimer.tempTime == 0) {
      initTimer(aTimer);
    }
    incrementTime(aTimer);
    computeTime(aTimer);
  } else {
    pauseForTimer(aTimer);
  }
}

// Afficher le chronomètre ou des fenêtres de paramétrages
void paint(Timer aTimer) {
  if(!aTimer.activateTimer && aTimer.timeInSeconds == 0) {
    // Si le chronomètre est inactif et à "zéro" alors on affiche l'écran de démarrage
    paintStartWindow();
  } else if(aTimer.resetTimer) {
    // Si le chronomètre est sur le point d'être réinitialisé alors on affichge l'écran pour confirmer ou non l'opération
    paintResetConfirmWindow();
  } else {
    // Sinon on affiche le chronomètre
    paint(CHRONO_MODE, aTimer.timeInSeconds + aTimer.tempTime, aTimer.valueOfTime, aTimer.activateTimer);
  }
}
