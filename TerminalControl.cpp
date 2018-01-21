//
// Created by yakirzhang on 18-1-20.
//

#include "include/TerminalControl.h"
#include <cstdio>
void TerminalControl::clearScreen() {
  char buff[30] = {0};
  snprintf(buff, sizeof(buff), "\033[2J");
  printf("%s", buff);
}

void TerminalControl::SetCursorVisual(bool showCursor) {
  char buff[30] = {0};
  if (showCursor)
    snprintf(buff, sizeof(buff), "\033[?25h");
  else
    snprintf(buff, sizeof(buff), "\033[?25l");
  printf("%s", buff);
};
void TerminalControl::Reset() { SetPrintfProp("0", sizeof("0")); }
bool TerminalControl::SetPrintfProp(const char *settingThings,
                                    size_t settingSize) {
  if (settingSize > 20) return false;
  char buff[30] = {0};
  snprintf(buff, sizeof(buff), "\033[%sm", settingThings);
  printf("%s", buff);
  return true;
}
void TerminalControl::SetDisplayType(DisPlayType type_) {
  char buff[10] = {0};

  switch (type_) {
    case BOLD:
      snprintf(buff, sizeof(buff), "1");
      break;
    case DEFAULT:
      snprintf(buff, sizeof(buff), "0");
    case BLINK:
      snprintf(buff, sizeof(buff), "5");
    case UNDERLINE:
      snprintf(buff, sizeof(buff), "4");
    default:
      break;
  }
  SetPrintfProp(buff, sizeof(buff));
}
void TerminalControl::MoveCursor(int x, int y) {
  char buff[30] = {0};
  // y;x as x is horizen
  snprintf(buff, sizeof(buff), "\033[%d;%dH", y, x);
  printf("%s", buff);
}
void TerminalControl::SetColor(ColorType color_, ColorLocate color_locate_) {
  char buff[20] = {0};
  if (color_locate_ == FRONT)
    snprintf(buff, sizeof(buff), "%d", color_ + 30);
  else if (color_locate_ == BACK)
    snprintf(buff, sizeof(buff), "%d", color_ + 40);
  SetPrintfProp(buff, strlen(buff));
}
void TerminalControl::putString(const char *str, size_t size) {
  printf("%s", str);
  fflush(NULL);
}