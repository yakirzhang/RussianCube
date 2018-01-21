//
// Created by 张义杰 on 2018/1/21.
//

#include <GameView.h>

GameView::GameView()
    : UpCube(Cube::CubeType(random() % 6), random() % 4, 10, 0) {
  Startview = Interface();
}
void GameView::init() {
  Startview.InsertHline(10, 5, 48);
  Startview.InsertHline(10, 30, 48);
  Startview.InsertHline(40, 14, 18);

  // |||||
  Startview.InsertVline(10, 5, 25);
  Startview.InsertVline(40, 5, 25);
  Startview.InsertVline(58, 5, 25);

  // lable
  Startview.InsertLable(9 + 2 + 28 + 2 + 4, 4 + 1 + 8 + 1 + 5, "Score: 0");
  Startview.InsertLable(9 + 2 + 28 + 2 + 4, 4 + 1 + 8 + 1 + 10, "Level: 1");
}

bool GameView::IsCollission(Cube &cube) {}
Cube GameView::CreatRandomCube() {
  srand(time(NULL));
  return Cube(Cube::CubeType(random() % 6), random() % 4, 10, 0);
}

void GameView::UpdateDown() {
  // todo 判断是否消除

  // todo 判断是否结束游戏
}
void GameView::Act(char ch) {
  switch (ch) {
    case 'w': {
      Cube NextCube_mode =
          Cube(UpCube.type_, (UpCube.CubeMode_ + 1) % UpCube.maxCubeMode_,
               UpCube.locate_x, UpCube.locate_y);
      if (!IsCollission(NextCube_mode)) {
        UpView.ClearArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
                         UpCube.Display);
        UpView.InserArea(NextCube_mode.locate_x, NextCube_mode.locate_y, 5, 5,
                         NextCube_mode.Display);
        UpCube = NextCube_mode;
        break;
      }
    }
    // change shape

    case 's': {
      Cube NextCube_down = Cube(UpCube.type_, UpCube.CubeMode_, UpCube.locate_x,
                                UpCube.locate_y + 1);
      if (!IsCollission(NextCube_down)) {
        UpView.ClearArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
                         UpCube.Display);
        UpView.InserArea(NextCube_down.locate_x, NextCube_down.locate_y, 5, 5,
                         NextCube_down.Display);
        UpCube = NextCube_down;
      } else {
        UpCube = CreatRandomCube();
        UpdateDown();
      }
      break;
    }

    case 'a': {
      Cube NextCube_left = Cube(UpCube.type_, UpCube.CubeMode_,
                                UpCube.locate_x - 1, UpCube.locate_y);
      if (!IsCollission(NextCube_left)) {
        UpView.ClearArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
                         UpCube.Display);
        UpView.InserArea(NextCube_left.locate_x, NextCube_left.locate_y, 5, 5,
                         NextCube_left.Display);
        UpCube = NextCube_left;
      }
      break;
    }

    case 'd': {
      Cube NextCube_right = Cube(UpCube.type_, UpCube.CubeMode_,
                                 UpCube.locate_x + 1, UpCube.locate_y);
      if (!IsCollission(NextCube_right)) {
        UpView.ClearArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
                         UpCube.Display);
        UpView.InserArea(NextCube_right.locate_x, NextCube_right.locate_y, 5, 5,
                         NextCube_right.Display);
        UpCube = NextCube_right;
      }
      break;
    }
    default:
      break;
  }
}
void GameView::show() {
  Startview.show();
  UpView.show();
  DownView.show();
  fflush(NULL);
}