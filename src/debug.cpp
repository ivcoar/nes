#include "debug.h"

#include <iostream>

void Debug::log(const char* msg)
{
  std::cout << msg << std::endl;
}

void Debug::log(const Loader::Header* header)
{

  Debug::log("iNES Header");
  std::cout << "PRG banks: " << header->romBanks << std::endl;
  std::cout << "CHR banks: " << header->vromBanks << std::endl;
  std::cout << "RAM banks: " << header->ramBanks << std::endl;
  std::cout << "Region: " << header->region << std::endl;
  
}
