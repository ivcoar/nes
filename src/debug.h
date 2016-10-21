#pragma once

//#include "types.h"
#include "loader.h"

namespace Debug
{

  void log(const char* msg);
  void log(const Loader::Header* header);
  
}
