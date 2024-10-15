#pragma once
#include <filesystem>
#include "ftxui/screen/color.hpp"
#include "pixelator.h"
#include "stb/stb_image.h"

namespace pixelator {
class StbImageDataView {
 public:
  explicit StbImageDataView(const std::filesystem::path& image_path);
  explicit StbImageDataView();

  // Copy construct is forbiddened.
  StbImageDataView(const StbImageDataView&) = delete;
  StbImageDataView& operator=(const StbImageDataView&) = delete;

  // Move construct
  StbImageDataView(StbImageDataView&& object);
  StbImageDataView& operator=(StbImageDataView&& object) {
    if (&object == this) { return *this; }
    rows_ = object.rows_;
    cols_ = object.cols_;
    channels_ = object.channels_;
    is_empty_ = object.is_empty_;
    data_ = std::move(object.data_);
    return *this;
  };

  int rows() const { return rows_; }
  int cols() const { return cols_; }
  int channels() const { return channels_; }
  int GetIndex(int query_row, int query_col) const {
    return channels_ * (query_row * cols_ + query_col);
  }
  Color at(int row, int col) const {
    int index = GetIndex(row, col);
#ifdef DEBUG
    Log("Pixel at (%d, %d): %d %d %d\n",
        row,
        col,
        data_[index],
        data_[index + 1],
        data_[index + 2]);
#endif
    return Color{data_[index], data_[index + 1], data_[index + 2]};
  };

  bool empty() const { return is_empty_; }

  ~StbImageDataView();

 private:
  struct Size {
    int width;
    int height;
  } size_;
  int rows_;
  int cols_;
  int channels_;
  stbi_uc* data_;

  bool is_empty_;
  std::filesystem::path image_path_;
};
}  // namespace pixelator
