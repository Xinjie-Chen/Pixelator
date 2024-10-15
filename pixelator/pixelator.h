#pragma once
#include <cstdio>
namespace pixelator {
#define Log(format, ...) printf(format, __VA_ARGS__);
struct Size {
  int rows;
  int cols;
};
struct Color {
  int r;
  int g;
  int b;
};
}  // namespace pixelator
