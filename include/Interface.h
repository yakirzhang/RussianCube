#pragma once
#include <Printer.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Interface {
 public:
  Interface() { Printer drawer_(); }
  void InsertVline(int x_, int y_, int length_) {
    vlines.emplace_back(x_, y_, length_);
  }
  void InsertHline(int x_, int y_, int length_) {
    hlines.emplace_back(x_, y_, length_);
  }
  void InserArea(int x_, int y_, int xsize, int ysize,
                 vector<vector<bool>> &data) {
    for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
        if (data[j][i])
          drawer_.PrintXY("  ", TerminalControl::ColorType::RED,
                          TerminalControl::ColorLocate::BACK, 2 * i + x_,
                          j + y_);
      }
    }
  }
  void DrawArea(bool map[30][40]) {
    for (int i = 13; i < 40; i++)
      for (int j = 0; j < 24; j++) {
        if (map[j][i]) {
          drawer_.PrintXY(" ", TerminalControl::ColorType::CYAN,
                          TerminalControl::ColorLocate::BACK, i, j);
        }
      }
  }
  void ClearArea(bool map[30][40]) {
    for (int i = 12; i < 40; i++)
      for (int j = 6; j < 30; j++) {
        drawer_.PrintXY(" ", TerminalControl::ColorType::BLACK,
                        TerminalControl::ColorLocate::BACK, i, j);
      }
  }
  void DrawArea(int x_, int y_, bool map[30][40]) {}
  void ClearArea(int x_, int y_, int xsize, int ysize,
                 vector<vector<bool>> &data) {
    for (int i = 0; i < xsize; i++)
      for (int j = 0; j < ysize; j++) {
        if (data[j][i])
          drawer_.PrintXY("  ", TerminalControl::ColorType::BLACK,
                          TerminalControl::ColorLocate::BACK, 2 * i + x_,
                          j + y_);
      }
  }
  void InserPoint(int x_, int y_) { points.emplace_back(x_, y_); }
  void InsertLable(int x_, int y_, string s) { lables.emplace_back(x_, y_, s); }
  void show() {
    for (auto line : vlines) {
      for (auto point : line.points)
        drawer_.PrintXY("  ", TerminalControl::ColorType::CYAN,
                        TerminalControl::ColorLocate::BACK, point.x, point.y);
    }
    for (auto line : hlines) {
      for (auto point : line.points)
        drawer_.PrintXY("  ", TerminalControl::ColorType::CYAN,
                        TerminalControl::ColorLocate::BACK, point.x, point.y);
    }
    for (auto point : points)
      drawer_.PrintXY("  ", TerminalControl::ColorType::CYAN,
                      TerminalControl::ColorLocate::BACK, point.x, point.y);
    for (auto lable : lables)
      drawer_.PrintXY(lable.s.c_str(), TerminalControl::ColorType::BLACK,
                      TerminalControl::ColorLocate::BACK, lable.x, lable.y);
  }
  class Lable {
   public:
    Lable(int x_, int y_, string s_) : x(x_), y(y_), s(s_){};
    int x, y;
    string s;
  };
  class Point {
   public:
    Point(int x_, int y_) : x(x_), y(y_){};
    Point(const Point &other) {
      this->x = other.x;
      this->y = other.y;
    };
    int x, y;
  };
  class Vline {
   public:
    Vline(Point StartPoint_, int length_) {
      for (int i = StartPoint_.y; i <= StartPoint_.y + length_; i++) {
        points.emplace_back(StartPoint_.x, i);
      }
    }
    Vline(int x_, int y_, int length_) : Vline(Point(x_, y_), length_){};

    vector<Point> points;
  };
  class Hline {
   public:
    Hline(Point StartPoint_, int length_) {
      for (int i = StartPoint_.x; i <= StartPoint_.x + length_; i++) {
        points.emplace_back(i, StartPoint_.y);
      }
    }
    Hline(int x_, int y_, int length_) : Hline(Point(x_, y_), length_){};

    vector<Point> points;
  };

 private:
  vector<Vline> vlines;
  vector<Hline> hlines;
  vector<Point> points;
  vector<Lable> lables;
  Printer drawer_;
  int s_x = 9 + 2 + 28 + 2 + 4, s_y = 4 + 1 + 8 + 1 + 5;  //打印分数的位置
  int l_x = 9 + 2 + 28 + 2 + 4, l_y = 4 + 1 + 8 + 1 + 10;  //打印关卡级别的位置
};