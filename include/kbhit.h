#pragma once

#include <termio.h>
#include <zconf.h>
#include <cstdio>
#include <cstring>

class KeyMeneger {
 public:
  int kbhit(void);
  void init_kbhit();
  void finish_kbhit();

 private:
  int tty_set(void);
  int tty_reset(void);

  struct termios ori_attr, cur_attr;
  int tty_set_flag;
};
