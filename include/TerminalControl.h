#pragma once
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
//     前景色为30+颜色值，如31表示前景色为红色；背景色为40+颜色值，如41表示背景色为红色。
// 0  (黑）1 （红）2 （绿）3  (黄)4 （蓝）5 （洋红）6 （青）7 （白）

// 显示方式
// 0(默认)、1(粗体 /高亮)、22(非粗体)、4(单条下划线)、24(无下划线)、5(闪烁)、
// 25(无闪烁)、7(反显、翻转前景色和背景色)、27(无反显)

//一般的控制方法为
//\033[显示方式;前景色;背景色m输出字符串\033[0m

//此外，还有一些ANSI控制码，如：nA (光标上移n行 )、nB(光标下移n行
//)、nC(光标右移n行 )、
// nD (光标左移n行
// )、2J(清屏)、K(清除从光标到行尾的内容)、s(保存光标位置)、u(恢复光标位置)
// ?25h(隐藏光标)、?25l(显示光标)。

class TerminalControl {
 public:
  enum DisPlayType {
    DEFAULT,
    BOLD,
    BLINK,
    UNDERLINE,
  };
  enum ColorType : int {
    BLACK = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
  };
  enum ColorLocate : int { FRONT = 1, BACK = 2 };
  void SetCursorVisual(bool showCursor = true);
  void clearScreen();
  void MoveCursor(int rows, int cols);
  void SetDisplayType(DisPlayType type_);
  void SetColor(ColorType color_, ColorLocate color_locate_);
  void putString(const char* str, size_t size);
  void Reset();
 private:
  bool SetPrintfProp(const char* settingThings, size_t settingSize);
};
