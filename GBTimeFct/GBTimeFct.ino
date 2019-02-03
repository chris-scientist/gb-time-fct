// author: chris-scientist
// created at: 31/01/2019
// updated at: 03/02/2019

#include <Gamebuino-Meta.h>

#include "Timer.h"
#include "TimerManager.h"

Timer myTimer;

void setup() {
  // initalisation de la gamebuino
  gb.begin();

  createTimer(myTimer);
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

  // gestion du chronomètre (commandes et incrémentation)
  manageCommandsOfTimer(myTimer);
  runTimer(myTimer);

  // votre programme ici...

  // affichage du chronomètre
  paint(myTimer);
}
