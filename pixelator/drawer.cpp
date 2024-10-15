#include "drawer.h"
#include <algorithm>
#include "image.h"
namespace pixelator {
void Drawer::Set(Image image) {
  int set_rows = std::min(image.rows(), rows_);
  int set_cols = std::min(image.cols(), cols_);
  for (int i = 0; i < set_rows; ++i) {
    for (int j = 0; j < set_cols; ++j) {
      screen_.PixelAt((j - 1) * 2, i).background_color = image.at(i, j);
      screen_.PixelAt((j - 1) * 2 + 1, i).background_color = image.at(i, j);
    }
  }
}
}  // namespace pixelator
