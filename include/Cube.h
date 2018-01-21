#pragma once
#include <vector>
using namespace std;
class Cube {
 public:
  enum CubeType : int {
    RIGHTGUN = 0,
    LEFTGUN,
    SHAN,
    RIGHTYAZI,
    LEFTYAZI,
    STICK
  };
  Cube(const Cube& other) {
    type_ = other.type_;
    CubeMode_ = other.CubeMode_;
    locate_x = other.locate_x;
    locate_y = other.locate_y;
    Display.assign(other.Display.begin(), other.Display.end());
  }
  Cube(CubeType ct_, int cm_, int x_, int y_);
  vector<vector<bool>> Display;
  CubeType type_;
  int CubeMode_;
  int locate_x, locate_y;
  int maxCubeMode_;
  static constexpr bool DisplayMap[6][4][5][5]{
      // type 1 RIGHT_GUN
      {{
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 1, 1, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 1, 1},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {1, 1, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       }},
      // type 2 LEFT_GUN
      {{
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 1, 1, 1},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 1, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {1, 1, 1, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       }},
      // type 3 MOUNT
      {{
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 1, 1, 1, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 1, 1, 1, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 1, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       }},
      // type 4 YAZI_RIGHT
      {{
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 0, 0, 1, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 1, 1, 0, 0},
           {0, 0, 0, 0, 0},
       }},
      // type 5 YAZI_LEFT
      {{
           {0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 1, 1, 0, 0},
           {0, 1, 0, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 1, 1, 0, 0},
           {0, 0, 1, 1, 0},
           {0, 0, 0, 0, 0},
       }},
      // type 6 STICK
      {{
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 0, 0},
       },
       {
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
           {0, 1, 1, 1, 1},
           {0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0},
       }}};
};