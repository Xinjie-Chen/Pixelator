#pragma once
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"
#include "image.h"
#include "pixelator.h"

namespace pixelator {
class Drawer {
 public:
  Drawer(ftxui::Dimensions dimension)
      : screen_(ftxui::Screen::Create({dimension.dimx, dimension.dimy})) {
    rows_ = dimension.dimy;
    cols_ = dimension.dimx;
#ifdef DEBUG
    Log("Drawer initial\n"
        "Drawer: %d %d\n",
        rows_,
        cols_);
#endif
  }
  int rows() const { return rows_; }
  int cols() const { return cols_; }
  Size size() const { return Size{rows_, cols_}; }

  void Set(Image);
  void Draw() const { screen_.Print(); }
  std::string ToString() const { return screen_.ToString(); }

 private:
  int rows_;
  int cols_;
  ftxui::Screen screen_;
};
}  // namespace pixelator
