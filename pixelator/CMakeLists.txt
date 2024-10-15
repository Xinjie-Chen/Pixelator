# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image
add_library(stb_image_data_view stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC
cxx_setup stb::stb ftxui::screen ftxui::dom ftxui::component)

add_library(image image.cpp)
target_link_libraries(image PUBLIC
cxx_setup stb::stb ftxui::screen ftxui::dom ftxui::component)

add_library(pixelate_image pixelator_image.cpp)
target_link_libraries(pixelate_image PUBLIC
cxx_setup stb::stb ftxui::screen ftxui::dom ftxui::component stb_image_data_view image)

add_library(drawer drawer.cpp)
target_link_libraries(drawer PUBLIC
cxx_setup stb::stb ftxui::screen ftxui::dom ftxui::component stb_image_data_view image)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE cxx_setup stb_image_data_view image pixelate_image drawer)

if(BUILD_TESTING)
  add_executable(data_view_test stb_image_data_view_test.cpp)
  target_link_libraries(data_view_test PRIVATE cxx_setup GTest::gtest_main stb_image_data_view)

  add_executable(image_test image_test.cpp)
  target_link_libraries(image_test PRIVATE cxx_setup GTest::gtest_main image)

  add_executable(pixelate_image_test pixelator_image_test.cpp)
  target_link_libraries(pixelate_image_test PRIVATE cxx_setup GTest::gtest_main pixelate_image)

  include(GoogleTest)
  gtest_discover_tests(data_view_test image_test)
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
endif()
