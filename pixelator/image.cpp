#include "image.h"
#include "ftxui/screen/screen.hpp"

namespace pixelator {
using namespace ftxui;
Image::Image()
    : is_empty_(true),
      screen_{Screen::Create(Dimension::Fixed(0), Dimension::Fixed(0))} {}
Image::Image(int rows, int cols)
    : is_empty_(false),
      screen_{Screen::Create(Dimension::Fixed(rows), Dimension::Fixed(cols))} {
  rows_ = rows;
  cols_ = cols;
}
ftxui::Color& Image::at(int rows, int cols) {
  return screen_.PixelAt(rows, cols).background_color;
}

Image::Image(const Image& other) noexcept : screen_{other.screen_} {
  rows_ = other.rows_;
  cols_ = other.cols_;
  is_empty_ = other.is_empty_;
}

Image::Image(Image&& other) noexcept : screen_{std::move(other.screen_)} {
  rows_ = other.rows_;
  cols_ = other.cols_;
  is_empty_ = other.is_empty_;
}

Image& Image::operator=(const Image& other) noexcept {
  if (&other == this) { return *this; }
  rows_ = other.rows_;
  cols_ = other.cols_;
  is_empty_ = other.is_empty_;
  screen_ = other.screen_;
  return *this;
}

Image& Image::operator=(Image&& other) noexcept {
  if (&other == this) { return *this; }
  rows_ = other.rows_;
  cols_ = other.cols_;
  is_empty_ = other.is_empty_;
  screen_ = std::move(other.screen_);
  return *this;
}

}  // namespace pixelator
