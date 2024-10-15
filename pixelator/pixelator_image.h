#pragma once
#include "image.h"
#include "pixelator.h"
#include "stb_image_data_view.h"

namespace pixelator {
Image&& pixelate(const StbImageDataView& image, pixelator::Size size);
}  // namespace pixelator
