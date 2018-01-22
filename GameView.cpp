//
// Created by 张义杰 on 2018/1/21.
//

#include <GameView.h>
#include <algorithm>

GameView::GameView()
    : UpCube(Cube::CubeType(random() % 6), random() % 4, 20, 20) {
  Startview = Interface();
  DownView = Interface();
  UpView = Interface();
  DownCube = DownCubes();
  p = Printer();
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

bool GameView::IsCollission(Cube &cube) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (cube.Display[j][i]) {
        if (2 * i + cube.locate_x < 12 || 2 * i + 2 + cube.locate_x > 40)
          return true;
        if (j + cube.locate_y <= 5 || j + cube.locate_y >= 30) return true;
        if (DownCube.BackGround[j + cube.locate_y][2 * i + cube.locate_x] ||
            DownCube.BackGround[j + cube.locate_y][2 * i + cube.locate_x + 1])
          return true;
      }
    }
  return false;
}
bool GameView::OutputDownView() {
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 40; j++)
      if (DownCube.BackGround[i][j]) {
        p.PrintXY("1", TerminalControl::ColorType::RED,
                  TerminalControl::ColorLocate::BACK, j + 60, i + 2);
      } else {
        p.PrintXY("0", TerminalControl::ColorType::RED,
                  TerminalControl::ColorLocate::BACK, j + 60, i + 2);
      }
}
Cube GameView::CreatRandomCube() {
  srand(time(NULL));
  return Cube(Cube::CubeType(random() % 6), random() % 4, 26, 10);
}

void GameView::UpdateDown(Cube &cube) {
  //  DownView.InserArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
  //                   UpCube.Display);

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (cube.Display[j][i]) {
        DownCube.BackGround[cube.locate_y + j][cube.locate_x + 2 * i] = true;
        DownCube.BackGround[cube.locate_y + j][cube.locate_x + 2 * i + 1] =
            true;
      }
    }
  DownView.ClearArea(DownCube.BackGround);

  // todo 判断是否消除
  int arr[30] = {0};
  for (int j = 0; j < 30; j++) {
    for (int i = 13; i < 40; i++) {
      if (!DownCube.BackGround[j][i]) {
        arr[j] = 1;
        break;
      }
    }
  }
  int nextline = 29;
  for (int ll = 29; ll >= 0; ll--) {
    if (arr[ll]) {
      for (int i = 12; i < 40; i++) {
        DownCube.BackGround[nextline][i] = DownCube.BackGround[ll][i];
      }
      nextline--;
    }
  }
  for (; nextline >= 0; nextline--)
    for (int i = 12; i < 40; i++) DownCube.BackGround[nextline][i] = 0;
  // DownView.ClearArea(DownCube.BackGround);
  DownView.DrawArea(DownCube.BackGround);
  // DownView.DrawArea(DownCube.BackGround);

  // todo 判断是否结束游戏
}
bool GameView::Act(char ch) {
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
        UpdateDown(UpCube);
        OutputDownView();
        UpCube = CreatRandomCube();
      }
      break;
    }

    case 'a': {
      Cube NextCube_left = Cube(UpCube.type_, UpCube.CubeMode_,
                                UpCube.locate_x - 2, UpCube.locate_y);
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
                                 UpCube.locate_x + 2, UpCube.locate_y);
      if (!IsCollission(NextCube_right)) {
        UpView.ClearArea(UpCube.locate_x, UpCube.locate_y, 5, 5,
                         UpCube.Display);
        UpView.InserArea(NextCube_right.locate_x, NextCube_right.locate_y, 5, 5,
                         NextCube_right.Display);
        UpCube = NextCube_right;
      }
      break;
    }
    case 'q': {
      return false;
    }
    default:
      break;
  }
  return true;
}
void GameView::show() {
  Startview.show();
  UpView.show();
  DownView.show();
  fflush(NULL);
}