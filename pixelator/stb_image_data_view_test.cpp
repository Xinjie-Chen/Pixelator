#include "stb_image_data_view.h"
#include <gtest/gtest.h>
#include <filesystem>

namespace fs = std::filesystem;
TEST(TestTopic, basicTest) {
  auto path = fs::canonical(
      "/Users/chenxinjie/src_code/cpp/lectures-and-homeworks/homeworks/"
      "homework_5/pixelator/pixelator/test_data/grumpy.png");
  pixelator::StbImageDataView test_image{path};
  EXPECT_EQ(test_image.rows(), 6);
  EXPECT_EQ(test_image.cols(), 4);
}
