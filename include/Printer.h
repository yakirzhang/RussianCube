#pragma once
#include <TerminalControl.h>
#include <memory>
class Printer {
 public:
  void SetCursorVisual(bool showCursor);
  void PrintStartInterface();
  Printer();
  void Print_mode_shape(int num, int mode, int x, int y,
                        TerminalControl::ColorType color);

 private:
  std::shared_ptr<TerminalControl> terminal_ = nullptr;
  void PrintXY(const char *str, TerminalControl::ColorType color,
               TerminalControl::ColorLocate locate, int x, int y);
};