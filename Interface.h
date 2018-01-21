#pragma once
#include <Printer.h>
#include <vector>
using namespace std;
class Interface {
public:
  Interface() { drawer_ = Printer(); }
  void InsertVline(int x_, int y_, int length_) {
    vlines.emplace_back(x_, y_, length_);
  }
  void InsertHline(int x_, int y_, int length_) {
    hlines.emplace_back(x_, y_, length_);
  }
  void InserPoint(int x_, int y_) { points.emplace_back(x_, y_); }
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
  }
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
    Vline(Point StartPoint_, int length_) {
      for (int i = StartPoint_.x; i <= StartPoint_.x + length_; i++) {
        points.emplace_back(i, StartPoint_.y);
      }
    }
    Vline(int x_, int y_, int length_) : Vline(Point(x_, y_), length_){};

  public:
    vector<Point> points;
  };
  class Hline {
    Hline(Point StartPoint_, int length_) {
      for (int i = StartPoint_.y; i <= StartPoint_.y + length_; i++) {
        points.emplace_back(StartPoint_.x, i);
      }
    }
    Hline(int x_, int y_, int length_) : Hline(Point(x_, y_), length_){};

  public:
    vector<Point> points;
  };

private:
  vector<Vline> vlines;
  vector<Hline> hlines;
  vector<Point> points;
  Printer drawer_;
};