#include "pixelator_image.h"
#include "image.h"
#include "pixelator.h"
#include "stb_image_data_view.h"

namespace pixelator {
static int Scale(int number, float factor) {
  return static_cast<int>(number * factor);
}
static bool IsSame(Size target, Size origin) {
  if (target.rows > origin.rows || target.cols > origin.cols) {
    return true;
  } else {
    return false;
  }
}
static double GetFactor(Size target, Size origin) {
  return std::min(static_cast<double>(target.rows) / origin.rows,
                  static_cast<double>(target.cols) / origin.cols);
}
static Size FactoredSize(Size origin, double factor) {
  return {Scale(origin.rows, factor), Scale(origin.cols, factor)};
}
static Image&& GenerateImage(const StbImageDataView& image, Size target) {
  Image* result = new Image{target.rows, target.cols};
  const int region_width = image.rows() / target.rows;
  const int region_height = image.cols() / target.cols;

  auto GetNewPixel = [&](int i, int j) {
    int sum_r{};
    int sum_g{};
    int sum_b{};
    int i_begin = i * region_height;
    int i_end = std::min((i + 1) * region_height, image.rows());
    int j_begin = j * region_width;
    int j_end = std::min((j + 1) * region_width, image.cols());
    int region_size = (i_end - i_begin) * (j_end - j_begin);

    for (int i = i_begin; i < i_end; i++) {
      for (int j = j_begin; j < j_end; j++) {
        sum_r += image.at(i, j).r;
        sum_g += image.at(i, j).g;
        sum_b += image.at(i, j).b;
      }
    }

    return ftxui::Color{ftxui::Color::RGB(
        sum_r / region_size, sum_g / region_size, sum_b / region_size)};
  };

  for (int i = 0; i < target.rows - 1; i++) {
    for (int j = 0; j < target.cols - 1; j++) {
      result->at(i, j) = GetNewPixel(i, j);
    }
  }
  return std::move(*result);
}

static Image&& GenerateOrigin(const StbImageDataView& image) {
  Image* result = new Image{image.rows(), image.cols()};
  for (int i = 0; i < image.rows(); i++) {
    for (int j = 0; j < image.cols(); j++) {
      result->at(i, j) = ftxui::Color{ftxui::Color::RGB(
          image.at(i, j).r, image.at(i, j).g, image.at(i, j).b)};
#ifdef DEBUG
      Log("origin_pixel at (%d, %d), RGB(%d, %d, %d)\n",
          i,
          j,
          image.at(i, j).r,
          image.at(i, j).g,
          image.at(i, j).b);
#endif
    }
  }
  return std::move(*result);
}
Image&& pixelate(const StbImageDataView& image, pixelator::Size size) {
  Size origin = {image.rows(), image.cols()};
  Size target = size;
#ifdef DEBUG
  Log("origin size (%d, %d)\n", origin.rows, origin.cols);
  Log("target size (%d, %d)\n", target.rows, target.cols);
#endif
  double factor = 1.0;
  if (IsSame(target, origin)) {
    return GenerateOrigin(image);
  } else {
    factor = GetFactor(target, origin);
    target = FactoredSize(origin, factor);
  }
#ifdef DEBUG
  Log("Log from pixelate\n"
      "target size (%d, %d)\n",
      target.rows,
      target.cols);
#endif
  return GenerateImage(image, target);
}
}  // namespace pixelator
