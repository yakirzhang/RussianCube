//
// Created by yakirzhang on 18-1-20.
//
#include <Printer.h>
Printer::Printer() {
  terminal_ = std::make_shared<TerminalControl>();
  terminal_->SetCursorVisual(false);
}
void Printer::PrintXY(const char *str, TerminalControl::ColorType color,
                      TerminalControl::ColorLocate locate, int x, int y) {
  terminal_->MoveCursor(x, y);
  terminal_->SetColor(color, locate);
  terminal_->putString(str, strlen(str));
}
Printer::~Printer() {
  terminal_->SetCursorVisual(true);
  terminal_->Reset();
}
//指定位置，输出图形
void Printer::PrintCube(Cube &cube_, int x, int y) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (cube_.Display[j][i])
        PrintXY("  ", TerminalControl::ColorType::RED,
                TerminalControl::ColorLocate::BACK, x + i * 2, y + j);
    }
  fflush(NULL);
};
//打印棋盘
void Printer::PrintMetrix(){

}
