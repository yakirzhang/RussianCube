//
// Created by yakirzhang on 18-1-20.
//

#include "Cube.h"
class Cube {
 public:
  enum CubeType : int { Square, SHAN, YAZI, STICK, LEFTGUN, RIGHTGUN };
  Cube(CubeType ct_, int cm_) : type_(ct_), CubeMode_(cm_) {
    switch (ct_) { case Square: }
  }

 private:
  CubeType type_;
  int CubeMode_;
  bool Display[5][5];
};