//
// Created by yakirzhang on 18-1-20.
//
#include <Printer.h>

Printer::Printer() { terminal_ = std::make_shared<TerminalControl>(); }
void Printer::PrintXY(const char *str, TerminalControl::ColorType color,
                      TerminalControl::ColorLocate locate, int x, int y) {
  terminal_->MoveCursor(y, x);
  terminal_->SetColor(color, locate);
  terminal_->putString(str, strlen(str));
}
void Printer::SetCursorVisual(bool showCursor) {
  terminal_->SetCursorVisual(showCursor);
};
//指定位置，输出图形
void Printer::Print_mode_shape(int num, int mode, int x, int y,
                               TerminalControl::ColorType color) {
  //指定位置输出方块
  int m_x = x;
  int m_y = y;
  int i;
  for (i = 0; i < 16; i++) {
    if (i != 0 && i % 4 == 0) {
      m_x = x;
      m_y++;
    }
    if (shape[n][m][i] == 1) {
      printxy("[]", c, m_x, m_y);
    }
    m_x = m_x + 2;
  }
  fflush(NULL);
};
void Printer::PrintStartInterface() {
  //清屏
  int l;
  int w;
  terminal_->clearScreen();
  int a, b;
  int s_x = 9 + 2 + 28 + 2 + 4, s_y = 4 + 1 + 8 + 1 + 5;  //打印分数的位置
  int l_x = 9 + 2 + 28 + 2 + 4, l_y = 4 + 1 + 8 + 1 + 10;  //打印关卡级别的位置
  for (l = 5; l < 30; l++) {
    a = 10;
    b = l;

    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
    a = 40;
    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
    a = 58;
    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
  }
  for (w = 10; w < 59; w++) {
    a = w;
    b = 5;
    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
    b = 30;
    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
  }
  //打印分数等级位置
  PrintXY("Score: 0", TerminalControl::ColorType::BLACK,
          TerminalControl::ColorLocate::BACK, s_x, s_y);
  PrintXY("Level: 1", TerminalControl::ColorType::BLACK,
          TerminalControl::ColorLocate::BACK, l_x, l_y);

  //打印边框 行，（5,10-58） （30，10-58）
  //打印另外一行，（12，42-56）
  for (w = 40; w < 59; w++) {
    b = 14;
    a = w;
    PrintXY("  ", TerminalControl::ColorType::CYAN,
            TerminalControl::ColorLocate::BACK, a, b);
  }
  //打印边框 列三条（5-31,10）（5-31,40）（5-31,56）
  //隐藏光标
  terminal_->SetCursorVisual(false);
  terminal_->Reset();
  fflush(NULL);
}