#pragma once
#include <Cube.h>
#include <TerminalControl.h>
#include <memory>
class Printer {
public:
  void PrintStartInterface();
  Printer();
  void PrintCube(Cube &cube_, int x, int y);
  ~Printer();
  void PrintMetrix();
  void PrintXY(const char *str, TerminalControl::ColorType color,
               TerminalControl::ColorLocate locate, int x, int y);

private:
  std::shared_ptr<TerminalControl> terminal_ = nullptr;
};