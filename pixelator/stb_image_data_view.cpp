#include "stb_image_data_view.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

namespace {
constexpr int kLoadAllChannels{0};
}

namespace pixelator {
StbImageDataView::StbImageDataView(const std::filesystem::path& image_path)
    : image_path_{image_path}, is_empty_{false} {
  data_ = stbi_load(
      image_path_.c_str(), &cols_, &rows_, &channels_, kLoadAllChannels);
#ifdef DEBUG
  Log("Load from path %s\n", image_path_.c_str());
  for (int i = 100; i < 200; ++i) {
    for (int j = 50; j < cols_; ++j) {
      Log("Pixel at (%d, %d): %d %d %d\n",
          i,
          j,
          data_[channels_ * (i * cols_ + j)],
          data_[channels_ * (i * cols_ + j) + 1],
          data_[channels_ * (i * cols_ + j) + 2])
    }
  }
#endif  // DEBUG
}
StbImageDataView::StbImageDataView(StbImageDataView&& object) {
  cols_ = object.cols_;
  rows_ = object.rows_;
  channels_ = object.channels_;
  is_empty_ = object.is_empty_;
  data_ = std::move(object.data_);
}
StbImageDataView::~StbImageDataView() { stbi_image_free(data_); }

}  // namespace pixelator
