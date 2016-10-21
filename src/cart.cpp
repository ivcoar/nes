#include "cart.h"

#include "loader.h"
#include "mapper.h"

#include <iostream>

Cart::Cart(Loader::Header* h, ubyte* data)
{
  
  header = h;

  ubyte mapperid = header->mapperHigh << 4 | header->mapperLow;
  switch (mapperid) {
  case 0:
    mapper = new Mapper2(this);
    break;
  case 2:
    mapper = new Mapper2(this);
    break;
  default:
    std::cerr << "Mapper not implemented: " << (int) mapperid << std::endl;
  }
  
  romBanks = header->romBanks;
  vromBanks = header->vromBanks;
  ramBanks = header->ramBanks;

}
