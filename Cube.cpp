//
// Created by yakirzhang on 18-1-20.
//

#include <Cube.h>

Cube::Cube(CubeType ct_, int cm_) : type_(ct_), CubeMode_(cm_) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      Display[i][j] = DisplayMap[type_][CubeMode_][i][j];
    }
}