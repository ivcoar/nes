#include "loader.h"

#include <iostream>
#include <fstream>

#include "cart.h"

using namespace std;

Cart* Loader::loadRom(const char* name)
{
  return Loader::loadRom(name, new Header());
}

Cart* Loader::loadRom(const char *name, Header* header)
{

  ifstream romfile(name, ios::binary);
  romfile.seekg(0, ios::end);
  auto romsize = romfile.tellg();
  romfile.seekg(0, ios::beg);

  romfile.read((char*) header->raw, 16);
  /*
  for (int i = 0; i < 16; i++) {
    header->raw[i] = data[i];
  }
  */

  auto data = new ubyte[header->romBanks * 0x4000 + header->vromBanks * 0x2000];
  romfile.seekg(16);
  romfile.read((char*) data, (int)romsize - 16);

  romfile.close();
  
  if (!(header->b0 == 'N' && header->b1 == 'E' && header->b2 == 'S'))
    return nullptr;

  ubyte mapper = header->mapperHigh << 4 | header->mapperLow;
  
  cout << name << endl;
  cout << "--- HEADER ---" << endl;
  cout << "0-3 " << header->b0 << header->b1 << header->b2 << header->b3 << endl;
  cout << "ROM Banks: " << (int) header->romBanks << endl;
  cout << "VROM Banks: " << (int) header->vromBanks << endl;
  cout << "Mapper: " << (int) mapper << endl; 
  

  auto cart = new Cart(header, data);
  
  return cart;
  
}
