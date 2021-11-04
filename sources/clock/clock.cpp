#include "clock/clock.h"

const std::size_t ygl::clock::SECOND  = 1000;
const std::size_t ygl::clock::HERTZ	  = 65;
const std::size_t ygl::clock::FPS	  = 30;
const std::size_t ygl::clock::LATENCY = ygl::clock::SECOND / ygl::clock::HERTZ;
