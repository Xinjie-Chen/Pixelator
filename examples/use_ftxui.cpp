#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

namespace {
const ftxui::Color kYellowishColor = ftxui::Color::RGB(255, 100, 0);
}

int main() {
  const ftxui::Dimensions dimensions{ftxui::Dimension::Full()};
  ftxui::Screen screen{ftxui::Screen::Create(dimensions)};
  // auto &pixel_left = screen.PixelAt(10, 10);
  // pixel_left.background_color = kYellowishColor;
  // pixel_left.character = ' ';
  // auto &pixel_right = screen.PixelAt(11, 10);
  // pixel_right.background_color = kYellowishColor;
  // pixel_right.character = ' ';
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 10; ++j) {
      auto &pixel = screen.PixelAt(j, i);
      pixel.background_color = kYellowishColor;
      pixel.character = ' ';
    }
  }
  // screen.Print();
  // using namespace ftxui;
  // Element document = hbox({
  //     text("left") | border,
  //     text("middle") | border | flex,
  //     text("right") | border,
  // });
  //
  // auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  // Render(screen, document);
  screen.Print();

  return 0;
}
