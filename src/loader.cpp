#include "loader.h"

#include <iostream>
#include <fstream>
//#include <bitfield>

using namespace std;

bool Loader::loadRom(const char* name)
{
  return Loader::loadRom(name, new Header());
}

bool Loader::loadRom(const char *name, Header* header)
{

  ifstream romfile(name, ios::binary);
  romfile.seekg(0, ios::end);
  auto romsize = romfile.tellg();
  romfile.seekg(0, ios::beg);

  ubyte* data = new ubyte[romsize];
  romfile.read((char*) data, romsize);
  
  for (int i = 0; i < 16; i++) {
    header->raw[i] = data[i];
  }

  if (!(header->b0 == 'N' && header->b1 == 'E' && header->b2 == 'S'))
    return false;

  int mapper = (header->mapperHigh << 4) | header->mapperLow;
  
  cout << name << endl;
  cout << "--- HEADER ---" << endl;
  cout << "0-3 " << header->b0 << header->b1 << header->b2 << header->b3 << endl;
  cout << "ROM Banks: " << (int) header->romBanks << endl;
  cout << "VROM Banks: " << (int) header->vromBanks << endl;
  cout << "Mapper: " << mapper << endl; 

  return true;
  
}
