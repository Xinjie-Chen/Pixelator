#include "pixelator_image.h"
#include <gtest/gtest.h>
#include <filesystem>
#include "ftxui/screen/color.hpp"
#include "image.h"

TEST(TestTopic, BasicPixelator) {
  const std::filesystem::path kImagePath =
      "/Users/chenxinjie/src_code/cpp/lectures-and-homeworks/homeworks/"
      "homework_5/pixelator/pixelator/test_data/test2.png";
  pixelator::StbImageDataView image(kImagePath);
  pixelator::Image result{std::move(pixelator::pixelate(image, {100, 100}))};
  EXPECT_EQ(result.cols(), 100);
  EXPECT_TRUE(result.at(3, 2) == (ftxui::Color{1, 1, 1}));
  pixelator::Image result2{std::move(pixelator::pixelate(image, {300, 300}))};
  EXPECT_EQ(result2.cols(), 300);
  pixelator::Image result3{std::move(pixelator::pixelate(image, {1000, 1000}))};
  EXPECT_EQ(result3.cols(), image.cols());
  EXPECT_EQ(result3.rows(), image.rows());
}
