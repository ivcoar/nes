#include "mapper.h"

#include "cart.h"

#include <iostream>
#include <iomanip>

Mapper::Mapper(Cart* c)
{
  cart = c; 
}

ubyte Mapper2::read(ushort address)
{

  if (address >= 0x8000) {
    return cart->rom[(int)address - 0x8000];
  } else if (address >= 0x6000) {
    return cart->ram[address - 0x6000];
  } else {
    std::cerr << "Unhandled cart read address: " << std::setfill('0') << std::setw(4) << std::hex <<
      address << std::endl;
    return 0;
  }

}

void Mapper2::write(ushort address, ubyte val)
{

  if (address >= 0x8000) {
    cart->rom[address - 0x8000] = val;
  } else if (address >= 0x6000) {
    cart->ram[address - 0x6000] = val;
  } else {
    std::cerr << "Unhandled cart write address: " << std::setfill('0') << std::setw(4) << std::hex <<
      address << std::endl;
  }
  
}

