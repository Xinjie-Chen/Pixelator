#pragma once
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include "pixelator.h"

namespace pixelator {
class Image {
 public:
  explicit Image();
  explicit Image(int rows, int cols);

  int rows() const { return rows_; }
  int cols() const { return cols_; }
  pixelator::Size size() const { return Size{rows_, cols_}; }
  bool is_empty() const { return is_empty_; }
  ftxui::Color& at(int rows, int cols);

  Image& operator=(const Image&) noexcept;
  Image(const Image&) noexcept;

  Image& operator=(Image&&) noexcept;
  Image(Image&&) noexcept;

  bool operator==(const ftxui::Color&) const;

 private:
  int rows_;
  int cols_;
  bool is_empty_;
  ftxui::Screen screen_;
};
}  // namespace pixelator
