#include <Cube.h>
#include <GameView.h>
#include <Printer.h>
#include <kbhit.h>
#include <iostream>
int main() {
  GameView game;
  game.init();
  game.show();
  KeyMeneger km;
  km.init_kbhit();
  while (1) {
    if (km.kbhit()) {
      game.Act(getchar());
    }
  }
  km.finish_kbhit();
}