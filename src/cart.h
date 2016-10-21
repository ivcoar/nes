#pragma once

#include "types.h"

namespace Loader
{
  class Header;
}

class Mapper;

class Cart
{
 public:
  Cart(Loader::Header* header, ubyte* data);

  Mapper* mapper;
  Loader::Header* header;
  ubyte romBanks;
  ubyte vromBanks;
  ubyte ramBanks;
  ubyte rom[];
  ubyte vrom[];
  ubyte ram[];
};
