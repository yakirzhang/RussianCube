#pragma once
#include <Cube.h>
#include <DownCubes.h>
#include <Interface.h>
class GameView {
 public:
  void init();
  GameView();
  void show();
  void Act(char ch);
  bool IsCollission(Cube &cube);
  void UpdateUp();
  Cube CreatRandomCube();
  void UpdateDown();

 private:
  Interface Startview;
  Interface DownView;
  Interface UpView;
  DownCubes DownCube;
  Cube UpCube;
};