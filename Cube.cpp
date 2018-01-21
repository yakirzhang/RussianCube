//
// Created by yakirzhang on 18-1-20.
//

#include <Cube.h>
constexpr bool Cube::DisplayMap[6][4][5][5];
Cube::Cube(CubeType ct_, int cm_, int x, int y)
    : type_(ct_), CubeMode_(cm_), locate_x(x), locate_y(y) {
  if (type_ == RIGHTGUN || type_ == LEFTGUN || type_ == SHAN)
    maxCubeMode_ = 4;
  else
    maxCubeMode_ = 2;
  CubeMode_ = CubeMode_ % maxCubeMode_;

  for (int i = 0; i < 5; i++) {
    vector<bool> tmp;
    tmp.assign(Cube::DisplayMap[type_][CubeMode_][i][0],
               Cube::DisplayMap[type_][CubeMode_][i][5]);
    Display.push_back(tmp);
  }
}