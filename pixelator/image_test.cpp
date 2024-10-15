#include "image.h"
#include <gtest/gtest.h>
#include <ftxui/screen/color.hpp>

namespace {
const ftxui::Color kYellowish = ftxui::Color::RGB(255, 200, 100);
}

TEST(TestTopic, BasicImageTest) {
  pixelator::Image test_image(100, 100);
  test_image.at(10, 10) = kYellowish;
  EXPECT_TRUE(test_image.at(10, 10) == kYellowish);
  EXPECT_TRUE(test_image.at(11, 12) == ftxui::Color{});
}
