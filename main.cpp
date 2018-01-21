#include <Cube.h>
#include <Printer.h>
#include <iostream>
int main() {
  Printer p;
  p.PrintStartInterface();
  Cube c(Cube::CubeType::LEFTGUN, 2);
  p.PrintCube(c, 14, 24);
  getchar();
  return 0;
}