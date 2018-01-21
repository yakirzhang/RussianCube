#pragma once
#include <Cube.h>
#include <DownCubes.h>
#include <Interface.h>
#include <Printer.h>
class GameView {
 public:
  void init();
  GameView();
  void show();
  bool Act(char ch);
  bool IsCollission(Cube &cube);
  void UpdateUp();
  Cube CreatRandomCube();
  void UpdateDown(Cube &cube);
    bool OutputDownView();
 private:
  Interface Startview;
  Interface DownView;
  Interface UpView;
  DownCubes DownCube;
  Printer p;
  Cube UpCube;
};