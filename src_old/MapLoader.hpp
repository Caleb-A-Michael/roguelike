#pragma once

#include "Map.hpp"
#include <string>

namespace MapLoader {
    Map load(const std::string& path);
}