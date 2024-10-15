#include "drawer.h"
#include "pixelator_image.h"
#include "stb_image_data_view.h"

#include <cstddef>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
namespace {
using pixelator::Drawer;
using pixelator::pixelate;
using pixelator::StbImageDataView;
}  // namespace

int main(int argc, char **argv) {
  if (argc < 2) { std::cerr << "No image provided." << std::endl; }

  fs::path image_path{argv[1]};
  if (!fs::exists(image_path)) {
    std::cerr << "No image file" << std::endl;
    std::exit(1);
  }
  const StbImageDataView image{image_path};
  if (image.empty()) {
    std::cerr << "Image could not be loaded" << std::endl;
    exit(1);
  }
  Drawer drawer{ftxui::Dimension::Full()};

  drawer.Set(pixelate(image, drawer.size()));
  drawer.Draw();
  return 0;
}
